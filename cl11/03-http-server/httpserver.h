#ifndef _HTTPSERVER
#define _HTTPSERVER

#include <QCoreApplication>
#include <QNetworkInterface>
#include <iostream>
#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>
#include <QDebug>
#include <QStringList>
#include <QDateTime>

class HTTPserver : public QObject
{
	Q_OBJECT

public:
	explicit HTTPserver (QObject *parent = 0);
	~HTTPserver();
	QTcpSocket *socket ;

public slots:
	void myConnection();

private:
	qint64 bytesAvailable() const;
	QTcpServer *server;

signals:

};

#endif
