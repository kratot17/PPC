#include <QApplication>

#include "game.h"

int main (int argc, char ** argv)
{
    QApplication app(argc, argv);

    Game g;
    g.show();

    return app.exec();
}