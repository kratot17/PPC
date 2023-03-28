#include <QApplication>
#include <QLabel>
#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>

class Okno : public QMainWindow
{

public:
	Okno(QWidget *parent = 0) : QMainWindow(parent)
	{
		this->resize(320, 240);
		QGraphicsScene *scene = new QGraphicsScene;
		scene->addLine(20, 50, 50, 200);
		scene->addRect(100, 50, 60, 80);
		scene->addRect(100, 50, 60, 80, QPen(), QBrush(Qt::red));
		scene->addEllipse(200, 100, 80, 80);
		QGraphicsView *view = new QGraphicsView(scene);
		setCentralWidget(view);
	}
};

int main(int argc, char **argv)
{
	QApplication a(argc, argv);

	Okno w;
	w.show();
	return a.exec();
}