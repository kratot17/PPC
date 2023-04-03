#include "server.h"

Server::Server (QObject *parent) : QObject(parent)
{
    server = new QTcpServer (this);

    // optevrene porty - nmap, netstat

    // propojeni signalu newConnection se slotem, ktery zpracuje prichozi spojeni
    connect (server, SIGNAL(newConnection()), this, SLOT(myConnection()));

    // cekame na spojeni z libovolne IP adresy na portu 1234
    if (!server->listen (QHostAddress::Any, 1234))
        qDebug() << "nepodarilo se zahajit poslouchani na port 1234";
}

Server::~Server()
{
    socket->close();
}

void Server::myConnection()
{
    socket = server->nextPendingConnection();

    while(!(socket->waitForReadyRead(100)));

    QByteArray data = socket->readAll();

    qDebug() << data;

    socket->write("ACK");

    connect (socket, SIGNAL(disconnected()), socket, SLOT(deleteLater()));

    socket->disconnectFromHost();
}