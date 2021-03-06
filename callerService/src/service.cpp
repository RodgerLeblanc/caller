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
#include "UpFront.h"

#include <bb/Application>
#include <bb/ApplicationInfo>
#include <bb/system/InvokeManager>
#include <bb/system/phone/Call>
#include <bb/pim/contacts/ContactService>
#include <bb/pim/contacts/ContactSearchFilters>
#include <bb/pim/contacts/Contact>

using namespace bb::pim::contacts;
using namespace bb::system;

Service::Service() :
        QObject(),
        m_invokeManager(new InvokeManager(this)),
        settings(new Settings(this)),
        t2w(new Talk2WatchInterface(this)),
        upFront(new UpFront(this)),
        phone(new bb::system::phone::Phone(this))
{
    m_invokeManager->connect(m_invokeManager, SIGNAL(invoked(const bb::system::InvokeRequest&)),
            this, SLOT(handleInvoke(const bb::system::InvokeRequest&)));

    connect(phone, SIGNAL(callUpdated(const bb::system::phone::Call)), this, SLOT(onCallUpdated(const bb::system::phone::Call)));

    qDebug() << "Headless started";
}

Service::~Service()
{
    qDebug() << "Headless stopped";
}

void Service::handleInvoke(const bb::system::InvokeRequest & request)
{
    if (request.action().compare("com.RogerLeblanc.callerService.SHUTDOWN") == 0) {
        bb::Application::instance()->quit();
    }
}

void Service::onCallUpdated(const bb::system::phone::Call call) {
    if (call.phoneNumber().isEmpty())
        return;

    ContactSearchFilters filters;
    filters.setSearchValue(call.phoneNumber());
    QList<Contact> contacts = ContactService().searchContacts(filters);

    QString title = contacts.isEmpty() ? "Incoming call" : "Incoming call " + contacts[0].displayName();
    if (call.callType() == bb::system::phone::CallType::Incoming && settings->value("send", false).toBool()) {
        t2w->sendSms(title, call.phoneNumber());
        QString messageToUpFront = "Incoming call:\n" + title.remove("Incoming call ") + "\n" + call.phoneNumber();
        sendToUpFront(messageToUpFront);
    }
}

void Service::sendToUpFront(QString & message) {
    // Send to UpFront, fill backgroundZ image (url), image (url), title, message, color (bb::cascades::Color)
    bb::ApplicationInfo appInfo;
    QString backgroundZ = "http://s26.postimg.org/pm0t4czqh/caller_334_396.png";
    QString backgroundQ = "http://s26.postimg.org/rrv3yv36x/caller_310_211.png";
    QString icon = "http://s26.postimg.org/ls7cv7ied/phone_38_38.png";
    QString seconds = ""; // leave blank
    QString sendToT2w = ""; // leave blank
    QString textColor = "White"; // Choose any color available in QML
    QString other = "";

    QString command = appInfo.signingHash() + "##" + appInfo.title() + "##" + backgroundZ + "##" + backgroundQ + "##" + icon + "##" + message + "##" + seconds + "##" + sendToT2w + "##" + textColor + "##" + other;
    upFront->updateUpFront(command);
    qDebug() << "sendToUpFront:" << command;
}
