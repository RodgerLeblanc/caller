/*
 * Talk2WatchInterface.h
 *
 *  Created on: 09.01.2014
 *      Author: benjaminsliwa
 */

#ifndef TALK2WATCHINTERFACE_H_
#define TALK2WATCHINTERFACE_H_

#include <QObject>
#include <bb/system/InvokeManager>

class UdpModule;

class Talk2WatchInterface : public QObject
{
	Q_OBJECT
public:

	/************************************************************
	 * 							SETUP							*
	 ***********************************************************/

	/*	Add the following Libs to your project
	 * 	LIBS: libbbsystem
	 *
	 *	Create an a new Talk2WatchInterface object
	 */

	Talk2WatchInterface(QObject *_parent = 0);

	/*	HANDLING DIFFERENT TALK2WATCH VERSIONS
	 *
	 *	As the normal Talk2Watch version and the Pro version use different target ids the installed version has to be determined.
	 *	On object creation a lookup will be performed automatically. The transmission methods will automatically chose the right app.
	 *	If both apps are installed, the Pro version will be chosen.
	 *
	 *	Note: the initial lookup takes some time - if you call a send method directly after object creation it will probably fail
	 */

	virtual ~Talk2WatchInterface();

	/************************************************************
	 * 						HELPER METHODS						*
	 ***********************************************************/

	Q_INVOKABLE bool isTalk2WatchInstalled();

	Q_INVOKABLE bool isTalk2WatchProInstalled();

	Q_INVOKABLE bool isTalk2WatchProServiceInstalled();


	/************************************************************
	 * 		SENDING MESSAGES TO THE WATCH VIA TALK2WATCH		*
	 ***********************************************************/

	/*
	 *	Currently there are two possibilities of displaying a message on the watch - SMS or Email.
	 * 	The only difference is the number of available variables (-> different text areas on the watch).
	 *
	 * 	Sending messages does not require any setup methods
	 */

	Q_INVOKABLE void sendSms(QString _sender, QString _text);

	Q_INVOKABLE void sendEmail(QString _sender, QString _subject, QString _text);


	/************************************************************
	 * 		RECEIVING ACTIONS FROM THE WATCH VIA TALK2WATCH		*
	 ***********************************************************/

	/*	NOTE: The message receiving part is only available for Talk2Watch Pro	 */


	/*	SETUP METHODS - DESCRIPTION
	 *
	 *	Every application which wants to receives messages from Talk2Watch has to setup a receiver first.
	 *
	 *	Messages can be received via
	 *	- TCP/ UDP
	 */

	/*	RECEIVING MESSAGES - STEP 1
	 *
	 *	Chose one of the available receiver models, implement it and call the activation method with the correct parameters
	 */

	Q_INVOKABLE void setAppValues(QString _appName, QString _appVersion, QString _appKey, QString _protocol, QString _port, QString _description);


	/*	APPLICATION AUTHORIZATION
	 *
	 *	For receiving notifications about triggered actions every application has to be authorized by the user.
	 *	If the user grants the requested permissions Talk2Watch will create a new folder on the "Script" page for the application.
	 */

	/*	RECEIVING MESSAGES - STEP 2
	 *
	 *	Call the authorization method and wait for a reply. The reply will be passed to the receiver which was defined in STEP 1.
	 *	If the request was successful the value APP_RQ_SUCCESS will be returned
	 */

	Q_INVOKABLE void sendAppAuthorizationRequest();

	/*	SCRIPT CREATION
	 *
	 *	After a successful authorization the application is allowed to create new actions. Every action will be added to the new folder which
	 *	was created in STEP 2.
	 *
	 *	An action consists of three parts
	 *	1) TITLE: the title will be displayed on the watch when the ScriptMode is active
	 *	2) COMMAND:	the value which is passed back to the application receiver when a script is triggered
	 *	3) DESCRIPTION: the text which will be shown when the user selects the action from the application folder on the "Script" page
	 *
	 */

	/*	EXAMPLE
	 *
	 *	A location based applications wants to save the users position via a Talk2Watch script which is triggered from the watch
	 *
	 * 	TITLE:			Save position
	 * 	COMMAND:		SAVE_POSITION
	 *	DESCRIPTION:	Uses GPS to get the current latitude and logitude values and saves them.
	 */

	/*	RECEIVING MESSAGES - STEP 3
	 *
	 *	Use the creator methods to create the actions you want to add to Talk2Watch.
	 */

	Q_INVOKABLE void createAction(QString _title, QString _command, QString _description);



	Q_INVOKABLE void forwardSourceCode();
private:

	// UDP
	UdpModule *m_udp;


	// Transmission
	void sendCommand(QString _command);
	void sendCommandViaInvocation(QString _command, QString _target);

	QString m_appName;
	QString m_appVersion;
	QString m_appKey;
	QString m_protocol;
	QString m_port;
	QString m_description;

	QString m_target;
	QString m_mimeType;

	bb::system::InvokeManager *m_invokeManager;


	bool m_talk2WatchAvailable;
	bool m_talk2WatchProAvailable;
	bool m_talk2WatchProServiceAvailable;



signals:
	void transmissionReady();
	void receivedData(QString);


public slots:
	void onDataReived(const QString &_data);
	void onTalk2WatchLookup();



};

#endif /* TALK2WATCHINTERFACE_H_ */
