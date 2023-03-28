#include <QApplication>

#include "okno.h"

int main(int argc, char ** argv)
{
    QApplication app(argc, argv);

    Okno w;
    w.show();

    return app.exec();
}