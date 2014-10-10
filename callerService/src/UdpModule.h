/*
 * UdpModule.h
 *
 *  Created on: 16.01.2014
 *      Author: benjaminsliwa
 */

#ifndef UDPMODULE_H_
#define UDPMODULE_H_

#include <QObject>
#include <QtNetwork/QUdpSocket>

class UdpModule : public QObject
{
	Q_OBJECT
public:
	UdpModule(QObject *_parent = 0);
	virtual ~UdpModule();

	// RX
	void listenOnPort(int _port);

	// TX
	Q_INVOKABLE void sendMessage(QString _address, int _port, QString _data);

private:
	QUdpSocket *m_socket;
	QUdpSocket *m_server;

signals:
	void reveivedData(QString);

public slots:
	void onReadyRead();
};

#endif /* UDPMODULE_H_ */
