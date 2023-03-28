#include <QCoreApplication>
#include <QNetworkInterface>
#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>
#include <QDebug>

class Server : public QObject
{
        Q_OBJECT

public:
        Server (QObject *parent = 0);
        ~Server();
        QTcpSocket *socket ;

public slots:
        void myConnection();

private:
        qint64 bytesAvailable() const;
        QTcpServer *server;

signals:

};

