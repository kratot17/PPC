#include <QDebug>
#include <QPixmap>

#include "formular.h"

Formular::Formular (QWidget *parent) : QWidget (parent)
{
	// inicializace UI
	ui.setupUi (this);
}

void Formular::slot3()
{
	QPixmap p(QSize(100, 100));
	p.fill (QColor(ui.R->value(), ui.G->value(), ui.B->value()));
	ui.label->setPixmap(p);
}
