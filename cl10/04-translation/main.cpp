#include <QApplication>
#include <QPushButton>
#include <QTranslator>

int main(int argc, char ** argv)
{
    QApplication app(argc, argv);

    QTranslator translator;

    if (!translator.load("trans_cz"))
        return 1;

    app.installTranslator(&translator);

    QPushButton b1(QPushButton::tr("Hello"));
    b1.show();

    return app.exec();
}