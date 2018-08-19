#pragma once
#include <QtWidgets>
class Patient: public QObject {
Q_OBJECT
private:
    QString name;
    QString age;
public:
    Patient( QString name = "***** ***** *****", QString age = 0, QObject* pobj = 0 );
    void setName( QString name );
    void setAge( QString age );
    const QString& getName();
    QString getAge();
public slots:
    void slotsetName( const QString& name );

};
