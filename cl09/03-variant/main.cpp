#include <QDebug>
#include <QVariant>
#include <QColor>

int main ()
{
	QVariant v1(42);
	int value = v1.toInt(); // read back
	qDebug() << v1.typeName(); // int

	QVariant v2 = QVariant::fromValue(QColor(Qt::red));
	QColor color = v2.value<QColor>(); // read back
	qDebug() << v2.typeName(); // "QColor"

	return 0;
}