/*
 * UpFront.cpp
 *
 *
 * From the great work of (with permission) :
 *      Author: benjaminsliwa
 */

#include "UpFront.h"

UpFront::UpFront(QObject *_parent)
{
    Q_UNUSED(_parent);
	m_server = new QUdpSocket(this);
	m_socket = new QUdpSocket(this);
}

UpFront::~UpFront() {}

void UpFront::updateUpFront(QString _data)
{
	qDebug() << "UdpModule::sendMessage " << _data;
	m_socket->writeDatagram(_data.toStdString().c_str(), QHostAddress("127.0.0.1"), 8154);
}
