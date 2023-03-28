#include <QApplication>
#include <QWidget>
#include <QPainter>

class Colours : public QWidget 
{
  
public:
	Colours (QWidget *parent = 0) : QWidget (parent) 
	{
		resize(360, 280);
	}

protected:
	void paintEvent(QPaintEvent *)
	{
		QPainter qp(this);
  		drawColouredRectangles(qp);
	}

	void drawColouredRectangles(QPainter & qp)
	{
		qp.setPen(QColor("#d4d4d4"));

		qp.setBrush(QBrush("#c56c00"));
		qp.drawRect(10, 15, 90, 60);

		qp.setBrush(QBrush("#1ac500"));
		qp.drawRect(130, 15, 90, 60);

		qp.setBrush(QBrush("#539e47"));
		qp.drawRect(250, 15, 90, 60);

		qp.setBrush(QBrush("#004fc5"));
		qp.drawRect(10, 105, 90, 60);

		qp.setBrush(QBrush("#c50024"));
		qp.drawRect(130, 105, 90, 60);

		qp.setBrush(QBrush("#9e4757"));
		qp.drawRect(250, 105, 90, 60);

		qp.setBrush(QBrush("#5f3b00"));
		qp.drawRect(10, 195, 90, 60);

		qp.setBrush(QBrush("#4c4c4c"));
		qp.drawRect(130, 195, 90, 60);

		qp.setBrush(QBrush("#785f36"));
		qp.drawRect(250, 195, 90, 60);
	}
};

int main (int argc, char ** argv)
{
	QApplication a(argc, argv);
	
	Colours w;
	w.show();

	return a.exec();
}