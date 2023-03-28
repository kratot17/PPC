#include <QVBoxLayout>
#include <QTimer>
#include <QLabel>
#include <QSLider>
#include <QDebug>
#include <QStatusBar>

#include "ball.h"

class Game : public QWidget
{
    Q_OBJECT

    QVBoxLayout *h;
    Ball *b;
    QTimer *t;
    QLabel *l;
    QSlider *s;
    QStatusBar *statusBar;

public:
    Game (QWidget *parent=0);

public slots:
    void changeSpeed();
};