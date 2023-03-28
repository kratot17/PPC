#include "ui_formular.h"	// vznikne z formular.ui

class Formular : public QWidget
{
	Q_OBJECT
	
public:
	Formular (QWidget *parent = 0);	// top-level okno
	
private:
	Ui::Formular ui;	// Ui::Formular je trida vytvorena prekladem XML souboru

private slots:
	void slot3();
};
