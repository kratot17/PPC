#include <QWidget>
#include <QDebug>
#include <QCloseEvent>

class Okno : public QWidget
{
public:
    Okno (QWidget * parent = 0) : QWidget (parent)
    {
        // 
    }

    bool event (QEvent * event)
    {
        // QEvent::Paint 
        if (event->type() == QEvent::Paint)
            qDebug() << event;
        return QWidget::event(event);
    }

    void closeEvent (QCloseEvent * event)
    {
        event->ignore();
    }
};