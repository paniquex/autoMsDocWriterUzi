#include "patient.h"
#include <QtWidgets>

Patient::Patient( QString name, QString age, QObject* pobj )
{
    this->name = name;
    this->age = age;
}

void Patient::setName( QString name )
{
    this->name = name;
}

void Patient::setAge ( QString age )
{
    this->age = age;
}

const QString& Patient::getName()
{
    return this->name;
}

QString Patient::getAge()
{
    return this->age;
}

void Patient::slotsetName( const QString& name )
{

}


