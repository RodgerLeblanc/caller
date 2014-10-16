/*
 * UdpModule.h
 *
 *  Created on: 16.01.2014
 *      Author: benjaminsliwa
 */

#ifndef UPFRONT_H_
#define UPFRONT_H_

#include <QObject>
#include <QtNetwork/QUdpSocket>

class UpFront : public QObject
{
	Q_OBJECT
public:
	UpFront(QObject *_parent = 0);
	virtual ~UpFront();

	Q_INVOKABLE void updateUpFront(QString _data);

private:
	QUdpSocket *m_socket;
	QUdpSocket *m_server;
};

#endif /* UPFRONT_H_ */
