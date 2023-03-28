#include <QApplication>
#include <QListView>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>
#include <QTableView>
#include <QHeaderView>

int main(int argc, char ** argv) 
{
	QApplication a (argc, argv);

	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	QString filename ("got.db");

	db.setDatabaseName(filename);

	if (!db.open())
	{
		qDebug() << db.lastError().text();
	}

	QSqlTableModel model;
    	model.setTable("characters");
    	model.setFilter("id > 1");
    	model.setSort(2, Qt::DescendingOrder);
	model.setEditStrategy(QSqlTableModel::OnManualSubmit);
    	model.select();

	model.setHeaderData(0, Qt::Horizontal, "id");
	model.setHeaderData(1, Qt::Horizontal, "name");
	model.setHeaderData(1, Qt::Horizontal, "name");

	QTableView view;
	view.setModel(&model);

	view.resizeColumnsToContents();
	view.horizontalHeader()->setSectionsClickable(true);
	view.horizontalHeader()->setSectionsMovable(true);
	view.setSortingEnabled(true);

	view.show();

	// qDebug() << model.rowCount();
	auto row = model.rowCount();
/*
	model.insertRows(row, 1);
    	model.setData(model.index(row, 0), 4);
    	model.setData(model.index(row, 1), "Eddard");
    	model.setData(model.index(row, 2), "Winterfell");
    	model.submitAll();
*/
	QObject::connect(&model, QSqlTableModel::dataChanged, [&](const QModelIndex &index){
		int row = index.row();
    		int col = index.column();
		qDebug() << "row: " << row << ", col: " << col;
	});

	return a.exec();
}
