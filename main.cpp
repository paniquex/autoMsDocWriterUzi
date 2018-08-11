#include "formofliver.h"
#include <QtWidgets>
#include <QLineEdit>
#include <QFrame>
#include <QDebug>
#include <QAxObject>
#include <QAxBase>
#include "patient.h"


//#include "livercheck.h"
void replaceString(QAxObject* pActiveDoc, const QString& oldString, const QString& newString);


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget wgt;
    qint32 gridX = 1, gridY = 1;
    QLineEdit* patientName = new QLineEdit;

    patientName->setFixedHeight( 15 );
    QDateEdit* patientAge = new QDateEdit;
    QDateEdit* researchDate = new QDateEdit( QDate::currentDate() );

    Patient* Kolya = new Patient;
    Kolya->setName( "Kolya Efimov" );
// Создаение Заголовков

    QLabel* labelName = new QLabel( "ФИО: "  );
    QLabel* labelAge  = new QLabel( "Год Рождения: " );
    QLabel* labelDate = new QLabel( "Дата исследования: " );


//Заплняемая часть
    QLabel* liverLabel = new QLabel( "ПЕЧЕНЬ: визуализируется");
    //Расположение печени

    QLabel* placeLabel = new QLabel( "Расположена: " );
    QRadioButton* placeStdRadio = new QRadioButton( "&Обычно" );
    QRadioButton* placeLeftRadio = new QRadioButton( "&Слева" );
    placeStdRadio->setChecked( true );

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

    //Толщина
    QSpinBox* leftThickSpin = new QSpinBox;
    QSpinBox* rightThickSpin = new QSpinBox;
    QLabel* thickLabel1 = new QLabel( "Толщина: " );
    QLabel* thickLabel2 = new QLabel( "Толщина: " );
    leftThickSpin->setSuffix(" мм");
    rightThickSpin->setSuffix(" мм");
    leftThickSpin->setRange( 0, 300 );
    rightThickSpin->setRange( 0, 300 );
    leftThickSpin->clear();
    rightThickSpin->clear();

    //Контуры
    QLabel* contourLabel = new QLabel( "Контуры: " );
    QRadioButton* contourStraight = new QRadioButton( "Ровные" );
    QRadioButton* contourNotStraight = new QRadioButton( "Неровные" );
    QRadioButton* contourHilly = new QRadioButton( "Бугристые" );
        //делаем независимыми c предыдущими радио-кнопками
    QButtonGroup* contourGroups = new QButtonGroup;
    contourGroups->addButton( contourStraight );
    contourGroups->addButton( contourNotStraight );
    contourGroups->addButton( contourHilly );
    contourGroups->setExclusive( true );

    //Эхоструктура
    QCheckBox* echoCheck = new QCheckBox( "Эхоструктура: неоднородная" );
    echoCheck->setFixedSize( 200, 20 );
    QObject::connect( echoCheck, &QCheckBox::stateChanged,
                          [&] { if ( !( echoCheck->isChecked() ) ) echoCheck->setText("Эхоструктура: неоднородная");
                                if ( ( echoCheck->isChecked() ) ) echoCheck->setText("Эхоструктура: однородная");
                                });


    //Эхогенность
    QLabel* echogenLabel = new QLabel( "Эхогенность: " );
    QRadioButton* echogenUpRadio = new QRadioButton( "Повышена" );
    QRadioButton* echogenDownRadio = new QRadioButton( "Понижена" );
    QRadioButton* echogenMidRadio = new QRadioButton( "Средняя");

        //делаем независимыми от других радио-кнопок
    QButtonGroup* echogenGroup = new QButtonGroup;
    echogenGroup->addButton( echogenUpRadio );
    echogenGroup->addButton( echogenDownRadio );
    echogenGroup->addButton( echogenMidRadio );
    echogenGroup->setExclusive( true );

    //Магистр. ствол
    QCheckBox* magCheck = new QCheckBox( "Магистральный ствол воротной вены: не расширен, " );
    QObject::connect( magCheck, &QCheckBox::stateChanged,
                      [&] { if ( !( magCheck->isChecked() ) ) magCheck->setText("Магистральный ствол воротной вены: не расширен, ");
                            if ( ( magCheck->isChecked() ) ) magCheck->setText("Магистральный ствол воротной вены: расширен, ");
                            });
    QSpinBox* magSpin = new QSpinBox;
    magSpin->setRange( 0, 300 );
    magSpin->setSuffix( " мм" );
    magSpin->clear();

    //Скорость кровотока
    QLabel* speedBloodLabel = new QLabel( "Скорость кровотока: " );
    QRadioButton* speedBloodUpRadio = new QRadioButton( "Высокая" );
    QRadioButton* speedBloodDownRadio = new QRadioButton( "Низкая" );
    QRadioButton* speedBloodMidRadio = new QRadioButton( "Нормальная");

        //делаем независимыми от других радио-кнопок
    QButtonGroup* speedBloodGroup = new QButtonGroup;
    speedBloodGroup->addButton( speedBloodUpRadio );
    speedBloodGroup->addButton( speedBloodDownRadio );
    speedBloodGroup->addButton( speedBloodMidRadio );
    speedBloodGroup->setExclusive( true );

    //Печеночные Вены
    QCheckBox* hepaticCheck = new QCheckBox( "Печоночные вены: не изменены" );
    hepaticCheck->setFixedSize( 230, 20 );
    QObject::connect( hepaticCheck, &QCheckBox::stateChanged,
                          [&] { if ( !( hepaticCheck->isChecked() ) ) hepaticCheck->setText("Печоночные вены: не изменены");
                                if ( ( hepaticCheck->isChecked() ) ) hepaticCheck->setText("Печоночные вены: изменены");
                                });

    //Нижняя полая вена
    QCheckBox* downVenaCheck = new QCheckBox( "Нижняя полая вена: не расширена, " );
    QObject::connect( downVenaCheck, &QCheckBox::stateChanged,
                      [&] { if ( !( downVenaCheck->isChecked() ) ) downVenaCheck->setText("Нижняя полая вена: не расширена, ");
                            if ( ( downVenaCheck->isChecked() ) ) downVenaCheck->setText("Нижняя полая вена:   расширена, ");
                            });
    QSpinBox* downVenaSpin = new QSpinBox;
    downVenaSpin->setRange( 0, 300 );
    downVenaSpin->setSuffix( " мм" );
    downVenaSpin->clear();

    //Внутрипеченочные желчные протоки
    QCheckBox* inhepaticCheck = new QCheckBox( "Внутрипечоночные желчные протоки: не расширены" );
    inhepaticCheck->setFixedSize( 340, 20 );
    QObject::connect( inhepaticCheck, &QCheckBox::stateChanged,
                          [&] { if ( !( inhepaticCheck->isChecked() ) ) inhepaticCheck->setText("Внутрипечоночные желчные протоки: не расширены");
                                if ( ( inhepaticCheck->isChecked() ) ) inhepaticCheck->setText( "Внутрипечоночные желчные протоки:    расширены" );
                                });

    //Общий желчный проток:
    QCheckBox* commonBileCheck = new QCheckBox( "Общий желчный проток: не изменен," );
    QObject::connect( commonBileCheck, &QCheckBox::stateChanged,
                      [&] { if ( !( commonBileCheck->isChecked() ) ) commonBileCheck->setText("Общий желчный проток: не изменен,");
                            if ( ( commonBileCheck->isChecked() ) ) commonBileCheck->setText("Общий желчный проток:     изменен,");
                            });
    QSpinBox* commonBileSpin = new QSpinBox;
    commonBileSpin->setRange( 0, 300 );
    commonBileSpin->setSuffix( " мм" );
    commonBileSpin->clear();
    QCheckBox* commonBileCheck2 = new QCheckBox( " стенки: не утолщены");
    QObject::connect( commonBileCheck2, &QCheckBox::stateChanged,
                      [&] { if ( !( commonBileCheck2->isChecked() ) ) commonBileCheck2->setText(" стенки: не утолщены");
                            if ( ( commonBileCheck2->isChecked() ) ) commonBileCheck2->setText(" стенки:     утолщены");
                            });

    //Заключние
    QLabel* liverConclusionLabel = new QLabel( "ОПИСАНИЕ: " );
    QTextEdit* liverConclusionText = new QTextEdit;
    liverConclusionText->setFixedSize( 1200, 20 );


//ЖЕЛЧНЫЙ ПУЗЫРЬ
    QLabel* gallbladerLabel = new QLabel( " ЖЕЛЧНЫЙ ПУЗЫРЬ: " );

    //Размер
    QLineEdit* gallbladerSizeLine = new QLineEdit(" мм");
    QLabel* gallbladerSizeLabel = new QLabel( "Размер: " );

    //Деформация
    QLabel* gallbladerDeformationLabel = new QLabel( "Деформация: " );
    QFont gallbladerDeformationFont;
    QCheckBox* gallbladerDeformationNeckCheck = new QCheckBox( "" );
    gallbladerDeformationNeckCheck->setFont( gallbladerDeformationFont );
    QObject::connect( gallbladerDeformationNeckCheck, &QCheckBox::stateChanged,
                          [&] { if ( ( gallbladerDeformationNeckCheck->isChecked() ) ) gallbladerDeformationNeckCheck->setText( "в шейке, " );
                                if ( !( gallbladerDeformationNeckCheck->isChecked() ) ) gallbladerDeformationNeckCheck->setText( "" );
                                });
    QCheckBox* gallbladerDeformationBodyCheck = new QCheckBox( "" );
    QObject::connect( gallbladerDeformationBodyCheck, &QCheckBox::stateChanged,
                          [&] { if ( ( gallbladerDeformationBodyCheck->isChecked() ) ) gallbladerDeformationBodyCheck->setText( "в теле, " );
                                if ( !( gallbladerDeformationBodyCheck->isChecked() ) ) gallbladerDeformationBodyCheck->setText( "" );
                                });
    QCheckBox* gallbladerDeformationBottomCheck = new QCheckBox( "" );

    QObject::connect( gallbladerDeformationBottomCheck, &QCheckBox::stateChanged,
                          [&] { if ( ( gallbladerDeformationBottomCheck->isChecked() ) ) gallbladerDeformationBottomCheck->setText( "в дне" );
                                if ( !( gallbladerDeformationBottomCheck->isChecked() ) ) gallbladerDeformationBottomCheck->setText( "" );
                                });


    //Стенки
    QSpinBox* gallbladerWallSpin = new QSpinBox;
    gallbladerWallSpin->setRange( 0, 300 );
    QLabel* gallbladerWallLabel = new QLabel( "Стенки: " );

    //Содержимое
    QCheckBox* gallbladerContentCheck = new QCheckBox( "Содержимое: неоднородное" );
    gallbladerContentCheck->setFixedSize( 230, 20 );
    QObject::connect( gallbladerContentCheck, &QCheckBox::stateChanged,
                          [&] { if ( !( gallbladerContentCheck->isChecked() ) ) gallbladerContentCheck->setText("Содержимое: неоднородное" );
                                if ( ( gallbladerContentCheck->isChecked() ) ) gallbladerContentCheck->setText("Содержимое:   однородное" );
                                });

    //Конкременты
    QCheckBox* gallbladerConcrementsCheck = new QCheckBox( "Конкременты: не визуализируются" );
    gallbladerConcrementsCheck->setFixedSize( 230, 20 );
    QObject::connect( gallbladerConcrementsCheck, &QCheckBox::stateChanged,
                          [&] { if ( !( gallbladerConcrementsCheck->isChecked() ) ) gallbladerConcrementsCheck->setText( "Конкременты: не визуализируются" );
                                if ( ( gallbladerConcrementsCheck->isChecked() ) ) gallbladerConcrementsCheck->setText( "Конкременты:    визуализируются" );
                                });
    //Заключение
    QLabel* gallbladerConclusionLabel = new QLabel( "ОПИСАНИЕ: " );
    QTextEdit* gallbladerConclusionText = new QTextEdit;
    gallbladerConclusionText->setFixedSize( 1200, 20 );


//ПОДЖЕЛУДОЧНАЯ ЖЕЛЕЗА
    QLabel* pancreasLabel = new QLabel( "ПОДЖЕЛУДОЧНАЯ ЖЕЛЕЗА: визуализируется. Положение: типичное" );


    //Размеры
    QLabel* pancreasSizeHeadLabel = new QLabel( "Размер: головки:" );
    QLabel* pancreasSizeBodyLabel = new QLabel( ", тела:" );
    QLabel* pancreasSizeTailLabel = new QLabel( ", хвоста:" );
    QSpinBox* pancreasSizeHeadSpin = new QSpinBox;
    pancreasSizeHeadSpin->setRange( 0, 300 );
    pancreasSizeHeadSpin->setSuffix( " мм" );
    pancreasSizeHeadSpin->clear();
    QSpinBox* pancreasSizeBodySpin = new QSpinBox;
    pancreasSizeBodySpin->setRange( 0, 300 );
    pancreasSizeBodySpin->setSuffix( " мм" );
    pancreasSizeBodySpin->clear();
    QSpinBox* pancreasSizeTailSpin = new QSpinBox;
    pancreasSizeTailSpin->setRange( 0, 300 );
    pancreasSizeTailSpin->setSuffix( " мм" );
    pancreasSizeTailSpin->clear();

    //Контуры
    QLabel* pancreasContourLabel = new QLabel( "Контуры: " );
    QRadioButton* pancreasContourStraight = new QRadioButton( "Ровные" );
    QRadioButton* pancreasContourNotStraight = new QRadioButton( "Неровные" );
    QRadioButton* pancreasContourHilly = new QRadioButton( "Бугристые" );
        //делаем независимыми c предыдущими радио-кнопками
    QButtonGroup* pancreasContourGroups = new QButtonGroup;
    pancreasContourGroups->addButton( pancreasContourStraight );
    pancreasContourGroups->addButton( pancreasContourNotStraight );
    pancreasContourGroups->addButton( pancreasContourHilly );
    pancreasContourGroups->setExclusive( true );

    //Эхоструктура
    QCheckBox* pancreasEchoCheck = new QCheckBox( "Эхоструктура: неоднородная" );
    pancreasEchoCheck->setFixedSize( 200, 20 );
    QObject::connect( pancreasEchoCheck, &QCheckBox::stateChanged,
                          [&] { if ( !( pancreasEchoCheck->isChecked() ) ) pancreasEchoCheck->setText("Эхоструктура: неоднородная");
                                if ( ( pancreasEchoCheck->isChecked() ) ) pancreasEchoCheck->setText("Эхоструктура: однородная");
                                });

    //Эхогенность
    QLabel* pancreasEchogenLabel = new QLabel( "Эхогенность: " );
    QRadioButton* pancreasEchogenUpRadio = new QRadioButton( "Повышена" );
    QRadioButton* pancreasEchogenDownRadio = new QRadioButton( "Понижена" );
    QRadioButton* pancreasEchogenMidRadio = new QRadioButton( "Средняя");
    QButtonGroup* pancreasEchogenGroups = new QButtonGroup;
    pancreasEchogenGroups->addButton( pancreasEchogenUpRadio );
    pancreasEchogenGroups->addButton( pancreasEchogenDownRadio );
    pancreasEchogenGroups->addButton( pancreasEchogenMidRadio );
    pancreasEchogenGroups->setExclusive( true );


    //Главный панкреатический проток
    QCheckBox* pancreasMainStreamCheck = new QCheckBox( "Главный панкреатический проток: не расширен" );
    pancreasMainStreamCheck->setFixedSize( 350, 20 );
    QObject::connect( pancreasMainStreamCheck, &QCheckBox::stateChanged,
                          [&] { if ( !( pancreasMainStreamCheck->isChecked() ) ) pancreasMainStreamCheck->setText( "Главный панкреатический проток: не расширен" );
                                if ( ( pancreasMainStreamCheck->isChecked() ) ) pancreasMainStreamCheck->setText( "Главный панкреатический проток:    расширен" );
                                });

    //Заключение
        QLabel* pancreasConclusionLabel = new QLabel( "ОПИСАНИЕ: " );
        QTextEdit* pancreasConclusionText = new QTextEdit;
        pancreasConclusionText->setFixedSize( 1200, 20 );

//СЕЛЕЗЕНКА
    QLabel* spleenLabel = new QLabel( "СЕЛЕЗЕНКА: " );

    //Положение:
    QLabel* spleenPlaceLabel = new QLabel( "Положение: " );

    //Форма
    QLabel* spleenFormLabel = new QLabel( "Форма: " );
    QRadioButton* spleenFormNormalRadio = new QRadioButton( "Обычная" );
    QButtonGroup* spleenFormGroup = new QButtonGroup;
    spleenFormGroup->addButton( spleenFormNormalRadio );
    spleenFormGroup->setExclusive( true );
    spleenFormNormalRadio->setChecked( true );

    //Размер
    QLineEdit* spleenSizeLine = new QLineEdit( " мм" );
    QLabel* spleenSizeLabel = new QLabel( "Размер: " );

    //Контуры
    QLabel* spleenContourLabel = new QLabel( "Контуры: " );
    QRadioButton* spleenContourStraight = new QRadioButton( "Ровные" );
    QRadioButton* spleenContourNotStraight = new QRadioButton( "Неровные" );
    QRadioButton* spleenContourHilly = new QRadioButton( "Бугристые" );
        //делаем независимыми c предыдущими радио-кнопками
    QButtonGroup* spleenContourGroups = new QButtonGroup;
    spleenContourGroups->addButton( spleenContourStraight );
    spleenContourGroups->addButton( spleenContourNotStraight );
    spleenContourGroups->addButton( spleenContourHilly );
    spleenContourGroups->setExclusive( true );

    //Эхоструктура
    QCheckBox* spleenEchoCheck = new QCheckBox( "Эхоструктура: неоднородная" );
    spleenEchoCheck->setFixedSize( 200, 20 );
    QObject::connect( spleenEchoCheck, &QCheckBox::stateChanged,
                          [&] { if ( !( spleenEchoCheck->isChecked() ) ) spleenEchoCheck->setText("Эхоструктура: неоднородная");
                                if ( ( spleenEchoCheck->isChecked() ) ) spleenEchoCheck->setText("Эхоструктура: однородная");
                                });

    //Эхогенность
    QLabel* spleenEchogenLabel = new QLabel( "Эхогенность: " );
    QRadioButton* spleenEchogenUpRadio = new QRadioButton( "Повышена" );
    QRadioButton* spleenEchogenDownRadio = new QRadioButton( "Понижена" );
    QRadioButton* spleenEchogenMidRadio = new QRadioButton( "Средняя");
    QButtonGroup* spleenEchogenGroups = new QButtonGroup;
    spleenEchogenGroups->addButton( spleenEchogenUpRadio );
    spleenEchogenGroups->addButton( spleenEchogenDownRadio );
    spleenEchogenGroups->addButton( spleenEchogenMidRadio );
    spleenEchogenGroups->setExclusive( true );

    //Селезеночная вена
    QCheckBox* spleenVenaCheck = new QCheckBox( "Селезеночная вена: не расширена" );
    spleenVenaCheck->setFixedSize( 350, 20 );
    QObject::connect( spleenVenaCheck, &QCheckBox::stateChanged,
                          [&] { if ( !( spleenVenaCheck->isChecked() ) ) spleenVenaCheck->setText( "Селезеночная вена: не расширена" );
                                if ( ( spleenVenaCheck->isChecked() ) ) spleenVenaCheck->setText( "Селезеночная вена:    расширена" );
                                });
    //Лимфатические узлы
    QCheckBox* spleenLimfaCheck = new QCheckBox( "Лимфатические узлы: не визуализируются" );
    spleenLimfaCheck->setFixedSize( 350, 20 );
    QObject::connect( spleenLimfaCheck, &QCheckBox::stateChanged,
                          [&] { if ( !( spleenLimfaCheck->isChecked() ) ) spleenLimfaCheck->setText( "Лимфатические узлы: не визуализируются" );
                                if ( ( spleenLimfaCheck->isChecked() ) ) spleenLimfaCheck->setText( "Лимфатические узлы:    визуализируются" );
                                });

    //Наличие свободной жидкости в брюшной полости
    QCheckBox* bellyWaterCheck = new QCheckBox( "НАЛИЧИЕ СВОБОДНОЙ ЖИДКОСТИ В БРЮШНОЙ ПОЛОСТИ: нет" );
    bellyWaterCheck->setFixedSize( 420, 20 );
    QObject::connect( bellyWaterCheck, &QCheckBox::stateChanged,
                          [&] { if ( !( bellyWaterCheck->isChecked() ) ) bellyWaterCheck->setText( "НАЛИЧИЕ СВОБОДНОЙ ЖИДКОСТИ В БРЮШНОЙ ПОЛОСТИ: нет" );
                                if ( ( bellyWaterCheck->isChecked() ) ) bellyWaterCheck->setText( "НАЛИЧИЕ СВОБОДНОЙ ЖИДКОСТИ В БРЮШНОЙ ПОЛОСТИ: есть" );
                                });

    //Заключение
    QLabel* spleenConclusionLabel = new QLabel( "ОПИСАНИЕ: " );
    QTextEdit* spleenConclusionText = new QTextEdit;
    spleenConclusionText->setFixedSize( 1200, 20 );

//ЗАКЛЮЧЕНИЕ
    QLabel* mainConclusionLabel = new QLabel( "ЗАКЛЮЧЕНИЕ: " );
    QTextEdit* mainConclusionText = new QTextEdit;
    mainConclusionText->setMaximumSize( 1400, 20 );
    mainConclusionText->setMinimumSize( 1200, 16 );
    //Шаблонные вставки
    QCheckBox* mainConclusionGepatomegCheck = new QCheckBox( "Гепатомегалия, " );
    QObject::connect( mainConclusionGepatomegCheck, &QCheckBox::stateChanged,
                      [&] { if ( ( mainConclusionGepatomegCheck->isChecked() ) ) mainConclusionText->setText( mainConclusionText->toPlainText() + "гепатомегалия, " );
                            if ( !( mainConclusionGepatomegCheck->isChecked() ) ) mainConclusionText->setText( mainConclusionText->toPlainText() );
                            });
    QCheckBox* mainConclusionDiffusalchangesLiverCheck = new QCheckBox( "Дифф. изменения печени" );
    QObject::connect( mainConclusionDiffusalchangesLiverCheck, &QCheckBox::stateChanged,
                      [&] { if ( ( mainConclusionDiffusalchangesLiverCheck->isChecked() ) ) mainConclusionText->setText( mainConclusionText->toPlainText() + "диффузные изменения печени по типу жирового гепатоза, " );
                            if ( !( mainConclusionDiffusalchangesLiverCheck->isChecked() ) ) mainConclusionText->setText( mainConclusionText->toPlainText() );
                            });
    QCheckBox* mainConclusionDiffusalchangesPancreasCheck = new QCheckBox( "Дифф. изменения поджел. железы" );
    QObject::connect( mainConclusionDiffusalchangesPancreasCheck, &QCheckBox::stateChanged,
                      [&] { if ( ( mainConclusionDiffusalchangesPancreasCheck->isChecked() ) ) mainConclusionText->setText( mainConclusionText->toPlainText() + "диффузные изменения поджелудочной железы, " );
                            if ( !( mainConclusionDiffusalchangesPancreasCheck->isChecked() ) ) mainConclusionText->setText( mainConclusionText->toPlainText() );
                            });
    QCheckBox* mainConclusionEchoFeaturesHoleCheck = new QCheckBox( "Эхо-призн. хр. калькул. холецистита" );
    QObject::connect( mainConclusionEchoFeaturesHoleCheck, &QCheckBox::stateChanged,
                      [&] { if ( ( mainConclusionEchoFeaturesHoleCheck->isChecked() ) ) mainConclusionText->setText( mainConclusionText->toPlainText() + "эхо-признаки хр. калькулезного холецистита, " );
                            if ( !( mainConclusionEchoFeaturesHoleCheck->isChecked() ) ) mainConclusionText->setText( mainConclusionText->toPlainText() );
                            });

    QPushButton* mainConclusionReturnButton = new QPushButton( "Cбросить текст" );
    mainConclusionReturnButton->setMinimumHeight( 20 );
    QObject::connect( mainConclusionReturnButton, &QPushButton::clicked,
                      [&]{ mainConclusionGepatomegCheck->setChecked( false );
                           mainConclusionDiffusalchangesLiverCheck->setChecked( false );
                           mainConclusionDiffusalchangesPancreasCheck->setChecked( false );
                           mainConclusionEchoFeaturesHoleCheck->setChecked( false );
                           mainConclusionText->clear();
                            });


//LAYOUT*******************************************************************
//*************************************************************************
    //QTabWidget* mainTabWidget = new QTabWidget;
    //mainTabWidget->addTab( &wgt, "Печень" );
    QGridLayout* mainLayout = new QGridLayout();

    QHBoxLayout* nameLayout = new QHBoxLayout;
    nameLayout->addWidget( labelName );
    nameLayout->addWidget( patientName );
    //labelName->setSizePolicy( QSizePolicy::Preferred, QSizePolicy::Expanding );
    //patientName->setSizePolicy( QSizePolicy::Preferred, QSizePolicy::Expanding );

    QHBoxLayout* ageLayout = new QHBoxLayout;
    ageLayout->addWidget( labelAge );
    ageLayout->addWidget( patientAge );

    QHBoxLayout* dateLayout = new QHBoxLayout;
    dateLayout->addWidget( labelDate );
    dateLayout->addWidget( researchDate );

    //Основной слой
    QFrame mainFrame;
    mainFrame.setFrameShape( QFrame::Box );
    mainLayout->addWidget( &mainFrame, gridX, gridY, 3, 3 );

    mainLayout->addLayout( nameLayout, gridX, 1);
    gridX++;
    mainLayout->addLayout( ageLayout, gridX, 1 );
    gridX++;
    mainLayout->addLayout( dateLayout, gridX, 1 );

    //Начало протокола:
    QFrame liverFrame;
    liverFrame.setFrameShape( QFrame::Box );
    QLabel* protocallLabel = new QLabel( "ПРОТОКОЛ УЛЬТРАЗВУКОВОГО ИССЛЕДОВАНИЯ ОРГАНОВ БРЮШНОЙ ПОЛОСТИ");
    QFont liverProtocallFont;
    liverProtocallFont.setBold( true );
    protocallLabel->setFont( liverProtocallFont );

    gridX++;
    mainLayout->addWidget( &liverFrame, gridX + 1, 1, 13, 3 );
    mainLayout->addWidget( protocallLabel, gridX, 1);
    //Заполняеая часть
    gridX++;
    mainLayout->addWidget( liverLabel, gridX, 1 );
    //Расположение печени
    QHBoxLayout* placeLayout = new QHBoxLayout;
    placeLayout->addWidget( placeLabel );
    placeLayout->addWidget( placeStdRadio );
    placeLayout->addWidget( placeLeftRadio );
    mainLayout->addLayout( placeLayout, ++gridX, 1, 1, 1);

    //Доли
    gridX++;
    gridX++;
    mainLayout->addWidget( leftShareCheck, gridX, 1 );
    gridX++;
    mainLayout->addWidget( rightShareCheck, gridX, 1 );
    //Толщина
    mainLayout->addWidget( thickLabel1, gridX - 1, 2 );
    mainLayout->addWidget( thickLabel2, gridX, 2 );
    mainLayout->addWidget( leftThickSpin, gridX - 1, 2 );
    leftThickSpin->setAutoFillBackground( true );
    mainLayout->addWidget( rightThickSpin, gridX, 2 );
    //Контур
    QHBoxLayout* contourLayout = new QHBoxLayout;
    gridX++;
    mainLayout->addLayout( contourLayout, gridX, 1, 1, 1 );
    contourLayout->addWidget( contourLabel );
    contourLayout->addWidget( contourStraight );
    contourLayout->addWidget( contourNotStraight );
    contourLayout->addWidget( contourHilly );
    //Эхоструктура
    mainLayout->addWidget( echoCheck, gridX, 2 );
    //Эхогенность
    gridX++;
    QHBoxLayout* echogenLayout = new QHBoxLayout;
    echogenLayout->addWidget( echogenLabel );
    echogenLayout->addWidget( echogenUpRadio );
    echogenLayout->addWidget( echogenMidRadio );
    echogenLayout->addWidget( echogenDownRadio );
    mainLayout->addLayout( echogenLayout, gridX, 1, 1, 1 );
    //Магистр. Ствол
    gridX++;
    QHBoxLayout* magHLayout = new QHBoxLayout;
    magHLayout->addWidget( magCheck );
    magHLayout->addWidget( magSpin );
    mainLayout->addLayout( magHLayout, gridX, 1, 1, 1 );
    //Скорость кровотока
    gridX++;
    QHBoxLayout* speedBloodLayout = new QHBoxLayout;
    speedBloodLayout->addWidget( speedBloodLabel );
    speedBloodLayout->addWidget( speedBloodUpRadio );
    speedBloodLayout->addWidget( speedBloodMidRadio );
    speedBloodLayout->addWidget( speedBloodDownRadio );
    mainLayout->addLayout( speedBloodLayout, gridX, 1, 1, 1 );
    //Печеночные вены
    mainLayout->addWidget( hepaticCheck, ++gridX, 1 );
    //Нижняя полая вена
    QHBoxLayout* downVenaHLayout = new QHBoxLayout;
    downVenaHLayout->addWidget( downVenaCheck );
    downVenaHLayout->addWidget( downVenaSpin );
    mainLayout->addLayout( downVenaHLayout, ++gridX, 1, 1, 1 );
    //Внутрипеченочные желчные протоки
    mainLayout->addWidget( inhepaticCheck, ++gridX, 1 );
    //Общий желчный проток
    QHBoxLayout* commonBileHLayout = new QHBoxLayout;
    commonBileHLayout->addWidget( commonBileCheck );
    commonBileHLayout->addWidget( commonBileSpin );
    commonBileHLayout->addWidget( commonBileCheck2 );
    mainLayout->addLayout( commonBileHLayout, ++gridX, 1, 1, 2 );
    //Заключение
    QHBoxLayout* liverConclusionLayout = new QHBoxLayout;
    liverConclusionLayout->addWidget( liverConclusionLabel );
    liverConclusionLayout->addWidget( liverConclusionText );
    mainLayout->addLayout( liverConclusionLayout, ++gridX, 1 );


    //ЖЕЛЧНЫЙ ПУЗЫРЬ
    QFrame* gallbladerFrame = new QFrame;
    gallbladerFrame->setFrameShape( QFrame::Box );
    mainLayout->addWidget( gallbladerFrame, ++gridX, 1, 6, 3 );
    mainLayout->addWidget( gallbladerLabel, gridX, 1);
    //Размер
    QHBoxLayout* gallbladerSizeLayout = new QHBoxLayout;
    gallbladerSizeLayout->addWidget( gallbladerSizeLabel );
    gallbladerSizeLayout->addWidget( gallbladerSizeLine );
    mainLayout->addLayout( gallbladerSizeLayout, ++gridX, 1 );
    //Деформация
    QHBoxLayout* gallbladerDeformationLayout = new QHBoxLayout;
    gallbladerDeformationLayout->addWidget( gallbladerDeformationLabel );
    gallbladerDeformationLayout->addWidget( gallbladerDeformationNeckCheck );
    gallbladerDeformationLayout->addWidget( gallbladerDeformationBodyCheck );
    gallbladerDeformationLayout->addWidget( gallbladerDeformationBottomCheck );
    mainLayout->addLayout( gallbladerDeformationLayout, ++gridX, 1 );
    //Стенки
    QHBoxLayout* gallbladerWallLayout = new QHBoxLayout;
    gallbladerWallSpin->setSuffix(" мм");
    gallbladerWallSpin->setRange( 0, 300 );
    gallbladerWallSpin->clear();
    gallbladerWallLayout->addWidget( gallbladerWallLabel );
    gallbladerWallLayout->addWidget( gallbladerWallSpin );
    mainLayout->addLayout( gallbladerWallLayout, ++gridX, 1 );
    //Содержимое
    mainLayout->addWidget( gallbladerContentCheck, ++gridX, 1 );
    //Конкременты
    mainLayout->addWidget( gallbladerConcrementsCheck, ++gridX, 1 );
    //Заключение
    QHBoxLayout* gallbladerConclusionLayout = new QHBoxLayout;
    gallbladerConclusionLayout->addWidget( gallbladerConclusionLabel );
    gallbladerConclusionLayout->addWidget( gallbladerConclusionText );
    mainLayout->addLayout( gallbladerConclusionLayout, ++gridX, 1 );

 //ПОДЖЕЛУДОЧНАЯ ЖЕЛЕЗА
    QFrame* pancreasFrame = new QFrame;
    pancreasFrame->setFrameShape( QFrame::Box );
    mainLayout->addWidget( pancreasFrame, ++gridX, 1, 5, 3 );
    mainLayout->addWidget( pancreasLabel, gridX, 1 );
    //Размеры:
    QHBoxLayout* pancreasSizeLayout = new QHBoxLayout;
    pancreasSizeLayout->addWidget( pancreasSizeHeadLabel );
    pancreasSizeLayout->addWidget( pancreasSizeHeadSpin );
    pancreasSizeLayout->addWidget( pancreasSizeBodyLabel );
    pancreasSizeLayout->addWidget( pancreasSizeBodySpin );
    pancreasSizeLayout->addWidget( pancreasSizeTailLabel );
    pancreasSizeLayout->addWidget( pancreasSizeTailSpin );
    mainLayout->addLayout( pancreasSizeLayout, ++gridX, 1, 1, 2 );
    //Контуры
    QHBoxLayout* pancreasContourLayout = new QHBoxLayout;
    mainLayout->addLayout( pancreasContourLayout, ++gridX, 1, 1, 1 );
    pancreasContourLayout->addWidget( pancreasContourLabel );
    pancreasContourLayout->addWidget( pancreasContourStraight );
    pancreasContourLayout->addWidget( pancreasContourNotStraight );
    pancreasContourLayout->addWidget( pancreasContourHilly );
    //Эхоструктура
    mainLayout->addWidget( pancreasEchoCheck, gridX, 2 );
    //Эхогенность
    QHBoxLayout* pancreasEchogenLayout = new QHBoxLayout;
    pancreasEchogenLayout->addWidget( pancreasEchogenLabel );
    pancreasEchogenLayout->addWidget( pancreasEchogenUpRadio );
    pancreasEchogenLayout->addWidget( pancreasEchogenMidRadio );
    pancreasEchogenLayout->addWidget( pancreasEchogenDownRadio );
    mainLayout->addLayout( pancreasEchogenLayout, ++gridX, 1, 1, 1 );
    //Главный панкреатический проток
     mainLayout->addWidget( pancreasMainStreamCheck, ++gridX, 1 );
    //Заключение
     QHBoxLayout* pancreasConclusionLayout = new QHBoxLayout;
     pancreasConclusionLayout->addWidget( pancreasConclusionLabel );
     pancreasConclusionLayout->addWidget( pancreasConclusionText );
     mainLayout->addLayout( pancreasConclusionLayout, ++gridX, 1 );

//СЕЛЕЗЕНКА
     QFrame* spleenFrame = new QFrame;
     spleenFrame->setFrameShape( QFrame::Box );
     mainLayout->addWidget( spleenFrame, ++gridX, 1, 7, 3 );
     mainLayout->addWidget( spleenLabel, gridX, 1);
     //Положение
     //mainLayout->addWidget( spleenPlaceLabel, ++gridX, 1 );
    //Форма
     QHBoxLayout* spleenFormLayout = new QHBoxLayout;
     spleenFormLayout->addWidget( spleenFormLabel );
     spleenFormLayout->addWidget( spleenFormNormalRadio );
     mainLayout->addLayout( spleenFormLayout, ++gridX, 1 );
     //Размер
     QHBoxLayout* spleenSizeLayout = new QHBoxLayout;
     spleenSizeLayout->addWidget( spleenSizeLabel );
     spleenSizeLayout->addWidget( spleenSizeLine );
     mainLayout->addLayout( spleenSizeLayout, ++gridX, 1 );
     //Контур
     QHBoxLayout* spleenContourLayout = new QHBoxLayout;
     mainLayout->addLayout( spleenContourLayout, ++gridX, 1, 1, 1 );
     spleenContourLayout->addWidget( spleenContourLabel );
     spleenContourLayout->addWidget( spleenContourStraight );
     spleenContourLayout->addWidget( spleenContourNotStraight );
     spleenContourLayout->addWidget( spleenContourHilly );
     //Эхоструктура
     mainLayout->addWidget( spleenEchoCheck, gridX, 2 );
     //Эхогенность
     QHBoxLayout* spleenEchogenLayout = new QHBoxLayout;
     spleenEchogenLayout->addWidget( spleenEchogenLabel );
     spleenEchogenLayout->addWidget( spleenEchogenUpRadio );
     spleenEchogenLayout->addWidget( spleenEchogenMidRadio );
     spleenEchogenLayout->addWidget( spleenEchogenDownRadio );
     mainLayout->addLayout( spleenEchogenLayout, ++gridX, 1, 1, 1 );
     //Селезеночная вена
     mainLayout->addWidget( spleenVenaCheck, ++gridX, 1 );
     //Лимфатические узлы
     mainLayout->addWidget( spleenLimfaCheck, gridX - 1, 2 );
     //Наличие свободной жидкости в брюшной полости
     mainLayout->addWidget( bellyWaterCheck, ++gridX, 1 );
    //Заключение
     QHBoxLayout* spleenConclusionLayout = new QHBoxLayout;
     spleenConclusionLayout->addWidget( spleenConclusionLabel );
     spleenConclusionLayout->addWidget( spleenConclusionText );
     mainLayout->addLayout( spleenConclusionLayout, ++gridX, 1 );

//ЗАКЛЮЧЕНИЕ:
     mainLayout->addWidget( mainConclusionLabel, ++gridX, 1 );
     mainLayout->addWidget( mainConclusionText, ++gridX, 1 );
     //Шаблонные вставки
     QGridLayout* mainConclusionPatternsLayout = new QGridLayout;
     mainConclusionPatternsLayout->addWidget( mainConclusionGepatomegCheck, 1, 1 );
     mainConclusionGepatomegCheck->setMinimumHeight( 15 );
     mainConclusionPatternsLayout->addWidget( mainConclusionDiffusalchangesLiverCheck, 1, 2 );
     mainConclusionDiffusalchangesLiverCheck->setMinimumHeight( 15 );
     mainConclusionPatternsLayout->addWidget( mainConclusionDiffusalchangesPancreasCheck, 2, 1 );
     mainConclusionDiffusalchangesPancreasCheck->setMinimumHeight( 15 );
     mainConclusionPatternsLayout->addWidget( mainConclusionEchoFeaturesHoleCheck, 2, 2 );
     mainConclusionEchoFeaturesHoleCheck->setMinimumHeight( 15 );
     mainConclusionPatternsLayout->addWidget( mainConclusionReturnButton, 3, 2 );

     mainLayout->addLayout( mainConclusionPatternsLayout, ++gridX, 1 );
     mainLayout->setMargin( 10 );
     mainLayout->setSpacing( 1 );

     //Связь с Документом word

         //Сохранить изменения
             QPushButton* liverSaveAllButton = new QPushButton( "Сохранить документ" );
             //wordSave* liverSaveAllClass = new wordSave;

             QObject::connect( liverSaveAllButton, &QPushButton::clicked,
                               [&] {
                                         QAxObject* pWord = new QAxObject( "Word.Application" );
                                         QAxObject* pDocs = pWord->querySubObject( "Documents" );

                                         QString dirDocLiver = QCoreApplication::applicationDirPath() + "/template/uziLiver.docx";

                                         pDocs->dynamicCall( "Add([Template], [NewTemplate], [DocumentType], [Visible])", dirDocLiver );

                                         pWord->setProperty( "DiplayAlerts()", false );

                                         //QAxObject* pActiveDoc = pWord->querySubObject( "ActiveDocument()" );
                                         pWord->setProperty( "DiplayAlerts()", false );

                                         //qint32 liverWordPlace = 0;
                                         //Имя пациента
                                         replaceString( pWord, "patientName", patientName->text() );

                                         //Год рождения и дата исследования
                                         replaceString( pWord, "patientAge", patientAge->text() );
                                         replaceString( pWord, "Date", researchDate->text() );

                                         //ПЕЧЕНЬ
                                            //Расположение Печени

                                             if ( placeStdRadio->isChecked() ) {
                                                 replaceString( pWord, "liverPlace", "обычно" );
                                             }
                                             else {
                                                 replaceString( pWord, "liverPlace", "слева" );
                                             }

                                             //Левая и правая доли
                                             if ( leftShareCheck->isChecked() ) {
                                                 replaceString( pWord, "leftShare", "   увеличена" );
                                             }
                                             else {
                                                 replaceString( pWord, "leftShare", "не увеличена" );
                                             }
                                             if ( rightShareCheck->isChecked() ) {
                                                 replaceString( pWord, "rightShare", "   увеличена" );
                                             }
                                             else {
                                                 replaceString( pWord, "rightShare", "не увеличена" );
                                             }
                                             //Толщина Долей
                                             replaceString( pWord, "leftThick" , leftThickSpin->text() );
                                             replaceString( pWord, "rightThick" , rightThickSpin->text() );

                                             //Контуры
                                             if ( contourStraight->isChecked() ) {
                                                 replaceString( pWord, "liverContour", "ровные" );
                                             }
                                             else if ( contourNotStraight->isChecked() ) {
                                                 replaceString( pWord, "liverContour", "неровные" );
                                             }
                                             else {
                                                 replaceString( pWord, "liverContour", "бугристые" );
                                             }

                                             //Эхоструктура и Эхогенность
                                             if ( echoCheck->isChecked() ) replaceString( pWord, "liverEchoStructure", "однородная" );
                                             else replaceString( pWord, "liverEchoStructure", "неоднородная" );
                                             if ( echogenUpRadio->isChecked() ) replaceString( pWord, "liverEcho", echogenUpRadio->text() );
                                             else if ( echogenMidRadio->isChecked() ) replaceString( pWord, "liverEcho", echogenMidRadio->text() );
                                             else replaceString( pWord, "liverEcho", echogenDownRadio->text() );

                                             //Магистральные ствол воротной вены
                                             replaceString( pWord, "liverMagCheck", magCheck->text() );
                                             replaceString( pWord, "liverMagSpin", magSpin->text() );

                                             //Скорость кровотока
                                             if ( speedBloodUpRadio->isChecked() )
                                                replaceString( pWord, "liverSpeedBloodRadio", "Высокая");
                                             else if ( speedBloodMidRadio->isChecked() )
                                                 replaceString( pWord, "liverSpeedBloodRadio", "Нормальная" );
                                             else
                                                 replaceString( pWord, "liverSpeedBloodRadio", "Низкая" );

                                             //Печеночные вены, Нижняя вена, желчные потоки
                                             replaceString( pWord, "liverHepaticCheck", hepaticCheck->text() );
                                             replaceString( pWord, "liverDownVenaCheck", downVenaCheck->text() );
                                             replaceString( pWord, "liverDownVenaSpin", downVenaSpin->text() );
                                             replaceString( pWord, "liverInHepaticCheck", inhepaticCheck->text() );

                                             //Общий желчный проток
                                             replaceString( pWord, "liverCommonBileCheck", commonBileCheck->text() );
                                             replaceString( pWord, "liverCommonBileSpin", commonBileSpin->text() );
                                             replaceString( pWord, "liverCommonBile2Check", commonBileCheck2->text() );

                                             //Описание
                                             replaceString( pWord, "liverDescriptionText", liverConclusionText->toPlainText() );
                                        //Желчный пузырь:
                                             //Размер и деформация
                                             replaceString( pWord, "gallbladerSizeLine", gallbladerSizeLine->text() );
                                             replaceString( pWord, "gallbladerDeformationCheck", gallbladerDeformationNeckCheck->text() + gallbladerDeformationBodyCheck->text() + gallbladerDeformationBottomCheck->text() );

                                             //Стенки и Содержимое, конкременты
                                             replaceString( pWord, "gallbladerWallSpin", gallbladerWallSpin->text() );
                                             replaceString( pWord, "gallbladerContentCheck", gallbladerContentCheck->text() );
                                             replaceString( pWord, "gallbladerConcrementsCheck", gallbladerConcrementsCheck->text() );

                                             //Описание
                                             replaceString( pWord, "gallbladerDescriptionText", gallbladerConclusionText->toPlainText() );

                                        //Поджелудочная железа
                                             replaceString( pWord, "pancreasSizeHeadSpin", pancreasSizeHeadSpin->text() );
                                             replaceString( pWord, "pancreasSizeBodySpin", pancreasSizeBodySpin->text() );
                                             replaceString( pWord, "pancreasSizeTailSpin", pancreasSizeTailSpin->text() );
                                             if ( pancreasContourStraight->isChecked() )
                                                replaceString( pWord, "pancreasContourRadio", pancreasContourStraight->text() );
                                             else if ( pancreasContourNotStraight->isChecked() )
                                                replaceString( pWord, "pancreasContourRadio", pancreasContourNotStraight->text() );
                                             else
                                                 replaceString( pWord, "pancreasContourRadio", pancreasContourHilly->text() );
                                             //Эхоструктура
                                             replaceString( pWord, "pancreasEchoCheck", pancreasEchoCheck->text() );

                                             //Эхогенность
                                             if ( pancreasEchogenUpRadio->isChecked() ) replaceString( pWord, "pancreasEchogenRadio", pancreasEchogenUpRadio->text() );
                                             else if ( pancreasEchogenMidRadio->isChecked() ) replaceString( pWord, "pancreasEchogenRadio", pancreasEchogenMidRadio->text() );
                                             else replaceString( pWord, "pancreasEchogenRadio", pancreasEchogenDownRadio->text() );

                                             //Главный панкреатический проток
                                             replaceString( pWord, "pancreasMainStreamCheck", pancreasMainStreamCheck->text() );
                                             //Описание
                                             replaceString( pWord, "pancreasDescriptionText", pancreasConclusionText->toPlainText() );

                                         //Селезенка
                                             //Положение

                                             //Форма
                                             replaceString( pWord, "spleenFormRadio", spleenFormNormalRadio->text() );
                                             //Размеры, контуры, эхогенность, эхоструктура
                                             replaceString( pWord, "spleenSizeLine", spleenSizeLine->text() );
                                             if ( spleenContourStraight->isChecked() ) {
                                                 replaceString( pWord, "spleenContourRadio", "ровные" );
                                             }
                                             else if ( spleenContourNotStraight->isChecked() ) {
                                                 replaceString( pWord, "spleenContourRadio", "неровные" );
                                             }
                                             else {
                                                 replaceString( pWord, "spleenContourRadio", "бугристые" );
                                             }
                                             if ( spleenEchogenUpRadio->isChecked() ) replaceString( pWord, "spleenEchogenRadio", spleenEchogenUpRadio->text() );
                                             else if ( spleenEchogenMidRadio->isChecked() ) replaceString( pWord, "spleenEchogenRadio", spleenEchogenMidRadio->text() );
                                             else replaceString( pWord, "spleenEchogenRadio", spleenEchogenDownRadio->text() );
                                             replaceString( pWord, "spleenEchoCheck", spleenEchoCheck->text() );

                                             //Вена, Лимфоузлы,
                                             replaceString( pWord, "spleenVenaCheck", spleenVenaCheck->text() );
                                             replaceString( pWord, "spleenLimfaCheck", spleenLimfaCheck->text() );
                                             replaceString( pWord, "bellyWaterCheck", bellyWaterCheck->text() );

                                             //Заключение:
                                             replaceString( pWord, "spleenDescriptionText", spleenConclusionText->toPlainText() );

                                         //ОСНОВНОЕ ЗАКЛЮЧЕНИЕ
                                            replaceString( pWord, "mainConclusionText", mainConclusionText->toPlainText() );



                                         pWord->setProperty( "Visible", true );
                                   }  );
         //Сохранить документ LAYOUT
              mainLayout->addWidget( liverSaveAllButton, ++gridX, 2 );

     //Создание шрифта для всего Виджета
              QFont widgetFont;
              widgetFont.setPixelSize( 12 );

     wgt.setFont( widgetFont );
     wgt.setLayout( mainLayout );
     wgt.resize( 600, 800 );
     //mainTabWidget->show();
    wgt.show();
    return a.exec();

}

void replaceString( QAxObject* pActiveDoc, const QString& oldString, const QString& newString)
{
  QAxObject* WordSelection = pActiveDoc->querySubObject("Selection");

  QAxObject* Find = WordSelection->querySubObject("Find");
  if (!Find) return;
  Find->dynamicCall("ClearFormatting()");

  QList<QVariant> params;
  params.operator << (QVariant(oldString));
  params.operator << (QVariant("0"));
  params.operator << (QVariant("0"));
  params.operator << (QVariant("0"));
  params.operator << (QVariant("0"));
  params.operator << (QVariant("0"));
  params.operator << (QVariant(true));
  params.operator << (QVariant("0"));
  params.operator << (QVariant("0"));
  params.operator << (QVariant(newString));
  params.operator << (QVariant("2"));
  params.operator << (QVariant("0"));
  params.operator << (QVariant("0"));
  params.operator << (QVariant("0"));
  params.operator << (QVariant("0"));
  Find->dynamicCall("Execute(const QVariant&,const QVariant&,"
                    "const QVariant&,const QVariant&,"
                    "const QVariant&,const QVariant&,"
                    "const QVariant&,const QVariant&,"
                    "const QVariant&,const QVariant&,"
                    "const QVariant&,const QVariant&,"
                    "const QVariant&,const QVariant&,const QVariant&)",
                    params);

}



