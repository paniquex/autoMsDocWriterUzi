#include "patient.h"
#include <QtWidgets>

Patient::Patient( QString name, qint16 age, QObject* pobj )
{
    this->name = name;
    this->age = age;
}

void Patient::setName( QString name )
{
    this->name = name;
}

void Patient::setAge ( qint16 age )
{
    this->age = age;
}

const QString& Patient::getName()
{
    return this->name;
}

qint16 Patient::getAge()
{
    return this->age;
}

void Patient::slotsetName( const QString& name )
{
    this->name = "Kolya Pupkin";
}


