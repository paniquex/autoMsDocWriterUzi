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
    mainLayout->addWidget( &mainFrame, 1, 1, 3, 3 );

    mainLayout->addLayout( nameLayout, 1, 1 );
    mainLayout->addLayout( ageLayout, 2, 1 );
    mainLayout->addLayout( dateLayout, 3, 1 );

//Начало протокола:
    QFrame protocallFrame;
    protocallFrame.setFrameShape( QFrame::Box );
    QLabel* protocallLabel = new QLabel( "\t\t\t ПРОТОКОЛ \n ультразвукогого исследования органов брюшной полости");
    mainLayout->addWidget( &protocallFrame, 4, 1, 8, 3 );
    mainLayout->addWidget( protocallLabel, 4, 1);

//Заплняемая часть
    QLabel* liverLabel = new QLabel( "Печень: визуализируется");
    mainLayout->addWidget( liverLabel, 5, 1 );
    //Расположение печени

    QLabel* placeLabel = new QLabel( "Расположена: " );
    QRadioButton* placeStdRadio = new QRadioButton( "&Обычно");
    QRadioButton* placeLeftRadio = new QRadioButton( "&Слева" );
    placeStdRadio->setChecked( true );
    QVBoxLayout* placeLayout = new QVBoxLayout;
    placeLayout->addWidget( placeLabel );
    placeLayout->addWidget( placeStdRadio );
    placeLayout->addWidget( placeLeftRadio );
    mainLayout->addLayout( placeLayout, 5, 2 );

    //Доли
    QCheckBox* leftShareCheck = new QCheckBox( "Левая доля: не увеличена");
    QCheckBox* rightShareCheck = new QCheckBox( "Правая доля: не увеличена");
    QObject::connect( leftShareCheck, &QCheckBox::stateChanged,
                      [&] { if ( !( leftShareCheck->isChecked() ) ) leftShareCheck->setText("Левая доля: не увеличена");
                            if ( ( leftShareCheck->isChecked() ) ) leftShareCheck->setText("Левая доля: увеличена");
                            });
    QObject::connect( rightShareCheck, &QCheckBox::stateChanged,
                      [&] { if ( !( rightShareCheck->isChecked() ) ) rightShareCheck->setText("Правая доля: не увеличена");
                            if ( ( rightShareCheck->isChecked() ) ) rightShareCheck->setText("Правая доля: увеличена");
                            });
    mainLayout->addWidget( leftShareCheck, 6, 1 );
    mainLayout->addWidget( rightShareCheck, 7, 1 );

    //Толщина
    QSpinBox* leftThickSpin = new QSpinBox;
    QSpinBox* rightThickSpin = new QSpinBox;
    QLabel* thickLabel1 = new QLabel( "Толщина: " );
    QLabel* thickLabel2 = new QLabel( "Толщина: " );
    leftThickSpin->setSuffix(" ММ");
    rightThickSpin->setSuffix(" ММ");
    leftThickSpin->setRange( 0, 300 );
    rightThickSpin->setRange( 0, 300 );
    leftThickSpin->clear();
    rightThickSpin->clear();
    mainLayout->addWidget( thickLabel1, 6, 2 );
    mainLayout->addWidget( thickLabel2, 7, 2 );
    mainLayout->addWidget( leftThickSpin, 6, 3 );
    mainLayout->addWidget( rightThickSpin, 7, 3 );

    wgt.setLayout( mainLayout );
    wgt.show();


    return a.exec();
}
