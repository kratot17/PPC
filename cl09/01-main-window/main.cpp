#include <QApplication>
#include <QMainWindow>
#include <QAction>
#include <QMenuBar>
#include <QMenu>
#include <QStatusBar>
#include <QTranslator>

int main(int argc, char ** argv)
{
    QApplication app(argc, argv);

    QMainWindow w;

    QMenuBar* bar = w.menuBar();
    QMenu* menu = bar->addMenu("&File");
    menu->addAction(new QAction("Open"));
    menu->addSeparator();
    QMenu* subMenu = menu->addMenu("Save");
    subMenu->addAction(new QAction("Save"));
    subMenu->addAction(new QAction("Save As"));

    QStatusBar * status = w.statusBar();
    status->showMessage("nazdar");

    w.show();

    return app.exec();
}