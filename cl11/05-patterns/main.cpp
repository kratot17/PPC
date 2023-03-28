#include <QApplication>
#include <QWidget>
#include <QPainter>

class Patterns : public QWidget
{

public:
	Patterns(QWidget *parent = 0) : QWidget(parent)
	{
		resize(350, 280);
	}

protected:
	void paintEvent(QPaintEvent *)
	{
		QPainter qp(this);
		drawRectangles(qp);
	}

	void drawRectangles(QPainter &qp)
	{
		qp.setPen(Qt::NoPen);

		qp.setBrush(Qt::HorPattern);
		qp.drawRect(10, 15, 90, 60);

		qp.setBrush(Qt::VerPattern);
		qp.drawRect(130, 15, 90, 60);

		qp.setBrush(Qt::CrossPattern);
		qp.drawRect(250, 15, 90, 60);

		qp.setBrush(Qt::Dense7Pattern);
		qp.drawRect(10, 105, 90, 60);

		qp.setBrush(Qt::Dense6Pattern);
		qp.drawRect(130, 105, 90, 60);

		qp.setBrush(Qt::Dense5Pattern);
		qp.drawRect(250, 105, 90, 60);

		qp.setBrush(Qt::BDiagPattern);
		qp.drawRect(10, 195, 90, 60);

		qp.setBrush(Qt::FDiagPattern);
		qp.drawRect(130, 195, 90, 60);

		qp.setBrush(Qt::DiagCrossPattern);
		qp.drawRect(250, 195, 90, 60);
	}
};

int main(int argc, char **argv)
{

	QApplication a(argc, argv);

	Patterns w;
	w.show();

	return a.exec();
}