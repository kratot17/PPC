#include <QApplication>
#include <QRadioButton>
#include <QVBoxLayout>
#include <QGroupBox>

int main(int argc, char **argv)
{
    QApplication a(argc, argv);

    QGroupBox *groupBox = new QGroupBox("Radio Buttons");

    QRadioButton *radio1 = new QRadioButton("&Radio button 1");
    QRadioButton *radio2 = new QRadioButton("R&adio button 2");
    QRadioButton *radio3 = new QRadioButton("Ra&dio button 3");

    radio1->setChecked(true);

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(radio1);
    vbox->addWidget(radio2);
    vbox->addWidget(radio3);
    vbox->addStretch(1);

    groupBox->setLayout(vbox);
    groupBox->show();

    return a.exec();
}