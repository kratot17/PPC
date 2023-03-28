#include <QMetaType>

class Contact
{
	QString n;
public:
	void setName(const QString & name) {n = name;}
	QString name() const {return n;}
};

Q_DECLARE_METATYPE(Contact);