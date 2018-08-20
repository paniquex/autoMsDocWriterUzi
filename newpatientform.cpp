#include "newpatientform.h"

void newPatientForm::setupUi( QWidget* wgt )
{
    patientFormLayout = new QFormLayout;
    patientInfoLabel = new QLabel( "Введите информацию о пациенте: " );
    patientNameLabel = new QLabel( "ФИО: " );
    patientNameLine = new QLineEdit;
    patientAgeLabel = new QLabel( "Дата рождения: " );
    patientAgeDate = new QDateEdit;
    patientAgeDate->setCalendarPopup( true );

    patientFormLayout->addWidget( patientInfoLabel );
    patientFormLayout->addWidget( patientNameLabel );
    patientFormLayout->addWidget( patientNameLine );
    patientFormLayout->addWidget( patientAgeLabel );
    patientFormLayout->addWidget( patientAgeDate );

    wgt->setLayout( patientFormLayout );


}

newPatientForm::newPatientForm( QWidget* wgt )
{
    setupUi( wgt );
}

newPatientForm::~newPatientForm()
{
}
