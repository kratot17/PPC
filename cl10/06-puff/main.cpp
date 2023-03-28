#include <QApplication>

#include "puff.h"

int main(int argc, char ** argv) 
{
    
  QApplication a (argc, argv); 

  Puff w;

  w.setWindowTitle("Ahoj PPC!");
  w.show();

  return a.exec();
}