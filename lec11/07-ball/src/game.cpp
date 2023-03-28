#include "game.h"

Game::Game (QWidget *parent) : QWidget (parent)
{
    resize(400, 400);

    h = new QVBoxLayout;

    s = new QSlider(this);
    s->setOrientation(Qt::Horizontal);
    s->setMaximum(70);
    s->setValue(70);
    s->setMinimum(20);
    h->addWidget(s);
    connect(s, SIGNAL(valueChanged(int)), this, SLOT(changeSpeed()));

    QWidget *w = new QWidget;
    b = new Ball(5, 5, w);
    h->addWidget(w);

    statusBar = new QStatusBar;
    statusBar->setMaximumHeight(20);
    statusBar->showMessage(QString("current speed: %1").arg(s->value()));
    // vlozeni status baru do layoutu
    h->addWidget(statusBar);

    setLayout(h);

    // casovac pro pohyb
    t = new QTimer;
    t->setInterval(100);
    t->start();

    // b->pohyb();
    connect (t, SIGNAL(timeout()), b, SLOT(pohyb()));
}

void Game::changeSpeed()
{
    t->setInterval(s->value());
    statusBar->showMessage(QString("current speed: %1").arg(100 - s->value()));
}