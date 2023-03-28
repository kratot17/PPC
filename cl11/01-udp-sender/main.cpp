#include <QCoreApplication>
#include <QUdpSocket>
	
int main(int argc, char ** argv)
{
	QCoreApplication a(argc, argv);
	//
	QHostAddress address("127.0.0.1"); // QHostAddress::LocalHost
	QByteArray datagram = "Hello from Sender";
	QUdpSocket socket;
	socket.writeDatagram(
		datagram.data(), datagram.size(), address, 1234);
	//
	return a.exec();
}