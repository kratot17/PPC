#include <QApplication>

#include "formular.h"

int main(int argc, char ** argv)
{
	QApplication a (argc, argv); 
	
	Formular w;
	w.show();

	return a.exec();
}
