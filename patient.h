#pragma once
#include <QtWidgets>
#include <newpatientform.h>
class Patient: public QObject {
Q_OBJECT
private:
    QString name;
    QDate age;
public:
    Patient( QString name = "***** ***** *****", QObject* pobj = 0 );
    void setName( QString name );
    void setAge( QDate age );
    const QString& getName();
    QDate getAge();
public slots:
    void slotsetName( const QString& name );

};
