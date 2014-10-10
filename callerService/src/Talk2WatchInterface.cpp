/*
 * Talk2WatchInterface.cpp
 *
 *  Created on: 09.01.2014
 *      Author: benjaminsliwa
 */

#include "Talk2WatchInterface.h"
#include <bb/system/InvokeQueryTargetsRequest>
#include <bb/system/InvokeQueryTargetsReply>
#include <bb/system/InvokeReply>
#include <QSettings>
#include "UdpModule.h"

/*	GENERAL INFORMATION
 *
 *
 *
 */

Talk2WatchInterface::Talk2WatchInterface(QObject *_parent)
{

	m_udp = new UdpModule(this);
	m_udp->listenOnPort(8484);
	connect(m_udp, SIGNAL(reveivedData(QString)), this, SLOT(onDataReived(QString)));


	m_talk2WatchAvailable = false;
	m_talk2WatchProAvailable = false;
	m_talk2WatchProServiceAvailable = false;

	m_invokeManager = new bb::system::InvokeManager(this);

	m_appName = "";
	m_appKey = "";
	m_description = "";
	m_protocol = "";
	m_port = "";
	m_target = "";
	m_mimeType = "";


	bb::system::InvokeQueryTargetsRequest request;
	request.setMimeType ("text/plain");
	request.setAction("bb.action.SHARE");
	const bb::system::InvokeQueryTargetsReply *reply = m_invokeManager->queryTargets(request);


	bool ok = connect(reply, SIGNAL(finished()), this, SLOT(onTalk2WatchLookup()));
	Q_ASSERT(ok);
	Q_UNUSED(ok);
}

Talk2WatchInterface::~Talk2WatchInterface()
{

}

/************************************************************
 * 						HELPER METHODS						*
 ***********************************************************/

bool Talk2WatchInterface::isTalk2WatchInstalled()
{
	return m_talk2WatchAvailable;
}

bool Talk2WatchInterface::isTalk2WatchProInstalled()
{
	return m_talk2WatchProAvailable;
}

bool Talk2WatchInterface::isTalk2WatchProServiceInstalled()
{
	return m_talk2WatchProServiceAvailable;
}

/************************************************************
 * 		SENDING MESSAGES TO THE WATCH VIA TALK2WATCH		*
 ***********************************************************/

void Talk2WatchInterface::sendSms(QString _sender, QString _text)
{
	sendCommand("SMS$$" + _sender + "$$" + _text);
}

void Talk2WatchInterface::sendEmail(QString _sender, QString _subject, QString _text)
{
	sendCommand("EMAIL$$" + _sender + "$$" + _subject + "$$" + _text);
}

/************************************************************
 * 		RECEIVING ACTIONS FROM THE WATCH VIA TALK2WATCH		*
 ***********************************************************/

/*	RECEIVING MESSAGES - STEP 1
 *
 *	Chose one of the available receiver models, implement it and call the activation method with the correct parameters
 */

void Talk2WatchInterface::setAppValues(QString _appName, QString _appVersion, QString _appKey, QString _protocol, QString _port, QString _description)
{
	m_appName = _appName;
	m_appVersion = _appVersion;
	m_appKey = _appKey;
	m_protocol = _protocol;
	m_port = _port;
	m_description = _description;
}


/*	RECEIVING MESSAGES - STEP 2
 *
 *	Call the authorization method and wait for a reply. The reply will be passed to the receiver which was defined in STEP 1.
 *	If the request was successful the value APP_RQ_SUCCESS will be returned
 */

void Talk2WatchInterface::sendAppAuthorizationRequest()
{
	QString command = "APP_AUTH_RQ$$";
	if(m_protocol=="TCP")
		command += m_appName + "$$" + m_appVersion + "$$" + m_appKey + "$$" + "TCP$$" + m_port + "$$" + m_description;
	else if(m_protocol=="UDP")
		command += m_appName + "$$" + m_appVersion + "$$" + m_appKey + "$$" + "UDP$$" + m_port + "$$" + m_description;

	sendCommand(command);
}

/*	RECEIVING MESSAGES - STEP 3
 *
 *	Use the creator methods to create the actions you want to add to Talk2Watch.
 */

void Talk2WatchInterface::createAction(QString _title, QString _command, QString _description)
{
	QString command = "APP_CREATE_ACTION$$" + _title + "$$" + m_appKey + "$$" + m_appName + "$$" + _command + "$$" + _description;
	sendCommand(command);
}

void Talk2WatchInterface::forwardSourceCode()
{
	bb::system::InvokeRequest request;
	request.setTarget("sys.pim.uib.email.hybridcomposer");
	request.setAction("bb.action.SHARE");
	request.setUri("file:///" + QDir::currentPath() + "/app/native/assets/T2W_API.zip");
	m_invokeManager->invoke(request);
}


/************************************************************
 * 						PRIVATE METHODS						*
 ***********************************************************/

// Transmission
void Talk2WatchInterface::sendCommand(QString _command)
{
    m_udp->sendMessage("127.0.0.1", 8989, _command); // T2W free
    m_udp->sendMessage("127.0.0.1", 9877, _command); // T2W Pro
}

void Talk2WatchInterface::sendCommandViaInvocation(QString _command, QString _target)
{
    bb::system::InvokeRequest request;
    request.setTarget(_target.toStdString().c_str());
    request.setAction("bb.action.SHARE");
    request.setData(_command.toStdString().c_str());
    request.setMimeType("text/plain");

    m_invokeManager->invoke(request);
}



/************************************************************
 * 						   	 SLOTS   						*
 ***********************************************************/

void Talk2WatchInterface::onDataReived(const QString &_data)
{
	qDebug() << "onDataReceived";
	emit receivedData(_data);
}


void Talk2WatchInterface::onTalk2WatchLookup()
{
	qDebug() << "onTalk2WatchProAvailableResponse()";
	m_talk2WatchProAvailable = true;
    bb::system::InvokeQueryTargetsReply *reply = qobject_cast<bb::system::InvokeQueryTargetsReply*>(sender());
    if (reply && reply->error() == bb::system::InvokeReplyError::None)
    {
    	QList<bb::system::InvokeAction> actions = reply->actions();

    	for(int i=0; i<actions.size(); i++)
    	{
    		QList<bb::system::InvokeTarget> targets = actions.at(i).targets();
    		for(int j=0; j<targets.size(); j++)
    		{
    			qDebug() << targets.at(j).name();
    			if(targets.at(j).name()=="com.Talk2WatchProService")
    			{
    				m_talk2WatchProServiceAvailable = true;
    				qDebug() << "Talk2WatchProService found";
    			}
    			if(targets.at(j).name()=="com.Talk2WatchPro")
    			{
    				m_talk2WatchProAvailable = true;
    				qDebug() << "Talk2WatchPro found";
    			}
    			if(targets.at(j).name()=="com.Talk2Watch.invocation.msg")
    			{
    				m_talk2WatchAvailable = true;
    				qDebug() << "Talk2Watch found";
    			}
    		}
    	}

		emit transmissionReady();

    	reply->deleteLater();
    } else if (reply && reply->error() != bb::system::InvokeReplyError::None){
    	qDebug() << "ERROR: " << reply->error();
    	reply->deleteLater();
    } else {
    	qDebug() << "reply not found";
    }


}
