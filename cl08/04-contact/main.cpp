#include "contact.h"
#include <QDebug>
#include <QVariant>

int main()
{
	Contact contact;
	contact.setName("Peter");
	const QVariant variant = QVariant::fromValue(contact);
	const Contact otherContact = variant.value<Contact>();

	qDebug() << otherContact.name(); // "Peter"
	qDebug() << variant.typeName(); // prints "Contact"

	return 0;
}