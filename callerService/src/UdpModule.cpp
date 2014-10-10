/*
 * UdpModule.cpp
 *
 *  Created on: 16.01.2014
 *      Author: benjaminsliwa
 */

#include "UdpModule.h"

UdpModule::UdpModule(QObject *_parent)
{
	m_server = new QUdpSocket(this);
	m_socket = new QUdpSocket(this);
}

UdpModule::~UdpModule()
{

}

void UdpModule::listenOnPort(int _port)
{
	m_server->bind(QHostAddress::Any, _port);
	bool ok = connect(m_server, SIGNAL(readyRead()), this, SLOT(onReadyRead()));

	ok==true ? qDebug() << "binding ok" : qDebug() << "binding failed";
}

void UdpModule::sendMessage(QString _address, int _port, QString _data)
{
	qDebug() << "UdpModule::sendMessage " << _data << " to" << _address << ":" << QString::number(_port);
	m_socket->writeDatagram(_data.toStdString().c_str(),QHostAddress(_address), _port);
}

void UdpModule::onReadyRead()
{
	qDebug() << "UdpServer::dataReceived";
    while (m_server->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(m_server->pendingDatagramSize());
        QHostAddress sender;
        quint16 senderPort;

        m_server->readDatagram(datagram.data(), datagram.size(),&sender, &senderPort);
        QString data = QString(datagram);

        qDebug() << data;
        emit reveivedData(data);

    }
}
