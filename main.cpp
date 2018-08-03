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
    QVBoxLayout* placeLayout = new QVBoxLayout;
    placeLayout->addWidget( placeLabel );
    placeLayout->addWidget( placeStdRadio );
    placeLayout->addWidget( placeLeftRadio );

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
    commonBileSpin->setSuffix( " мм" );
    commonBileSpin->clear();
    QCheckBox* commonBileCheck2 = new QCheckBox( " стенки: не утолщены");
    QObject::connect( commonBileCheck2, &QCheckBox::stateChanged,
                      [&] { if ( !( commonBileCheck2->isChecked() ) ) commonBileCheck2->setText(" стенки: не утолщены");
                            if ( ( commonBileCheck2->isChecked() ) ) commonBileCheck2->setText(" стенки:     утолщены");
                            });


//ЖЕЛЧНЫЙ ПУЗЫРЬ
    QLabel* gallbladerLabel = new QLabel( " ЖЕЛЧНЫЙ ПУЗЫРЬ: " );

    //Размер
    QSpinBox* gallbladerSizeSpin = new QSpinBox;
    QLabel* gallbladerSizeLabel = new QLabel( "Размер: " );

    //Деформация

    //Стенки
    QSpinBox* gallbladerWallSpin = new QSpinBox;
    QLabel* gallbladerWallLabel = new QLabel( "Стенки: " );

    //Содержимое
    QCheckBox* gallbladedContentCheck = new QCheckBox( "Содержимое: неоднородное" );
    gallbladedContentCheck->setFixedSize( 230, 20 );
    QObject::connect( gallbladedContentCheck, &QCheckBox::stateChanged,
                          [&] { if ( !( gallbladedContentCheck->isChecked() ) ) gallbladedContentCheck->setText("Содержимое: неоднородное" );
                                if ( ( gallbladedContentCheck->isChecked() ) ) gallbladedContentCheck->setText("Содержимое:   однородное" );
                                });

    //Конкременты
    QCheckBox* gallbladerConcrementsCheck = new QCheckBox( "Конкременты: не визуализируются" );
    gallbladerConcrementsCheck->setFixedSize( 230, 20 );
    QObject::connect( gallbladerConcrementsCheck, &QCheckBox::stateChanged,
                          [&] { if ( !( gallbladerConcrementsCheck->isChecked() ) ) gallbladerConcrementsCheck->setText( "Конкременты: не визуализируются" );
                                if ( ( gallbladerConcrementsCheck->isChecked() ) ) gallbladerConcrementsCheck->setText( "Конкременты:    визуализируются" );
                                });


//ПОДЖЕЛУДОЧНАЯ ЖЕЛЕЗА
    QLabel* pancreasLabel = new QLabel( "ПОДЖЕЛУДОЧНАЯ ЖЕЛЕЗА: визуализируется. Положение: типичное" );

    //Размеры
    QLabel* pancreasSizeHeadLabel = new QLabel( "Размер: головки:" );
    QLabel* pancreasSizeBodyLabel = new QLabel( ", тела:" );
    QLabel* pancreasSizeTailLabel = new QLabel( ", хвоста:" );
    QSpinBox* pancreasSizeHeadSpin = new QSpinBox;
    pancreasSizeHeadSpin->setSuffix( " мм" );
    pancreasSizeHeadSpin->clear();
    QSpinBox* pancreasSizeBodySpin = new QSpinBox;
    pancreasSizeBodySpin->setSuffix( " мм" );
    pancreasSizeBodySpin->clear();
    QSpinBox* pancreasSizeTailSpin = new QSpinBox;
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

    //Главный панкреатический проток
    QCheckBox* pancreasMainStreamCheck = new QCheckBox( "Главный панкреатический проток: не расширен" );
    pancreasMainStreamCheck->setFixedSize( 350, 20 );
    QObject::connect( pancreasMainStreamCheck, &QCheckBox::stateChanged,
                          [&] { if ( !( pancreasMainStreamCheck->isChecked() ) ) pancreasMainStreamCheck->setText( "Главный панкреатический проток: не расширен" );
                                if ( ( pancreasMainStreamCheck->isChecked() ) ) pancreasMainStreamCheck->setText( "Главный панкреатический проток:    расширен" );
                                });

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

    //Размер
    QSpinBox* spleenSizeSpin = new QSpinBox;
    spleenSizeSpin->setSuffix( " мм" );
    spleenSizeSpin->clear();
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
    QLabel* bellyConclusionLabel = new QLabel( "ЗАКЛЮЧЕНИЕ: " );
    QTextEdit* bellyConclusionText = new QTextEdit;
    bellyConclusionText->setMinimumSize( 900, 30 );

//LAYOUT
    QGridLayout* mainLayout = new QGridLayout();

    QHBoxLayout* nameLayout = new QHBoxLayout;
    nameLayout->addWidget( labelName );
    nameLayout->addWidget( patientName );
    labelName->setSizePolicy( QSizePolicy::Preferred, QSizePolicy::Expanding );
    patientName->setSizePolicy( QSizePolicy::Preferred, QSizePolicy::Expanding );

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
    QFrame liverFrame;
    liverFrame.setFrameShape( QFrame::Box );
    QLabel* protocallLabel = new QLabel( "\t\t\t ПРОТОКОЛ \n ультразвукогого исследования органов брюшной полости");


    mainLayout->addWidget( &liverFrame, 4, 1, 14, 3 );
    mainLayout->addWidget( protocallLabel, 4, 1);
    //Заполняеая часть
    mainLayout->addWidget( liverLabel, 5, 1 );
    //Расположение печени
    mainLayout->addLayout( placeLayout, 5, 2, 2, 1);
    //Доли
    mainLayout->addWidget( leftShareCheck, 8, 1 );
    mainLayout->addWidget( rightShareCheck, 9, 1 );
    //Толщина
    mainLayout->addWidget( thickLabel1, 8, 2 );
    mainLayout->addWidget( thickLabel2, 9, 2 );
    mainLayout->addWidget( leftThickSpin, 8, 3 );
    mainLayout->addWidget( rightThickSpin, 9, 3 );
    //Контур
    QHBoxLayout* contourLayout = new QHBoxLayout;
    mainLayout->addLayout( contourLayout, 10, 1, 1, 1 );
    contourLayout->addWidget( contourLabel );
    contourLayout->addWidget( contourStraight );
    contourLayout->addWidget( contourNotStraight );
    contourLayout->addWidget( contourHilly );
    //Эхоструктура
    mainLayout->addWidget( echoCheck, 10, 2 );
    //Эхогенность
    QHBoxLayout* echogenLayout = new QHBoxLayout;
    echogenLayout->addWidget( echogenLabel );
    echogenLayout->addWidget( echogenUpRadio );
    echogenLayout->addWidget( echogenMidRadio );
    echogenLayout->addWidget( echogenDownRadio );
    mainLayout->addLayout( echogenLayout, 11, 1, 1, 1 );
    //Магистр. Ствол
    QHBoxLayout* magHLayout = new QHBoxLayout;
    magHLayout->addWidget( magCheck );
    magHLayout->addWidget( magSpin );
    mainLayout->addLayout( magHLayout, 12, 1, 1, 1 );
    //Скорость кровотока
    QHBoxLayout* speedBloodLayout = new QHBoxLayout;
    speedBloodLayout->addWidget( speedBloodLabel );
    speedBloodLayout->addWidget( speedBloodUpRadio );
    speedBloodLayout->addWidget( speedBloodMidRadio );
    speedBloodLayout->addWidget( speedBloodDownRadio );
    mainLayout->addLayout( speedBloodLayout, 13, 1, 1, 1 );
    //Печеночные вены
    mainLayout->addWidget( hepaticCheck, 14, 1 );
    //Нижняя полая вена
    QHBoxLayout* downVenaHLayout = new QHBoxLayout;
    downVenaHLayout->addWidget( downVenaCheck );
    downVenaHLayout->addWidget( downVenaSpin );
    mainLayout->addLayout( downVenaHLayout, 15, 1, 1, 1 );
    //Внутрипеченочные желчные протоки
    mainLayout->addWidget( inhepaticCheck, 16, 1 );
    //Общий желчный проток
    QHBoxLayout* commonBileHLayout = new QHBoxLayout;
    commonBileHLayout->addWidget( commonBileCheck );
    commonBileHLayout->addWidget( commonBileSpin );
    commonBileHLayout->addWidget( commonBileCheck2 );
    mainLayout->addLayout( commonBileHLayout, 17, 1, 1, 2 );


    //ЖЕЛЧНЫЙ ПУЗЫРЬ
    QFrame* gallbladerFrame = new QFrame;
    gallbladerFrame->setFrameShape( QFrame::Box );
    mainLayout->addWidget( gallbladerFrame, 18, 1, 5, 3 );
    mainLayout->addWidget( gallbladerLabel, 18, 1);
    //Размер
    QHBoxLayout* gallbladerSizeLayout = new QHBoxLayout;
    gallbladerSizeSpin->setSuffix(" мм");
    gallbladerSizeSpin->setRange( 0, 300 );
    gallbladerSizeSpin->clear();
    gallbladerSizeLayout->addWidget( gallbladerSizeLabel );
    gallbladerSizeLayout->addWidget( gallbladerSizeSpin );
    mainLayout->addLayout( gallbladerSizeLayout, 19, 1 );
    //Стенки
    QHBoxLayout* gallbladerWallLayout = new QHBoxLayout;
    gallbladerWallSpin->setSuffix(" мм");
    gallbladerWallSpin->setRange( 0, 300 );
    gallbladerWallSpin->clear();
    gallbladerWallLayout->addWidget( gallbladerWallLabel );
    gallbladerWallLayout->addWidget( gallbladerWallSpin );
    mainLayout->addLayout( gallbladerWallLayout, 20, 1 );
    //Содержимое
    mainLayout->addWidget( gallbladedContentCheck, 21, 1 );
    //Конкременты
    mainLayout->addWidget( gallbladerConcrementsCheck, 22, 1 );

    //ПОДЖЕЛУДОЧНАЯ ЖЕЛЕЗА
    QFrame* pancreasFrame = new QFrame;
    pancreasFrame->setFrameShape( QFrame::Box );
    mainLayout->addWidget( pancreasFrame, 23, 1, 4, 3 );
    mainLayout->addWidget( pancreasLabel, 23, 1 );
    //Размеры:
    QHBoxLayout* pancreasSizeLayout = new QHBoxLayout;
    pancreasSizeLayout->addWidget( pancreasSizeHeadLabel );
    pancreasSizeLayout->addWidget( pancreasSizeHeadSpin );
    pancreasSizeLayout->addWidget( pancreasSizeBodyLabel );
    pancreasSizeLayout->addWidget( pancreasSizeBodySpin );
    pancreasSizeLayout->addWidget( pancreasSizeTailLabel );
    pancreasSizeLayout->addWidget( pancreasSizeTailSpin );
    mainLayout->addLayout( pancreasSizeLayout, 24, 1, 1, 2 );
    //Контуры
    QHBoxLayout* pancreasContourLayout = new QHBoxLayout;
    mainLayout->addLayout( pancreasContourLayout, 25, 1, 1, 1 );
    pancreasContourLayout->addWidget( pancreasContourLabel );
    pancreasContourLayout->addWidget( pancreasContourStraight );
    pancreasContourLayout->addWidget( pancreasContourNotStraight );
    pancreasContourLayout->addWidget( pancreasContourHilly );
    //Эхоструктура
    mainLayout->addWidget( pancreasEchoCheck, 25, 2 );
    //Эхогенность
    QHBoxLayout* pancreasEchogenLayout = new QHBoxLayout;
    pancreasEchogenLayout->addWidget( pancreasEchogenLabel );
    pancreasEchogenLayout->addWidget( pancreasEchogenUpRadio );
    pancreasEchogenLayout->addWidget( pancreasEchogenMidRadio );
    pancreasEchogenLayout->addWidget( pancreasEchogenDownRadio );
    mainLayout->addLayout( pancreasEchogenLayout, 26, 1, 1, 1 );
    //Главный панкреатический проток
     mainLayout->addWidget( pancreasMainStreamCheck, 27, 1 );

//СЕЛЕЗЕНКА
     QFrame* spleenFrame = new QFrame;
     spleenFrame->setFrameShape( QFrame::Box );
     mainLayout->addWidget( spleenFrame, 28, 1, 6, 3 );
     mainLayout->addWidget( spleenLabel, 28, 1);
     //Положение
     mainLayout->addWidget( spleenPlaceLabel, 29, 1 );
    //Форма
     QHBoxLayout* spleenFormLayout = new QHBoxLayout;
     spleenFormLayout->addWidget( spleenFormLabel );
     spleenFormLayout->addWidget( spleenFormNormalRadio );
     mainLayout->addLayout( spleenFormLayout, 30, 1 );
     //Размер
     QHBoxLayout* spleenSizeLayout = new QHBoxLayout;
     spleenSizeLayout->addWidget( spleenSizeLabel );
     spleenSizeLayout->addWidget( spleenSizeSpin );
     mainLayout->addLayout( spleenSizeLayout, 31, 1 );
     //Контур
     QHBoxLayout* spleenContourLayout = new QHBoxLayout;
     mainLayout->addLayout( spleenContourLayout, 32, 1, 1, 1 );
     spleenContourLayout->addWidget( spleenContourLabel );
     spleenContourLayout->addWidget( spleenContourStraight );
     spleenContourLayout->addWidget( spleenContourNotStraight );
     spleenContourLayout->addWidget( spleenContourHilly );
     //Эхоструктура
     mainLayout->addWidget( spleenEchoCheck, 32, 2 );
     //Эхогенность
     QHBoxLayout* spleenEchogenLayout = new QHBoxLayout;
     spleenEchogenLayout->addWidget( spleenEchogenLabel );
     spleenEchogenLayout->addWidget( spleenEchogenUpRadio );
     spleenEchogenLayout->addWidget( spleenEchogenMidRadio );
     spleenEchogenLayout->addWidget( spleenEchogenDownRadio );
     mainLayout->addLayout( spleenEchogenLayout, 33, 1, 1, 1 );
     //Селезеночная вена
     mainLayout->addWidget( spleenVenaCheck, 34, 1 );
     //Лимфатические узлы
     mainLayout->addWidget( spleenLimfaCheck, 34, 2 );
     //Наличие свободной жидкости в брюшной полости
     mainLayout->addWidget( bellyWaterCheck, 35, 1 );

//Заключение
     mainLayout->addWidget( bellyConclusionLabel, 36, 1 );
     mainLayout->addWidget( bellyConclusionText, 37, 1 );


    wgt.setLayout( mainLayout );
    wgt.setMinimumSize( 900, 1000 );
    wgt.show();


    return a.exec();
}
