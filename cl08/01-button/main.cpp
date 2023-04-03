#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	QPushButton b("Hello world");
	b.show();
	return app.exec();
}