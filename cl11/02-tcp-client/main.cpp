#include "client.h"

int main (int argc, char ** argv)
{
	QCoreApplication a (argc, argv);
	
	QString message;

	if (argc == 2) 
		message = QString (argv[1]);
	else 
		message = QString ("ahoj");
        
	Client c(message);
        
	return a.exec();
}

