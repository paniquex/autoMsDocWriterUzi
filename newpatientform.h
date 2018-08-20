#pragma once

#include <QObject>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QDateEdit>
#include <QFormLayout>

class newPatientForm : public QWidget
{
    Q_OBJECT
public:
    void setupUi( QWidget *wgt );
    QLabel* patientInfoLabel;
    QLineEdit* patientNameLine;
    QLabel* patientNameLabel;
    QDateEdit* patientAgeDate;
    QLabel* patientAgeLabel;
    QFormLayout* patientFormLayout;

    newPatientForm( QWidget *wgt );
    ~newPatientForm();

signals:

public slots:
};
