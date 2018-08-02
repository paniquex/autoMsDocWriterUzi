#pragma once
#include <QtWidgets>
class Patient: public QObject {
Q_OBJECT
private:
    QString name;
    qint16 age;
public:
    Patient( QString name = "***** ***** *****", qint16 age = 0, QObject* pobj = 0 );
    void setName( QString name );
    void setAge( qint16 age );
    const QString& getName();
    qint16 getAge();
public slots:
    void slotsetName( const QString& name );

};
