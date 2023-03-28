#include <QApplication>
#include <QLabel>
#include <QSlider>
#include <QProgressBar>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QGroupBox>

int main(int argc, char **argv)
{

    QApplication a(argc, argv);

    
    QLabel *label1 = new QLabel;
    label1->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    label1->setText("QSlider");
    label1->setAlignment(Qt::AlignBottom | Qt::AlignRight);

    QSlider *slider = new QSlider(Qt::Horizontal);
    slider->setRange(0, 99);
    slider->setValue(42);

    QLabel *label2 = new QLabel;
    label2->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    label2->setText("QProgressBar");
    label2->setAlignment(Qt::AlignBottom | Qt::AlignRight);

    QProgressBar *progress = new QProgressBar;
    progress->setRange(0, 99);
    progress->setValue(42);
    // format: %v for value; %p for percentage
    progress->setFormat("%v (%p%)");

    QLabel *label3 = new QLabel;
    label3->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    label3->setText("QSpinBox");
    label3->setAlignment(Qt::AlignBottom | Qt::AlignRight);

    QSpinBox *spin = new QSpinBox;
    spin->setRange(0, 99);
    spin->setValue(42);
    spin->setSuffix(" USD");

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(label1);
    vbox->addWidget(slider);
    vbox->addWidget(label2);
    vbox->addWidget(progress);
    vbox->addWidget(label3);
    vbox->addWidget(spin);

    QGroupBox *groupBox = new QGroupBox("User inputs");
    groupBox->setLayout(vbox);
    groupBox->show();

    return a.exec();
}