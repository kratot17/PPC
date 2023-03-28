#include "client.h"

Client::Client (QString message, QObject *parent) : QObject(parent)
{
    socket = new QTcpSocket (this);

    // 127.0.0.1
    socket->connectToHost ("localhost", 1234);

    socket->write(message.toLocal8Bit());
    socket->flush();

    connect (socket, SIGNAL(disconnected()), socket, SLOT(deleteLater()));
    connect (socket, SIGNAL(readyRead()), this, SLOT(readData()));
}

Client::~Client()
{
    socket->close();
}

void Client::readData()
{
    // precteme data ze serveru
    qDebug() << socket->readAll();

}