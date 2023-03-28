#include <QApplication>
#include <QLabel>
#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>

class Okno : public QMainWindow 
{

public:
	Okno (QWidget *parent = 0) : QMainWindow(parent) 
	{ 
		resize(320, 440);
		QGraphicsScene* scene = new QGraphicsScene;
		QPolygonF polygon;

		polygon <<
			QPointF( 50,  50) << // start here
			QPointF( 50,  70) << // going down
			QPointF(100,  70) << // going right
			QPointF(100, 180) << // going down
			QPointF(120, 180) << // going right
			QPointF(120,  70) << // going up
			QPointF(170,  70) << // going right
			QPointF(170,  50) << // going up
			QPointF( 50,  50);   // going left (back to start)
		QGraphicsPolygonItem * p = scene->addPolygon(polygon, QPen(), Qt::red);
		// libo-li barvicky? 
    		// scene->addPolygon(polygon, QPen(), QBrush(Qt::red));
		QTransform t;
		int centerX = p->boundingRect().width()/2;
		int centerY = p->boundingRect().height()/2; 
		t.translate(centerX, centerY); 
		// t.rotate(45); 
		// t.translate(-centerX , -centerY );
		// p->setTransformOriginPoint(0, 0);
		p->setTransform(t);
		// p->setRotation(90);
		QGraphicsView* view = new QGraphicsView(scene);
		setCentralWidget(view);
	}
};

int main (int argc, char ** argv) 
{
	QApplication a(argc, argv);

	Okno w;
	w.show();

	return a.exec(); 
}