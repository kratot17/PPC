#include <QApplication>
#include <QListView>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>
#include <QTableView>

int main(int argc, char ** argv) 
{
	QApplication a (argc, argv);

	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	QString filename ("got.db");

	db.setDatabaseName(filename);

	if (db.open())
	{
		qDebug() << db.lastError().text();
	}

	QSqlQueryModel model;
	model.setQuery("SELECT * FROM characters", db);
/*
	for (int i = 0; i < model.rowCount(); ++i) {
		int id = model.record(i).value("id").toInt();
		QString name = model.record(i).value("name").toString();
		qDebug() << id << name;
	}	
*/


	model.setHeaderData(0, Qt::Horizontal, "id");
	model.setHeaderData(1, Qt::Horizontal, "name");
	model.setHeaderData(1, Qt::Horizontal, "name");

	QTableView view;
	view.setModel(&model);
	view.show();

	return a.exec();
}
