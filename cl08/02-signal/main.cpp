#include <QApplication>
#include <QPushButton>

int main(int argc, char ** argv)
{
	QApplication app (argc, argv);
	// objekt může být vytvořen v zásobníku i na haldě
	QPushButton *b = new QPushButton("&Quit");
	// propojení signálu emitovaného objektem se slotem aplikace
	QObject::connect(b, SIGNAL(clicked()), &app, SLOT(quit()));
	// aktivace objektu
	b->show();
	//
	return app.exec();
}