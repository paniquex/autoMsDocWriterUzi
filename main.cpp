#include <QApplication>
#include <QtWidgets>
#include <QLineEdit>
#include <QFrame>
#include "patient.h"
//#include "livercheck.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget wgt;

    QLineEdit* patientName = new QLineEdit;
    QDateEdit* patientAge = new QDateEdit;
    QDateEdit* researchDate = new QDateEdit( QDate::currentDate() );
    patientName->setFixedSize( 300, 20 );

    Patient* Kolya = new Patient;
    Kolya->setName( "Kolya Efimov" );
// Создаение Заголовков

    QLabel* labelName = new QLabel( "ФИО: "  );
    QLabel* labelAge  = new QLabel( "Год Рождения: " );
    QLabel* labelDate = new QLabel( "Дата исследования: " );


    QGridLayout* mainLayout = new QGridLayout();

    QHBoxLayout* nameLayout = new QHBoxLayout;
    nameLayout->addWidget( labelName );
    nameLayout->addWidget( patientName );

    QHBoxLayout* ageLayout = new QHBoxLayout;
    ageLayout->addWidget( labelAge );
    ageLayout->addWidget( patientAge );

    QHBoxLayout* dateLayout = new QHBoxLayout;
    dateLayout->addWidget( labelDate );
    dateLayout->addWidget( researchDate );

//Основной слой
    QFrame mainFrame;
    mainFrame.setFrameShape( QFrame::Box );
    mainLayout->addWidget( &mainFrame, 1, 1, 3, 2 );

    mainLayout->addLayout( nameLayout, 1, 1 );
    mainLayout->addLayout( ageLayout, 2, 1 );
    mainLayout->addLayout( dateLayout, 3, 1 );

    wgt.setLayout( mainLayout );

//Начало протокола:
    QFrame protocallFrame;
    protocallFrame.setFrameShape( QFrame::Box );
    QLabel* protocallLabel = new QLabel( "\t\t\t ПРОТОКОЛ \n ультразвукогого исследования органов брюшной полости");
    mainLayout->addWidget( &protocallFrame, 3, 1, 3, 2 );
    mainLayout->addWidget( protocallLabel, 4, 1);

//Заплняемая часть
    QLabel* liverLabel = new QLabel( "Печень: визуализируется");
    mainLayout->addWidget( liverLabel, 5, 1 );

    wgt.show();


    return a.exec();
}
