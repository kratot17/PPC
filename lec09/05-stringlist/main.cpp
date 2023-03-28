#include <iostream>
#include <QStringList>
#include <QDebug>

using namespace std;

int main()
{
        QStringList fonts = { "jedna", "dva", "tri" };

        fonts << "ctyri ";

        QStringList::const_iterator constIterator;
        for (constIterator = fonts.constBegin(); constIterator != fonts.constEnd(); ++constIterator)
        {
                cout << (*constIterator).toLocal8Bit().constData() << endl;
        }

        foreach (const QString &str, fonts) 
        {
                qDebug() << str;
        }

        QString a("ahoj");
        const char * pa = a.toLocal8Bit().constData();
        cout << pa << endl;
}