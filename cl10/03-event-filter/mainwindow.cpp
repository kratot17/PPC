#include "mainwindow.h"

MainWindow::MainWindow()
{
  bpCnt = 0;
  tabCnt = 0;

  bpCounter = new QLabel(QString("Backspace Count: %1").arg(bpCnt));
  bpTab = new QLabel(QString("Tab Count: %1").arg(tabCnt));

  textEdit = new QTextEdit;
  setCentralWidget(textEdit);

  statusBar()->addWidget(bpCounter);
  statusBar()->addWidget(bpTab);
  textEdit->installEventFilter(this);
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
  if (obj == textEdit) 
  {
    if (event->type() == QEvent::KeyPress) 
    {
      QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
      if ( keyEvent->key() == Qt::Key_Backspace ) 
      {
        bpCounter->setText(QString("Backspace Count: %1").arg(++bpCnt));
      }
      else if ( keyEvent->key() == Qt::Key_Tab )
      {
        // 4 spaces
        textEdit->insertPlainText(QString().fill(' ', 4));
        bpTab->setText(QString("Tab Count: %1").arg(++tabCnt));
        return true;
      }
    }
    // pass the event to the widget
    return false;
  }
  else 
  {
    // pass the event on to the parent class
    return QMainWindow::eventFilter(obj, event);
  }
};