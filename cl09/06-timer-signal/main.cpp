#include <QApplication>
#include <QPushButton>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QTimer>

int main(int argc, char ** argv)
{
    QApplication a (argc, argv);

    QWidget w;

    QPushButton *b1 = new QPushButton("jedna");
    QPushButton *b2 = new QPushButton("dva");
    
    QHBoxLayout * l = new QHBoxLayout;

    l->addWidget(b1);
    l->addWidget(b2);

    w.setLayout(l);
    w.show();

    QTimer t;
    // QMessageBox msg;
    // msg.setText("ahoj");
    QMessageBox msg (QMessageBox::Information, "Informace", "Zdravime PPC!", QMessageBox::Yes | QMessageBox::No);

    QObject::connect(b1, QPushButton::clicked, qApp, [&t](){t.start(3000);});
    QObject::connect(b1, QPushButton::clicked, qApp, [&msg, &t](){msg.exec(); t.start(3000);});
    QObject::connect(&t, QTimer::timeout, qApp, [&msg](){msg.close();});
    QObject::connect(b2, QPushButton::clicked, [&b2](){b2->setText("clicked");});

    return a.exec();
}