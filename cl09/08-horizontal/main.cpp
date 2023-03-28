#include <QApplication>
#include <QPushButton>
#include <QHBoxLayout>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	QWidget *window = new QWidget;
	QHBoxLayout *layout = new QHBoxLayout;
	layout->addWidget(new QPushButton("One"));
	layout->addWidget(new QPushButton("Two"));
	layout->addWidget(new QPushButton("Three"));
	window->setLayout(layout);
	window->show();
	return app.exec();
}