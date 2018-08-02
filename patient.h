#pragma once
#include <QtWidgets>
class Patient {
private:
    QString name;
    qint16 age;
public:
    Patient() {
        this->age = 00;
        this->name = "***** ***** *****";
    }
    void setName( QString name );
    void setAge( qint16 age );
    QString getName();
    qint16 getAge();


};
