#include <QCoreApplication>
#include <QtCore/QUrl>
#include <QDebug>
#include <QSettings>
#include <QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QJsonDocument.h>
#include <QJsonObject.h>

int main(int argc, char *argv[])
{
	QCoreApplication app(argc, argv);

	/*
	 * jak nastavit konfiguracni data pomoci QSettings
	 * QSettings settings ("api"); // vytvori ~/.config/api.conf
	 * settings.setValue ("key", "vas klic ktery jste ziskali pri registraci");
	 * settings.sync();
	 */
	// QSettings settings ("api");
	// QString key = settings.value("key", "").toString();
	QString key("55bf16094a11895476589ed457ecb57d");

	QEventLoop eventLoop;
	QNetworkAccessManager mgr;
	QObject::connect (&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
	QNetworkRequest req (QUrl (QString("http://api.openweathermap.org/data/2.5/weather?q=prague&appid=%1").arg(key)));
	QNetworkReply *reply = mgr.get (req);
	eventLoop.exec();

	if (reply->error() == QNetworkReply::NoError) 
	{
		QString strReply = (QString)reply->readAll();
		QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());
		QJsonObject jsonObj = jsonResponse.object();
		qDebug() << "mesto: " << jsonObj["name"].toString();
		qDebug() << "vlhkost: " << jsonObj.value(QString("main")).toObject()["humidity"].toDouble();
		delete reply;
	}
	else 
	{
		qDebug() << "chyba" << reply->errorString();
		delete reply;
	}

	return 0;
}
