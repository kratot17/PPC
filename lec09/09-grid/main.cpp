#include <QApplication>
#include <QPushButton>
#include <QGridLayout>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	QWidget* window = new QWidget;

	QPushButton *one = new QPushButton("One");
	QPushButton *two = new QPushButton("Two");
	QPushButton *three = new QPushButton("Three");

	QGridLayout* layout = new QGridLayout;

	layout->addWidget(one, 0, 0); // row:0, col:0
	layout->addWidget(two, 0, 1); // row:0, col:1
	layout->addWidget(three, 1, 0, 1, 2); // r:1, c:0, rSpan:1, cSpan:2

	window->setLayout(layout);
	window->show();

	return app.exec();
}
