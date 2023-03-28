#include "httpserver.h"

using namespace std;

void delayms (int millisecondsToWait);

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	HTTPserver server;
	return a.exec();
}

HTTPserver::HTTPserver (QObject *parent) : QObject(parent)
{
	server = new QTcpServer(this);
	// cekam, nez webovy prohlize navaze signal, tim vygeneruji signal
	connect(server, SIGNAL(newConnection()),this, SLOT(myConnection()));

	if (!server->listen (QHostAddress::Any,8080))
		cerr << "\033[31mERROR:\033[0m Web server could not start\n";
	else 
		cerr << "\033[32mINFO:\033[0m Web server is waiting for a connection on port 8080\n";
}

void HTTPserver::myConnection()
{
	static qint16 count;	// pocet pripojeni, ktere budu aktualizovat v prohlizeci

	socket = server->nextPendingConnection();

	while (!(socket->waitForReadyRead(100)));	// cekam na data z prohlizece

	char webBrowserRXData[1000];
	int sv = socket->read (webBrowserRXData, 1000);

	QString response (webBrowserRXData);
	QStringList lines = response.split("\n");

	cerr << "\033[34mBROWSER:\033[0m Reading web browser data:\n";
	
	if (count == 0)
	{
		for(int i=0; i<sv; i++)
			cerr << webBrowserRXData[i];
	}
	else
		cerr << qPrintable(lines[0]);
	cerr << "\n";

	socket->write("HTTP/1.1 200 OK\r\n");	// radne ukonceni radku v raw modu: \r\n
	socket->write("Content-Type: text/html\r\n");
	socket->write("Connection: close\r\n");
	socket->write("Refresh: 1\r\n\r\n");	// prohlizec obnovuje kazdou vterinu. konec hlavicky, nasleduje 2x \r\n.

	socket->write("<!DOCTYPE html>\r\n");
	socket->write("<html>\n");
	socket->write("<body>\n<h1>Current datetime (");
	QByteArray str;
	str.setNum(count++);   			// konverze int -> string
	socket->write(str);
	socket->write(")</h2>");
	socket->write("<p>");
	QString cas = QDateTime::currentDateTime().toString();
	socket->write(cas.toLocal8Bit());
	socket->write("</p>\n</body>\n</html>\n");

	socket->flush();
	connect (socket, SIGNAL(disconnected()), socket, SLOT(deleteLater()));
	socket->disconnectFromHost();
}

HTTPserver::~HTTPserver()
{
	socket->close();
}
