#include <QWidget>
#include <QPainter>
#include <QPainterPath>

class Ball : public QWidget
{
    Q_OBJECT

    // zmena v prostoru
    int dx, dy;

public:
    Ball (int dx, int dy, QWidget* parent=0) : QWidget (parent), dx(dx), dy(dy)
    {
        this->setFixedSize(10, 10);
    }

    void paintEvent (QPaintEvent *e)
    {
        Q_UNUSED (e);

        QPainter p (this);
        QPainterPath pp;
        pp.addEllipse (this->rect());
        p.fillPath (pp, Qt::red);
    }

public slots:
    void pohyb (void)
    {
        // aktualni pozice mice
        QPoint p = this->pos();

        // souradnice x
        int x = p.x() + dx;
        // souradnice y
        int y = p.y() + dy;

        if (x < 0)
        {
            x = 0;
            dx *= -1; // zmenim smer micku v souradnici x
        }
        else if (x + width() > parentWidget()->width())
        {
            x = parentWidget()->width() - width(); // sirka nadrazeneho konteru - sirka objektu
            dx *= -1;
        }

        if (y < 0)
        {
            y = 0; 
            dy *= -1;
        }
        else if (y + height() > parentWidget()->height())
        {
            y = parentWidget()->height() - height();
            dy *= -1;
        }

        move (x, y);
    }
};

