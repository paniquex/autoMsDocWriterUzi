#pragma once

#include <QObject>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QDateEdit>
#include <QRadioButton>
#include <QButtonGroup>
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
    QButtonGroup* patientGroup;
    QRadioButton* patientMaleRadio;
    QRadioButton* patientFemaleRadio;
    QLabel* patientSexLabel;
    QHBoxLayout* patientSexLayout;

    newPatientForm( QWidget *wgt );
    ~newPatientForm();

signals:

public slots:
};
