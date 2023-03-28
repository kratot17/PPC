#include <QApplication>
#include <QWidget>
#include <QPainter>

class Lines : public QWidget 
{

public:
	Lines (QWidget *parent = 0) : QWidget (parent) 
	{
		resize(280, 270);
	}

protected:
	void paintEvent(QPaintEvent *event)
	{
		Q_UNUSED(event);
  
		QPainter qp(this);
  		drawLines(&qp);
	}

	void drawLines(QPainter *qp)
	{	
		QPen pen(Qt::black, 2, Qt::SolidLine);  
		qp->setPen(pen); // setPen (new QPen())
  		qp->drawLine(20, 40, 250, 40);

		pen.setStyle(Qt::DashLine);
		qp->setPen(pen);
		qp->drawLine(20, 80, 250, 80);

		pen.setStyle(Qt::DashDotLine);
		qp->setPen(pen);
		qp->drawLine(20, 120, 250, 120);

		pen.setStyle(Qt::DotLine);
		qp->setPen(pen);
		qp->drawLine(20, 160, 250, 160);

		pen.setStyle(Qt::DashDotDotLine);
		qp->setPen(pen);
		qp->drawLine(20, 200, 250, 200);

		QVector<qreal> dashes;
		qreal space = 4;

		dashes << 1 << space << 5 << space;

		pen.setStyle(Qt::CustomDashLine);
		pen.setDashPattern(dashes);
  
		qp->setPen(pen);
		qp->drawLine(20, 240, 250, 240);
	}
};

int main (int argc, char ** argv)
{
	QApplication a(argc, argv);
	
	Lines w;
	w.show();

	return a.exec();
}