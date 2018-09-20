#include "newpatientform.h"

void newPatientForm::setupUi( QWidget* wgt )
{
    patientFormLayout = new QFormLayout;
    patientInfoLabel = new QLabel( "Введите информацию о пациенте: " );
    patientNameLabel = new QLabel( "ФИО: " );
    patientNameLine = new QLineEdit;
    patientAgeLabel = new QLabel( "Дата рождения: " );
    patientAgeDate = new QDateEdit;
    patientMaleRadio = new QRadioButton( "Муж." );
    patientFemaleRadio = new QRadioButton( "Жен." );
    patientSexLabel = new QLabel( "Пол пациента: " );
    patientGroup = new QButtonGroup;
    patientGroup->addButton( patientMaleRadio );
    patientGroup->addButton( patientFemaleRadio );
    patientGroup->setExclusive( true );
    patientSexLayout = new QHBoxLayout;
    patientSexLayout->addWidget( patientMaleRadio );
    patientSexLayout->addWidget( patientFemaleRadio );
    patientAgeDate->setCalendarPopup( true );

    patientFormLayout->addWidget( patientInfoLabel );
    patientFormLayout->addWidget( patientNameLabel );
    patientFormLayout->addWidget( patientNameLine );
    patientFormLayout->addWidget( patientAgeLabel );
    patientFormLayout->addWidget( patientAgeDate );
    patientFormLayout->addWidget( patientSexLabel );
    patientFormLayout->addWidget( patientMaleRadio );
    patientFormLayout->addWidget( patientFemaleRadio );

    wgt->setLayout( patientFormLayout );


}

newPatientForm::newPatientForm( QWidget* wgt )
{
    setupUi( wgt );
}

newPatientForm::~newPatientForm()
{
}
