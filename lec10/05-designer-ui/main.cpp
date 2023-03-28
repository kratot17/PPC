#include <QApplication>

#include "ui_formular.h"

int main(int argc, char ** argv)
{
    QApplication app(argc, argv);

    QWidget widget;
    Ui_Form ui;
    ui.setupUi(&widget);

    widget.show();

    return app.exec();
}
