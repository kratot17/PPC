#include <QPainter>
#include <QTimer>
#include <QTextStream>

#include "puff.h"

Puff::Puff(QWidget *parent = 0) : QWidget(parent)
{
	x = 1;
	opacity = 1.0;
	timerId = startTimer(15);
	resize(350, 280);
}

void Puff::paintEvent(QPaintEvent *)
{
	QPainter painter(this);

	QString text = "Ahoj PPC!";

	painter.setPen(QPen(QBrush("#575555"), 1));

	QFont font("Courier", x, QFont::DemiBold);
	QFontMetrics fm(font);
	int textWidth = fm.boundingRect(text).width();

	painter.setFont(font);

	if (x > 10)
	{
		opacity -= 0.01;
		painter.setOpacity(opacity);
	}

	if (opacity <= 0)
	{
		killTimer(timerId);
	}

	int h = height();
	int w = width();

	painter.translate(QPoint(w / 2, h / 2));
	painter.drawText(-textWidth / 2, 0, text);
}

void Puff::timerEvent(QTimerEvent *)
{
	x += 1;
	repaint();
}