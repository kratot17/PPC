#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

int main(int argc, char ** argv) 
{
	QCoreApplication a (argc, argv);

	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	QString filename ("got.db");

	db.setDatabaseName(filename);

	if (!db.open())
	{
		qDebug() << db.lastError().text();
	}

	QSqlQuery query ("SELECT name FROM characters");

	while (query.next()) 
	{
		QString name = query.value(0).toString();
		qDebug() << name;
	}

	return a.exec();
}
