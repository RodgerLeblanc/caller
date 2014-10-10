/*
 * Copyright (c) 2013-2014 BlackBerry Limited.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "service.hpp"
#include "Settings.h"
#include "Talk2WatchInterface.h"
#include "UdpModule.h"

#include <bb/Application>
#include <bb/ApplicationInfo>
#include <bb/platform/Notification>
#include <bb/platform/NotificationDefaultApplicationSettings>
#include <bb/system/InvokeManager>
#include <bb/system/phone/Call>

using namespace bb::platform;
using namespace bb::system;

Service::Service() :
        QObject(),
        m_notify(new Notification(this)),
        m_invokeManager(new InvokeManager(this)),
        settings(new Settings(this)),
        phone(new bb::system::phone::Phone(this))
{
    m_invokeManager->connect(m_invokeManager, SIGNAL(invoked(const bb::system::InvokeRequest&)),
            this, SLOT(handleInvoke(const bb::system::InvokeRequest&)));

    NotificationDefaultApplicationSettings settings;
    settings.setPreview(NotificationPriorityPolicy::Allow);
    settings.apply();

    // Connect t2w and udp objects
    t2w = new Talk2WatchInterface(this);
    connect(t2w, SIGNAL(transmissionReady()), this, SLOT(onTransmissionReady()));

    udp = new UdpModule;
    udp->listenOnPort(9821);
    connect(udp, SIGNAL(reveivedData(QString)), this, SLOT(onUdpDataReceived(QString)));

    connect(phone, SIGNAL(callUpdated(const bb::system::phone::Call)), this, SLOT(onCallUpdated(const bb::system::phone::Call)));
}

void Service::handleInvoke(const bb::system::InvokeRequest & request)
{
    if (request.action().compare("com.RogerLeblanc.callerService.SHUTDOWN") == 0) {
        bb::Application::instance()->quit();
    }
}

void Service::onCallUpdated(const bb::system::phone::Call call) {
    qDebug() << "CallerID :" << call.phoneNumber();
    qDebug() << "CallID :" << call.callId();
    qDebug() << "CallType :" << call.callType();
    if (call.callType() == bb::system::phone::CallType::Incoming && settings->value("send", false).toBool())
        t2w->sendSms("Incoming call", call.phoneNumber());
}

void Service::onTransmissionReady()
{
    authorizeAppWithT2w();
}

void Service::authorizeAppWithT2w()
{
    bb::ApplicationInfo appInfo;
    QString appName = "Caller";
    QString version = appInfo.version();
    QString UUID = "614bf149-5f54-4c51-8df0-4ec1ef94dedd";
    QString t2wAuthUdpPort = "9821";
    QString description = "CallerId";
    t2w->setAppValues(appName, version, UUID, "UDP", t2wAuthUdpPort, description);
    t2w->sendAppAuthorizationRequest();
}

void Service::onUdpDataReceived(QString _data)
{
    qDebug() << "onUdpDataReceived in..." << _data;
    if(_data=="AUTH_SUCCESS") {
        qDebug() << "Auth_Success!!!";
        return;
    }
    if (_data=="CREATE_ACTION_SUCCESS") {
        qDebug() << "Create_Action_success";
        t2w->sendSms("Script created successfully", "Your script was created successfully, you can now restart ScriptMode (choose \"[Back]\" repeatedly) to access it.");
    }
}
