#include <QCoreApplication>
#include <QNetworkInterface>
#include <QObject>
#include <QTcpSocket>
#include <QDebug>

class Client : public QObject
{
	Q_OBJECT

public:
	Client (QString message, QObject *parent = 0);
	~Client ();
	QTcpSocket *socket;

private slots:
	void readData();
};

