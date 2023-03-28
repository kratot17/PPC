#include <QCoreApplication>
#include <QUdpSocket>
#include <QNetworkDatagram>
#include <QDebug>
	
int main(int argc, char ** argv)
{
	QCoreApplication a(argc, argv);
	//
	QUdpSocket socket;
	if (!socket.bind(1234, QUdpSocket::ShareAddress))
	// if (!socket.bind(QHostAddress("127.0.0.1"), 1234))
	{
		qDebug() << "Chyba pri inicializaci socketu";
		return 1;
	}
	// 
	QObject::connect(&socket, QUdpSocket::readyRead, [&](){
		QByteArray datagram;
		datagram.resize(socket.pendingDatagramSize());
		QHostAddress address;
		quint16 port;
		socket.readDatagram(
			datagram.data(), datagram.size(), &address, &port);
		qDebug() << datagram.data();
	});
	
	return a.exec();
}