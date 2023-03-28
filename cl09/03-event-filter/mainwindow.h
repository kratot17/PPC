#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainwindow>
#include <QTextedit>
#include <QLabel>
#include <QStatusBar>
#include <QKeyEvent>

class MainWindow : public QMainWindow
{
  public:
    MainWindow();

  protected:
    bool eventFilter(QObject *obj, QEvent *ev);

  private:
    QTextEdit *textEdit;
    QLabel    *bpCounter;
    QLabel    *bpTab;
    int        bpCnt;
    int        tabCnt;
};

#endif // MAINWINDOW_H