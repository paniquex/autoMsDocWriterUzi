#include "patient.h"
#include <QtWidgets>

Patient::Patient( QString name, QObject* pobj )
{
    this->name = name;
}

void Patient::setName( QString name )
{
    this->name = name;
}

//void Patient::setAge ( QDate age )
//{
//    this->age.setDate( )
//}

const QString& Patient::getName()
{
    return this->name;
}

QDate Patient::getAge()
{
    return this->age;
}

void Patient::slotsetName( const QString& name )
{

}


