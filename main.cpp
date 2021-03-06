#include "formofliver.h"
#include <QtWidgets>
#include <QLineEdit>
#include <QFrame>
#include <QDebug>
#include <QAxObject>
#include <QAxBase>
#include <kidneys.cpp>
#include <thyroid.cpp>
#include <mammary.cpp>
#include "patient.h"
#include "newpatientform.h"

//#include "livercheck.h"
void replaceString(QAxObject* pActiveDoc, const QString& oldString, const QString& newString);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget wgt;
    QFont widgetFont;
    widgetFont.setPixelSize( 12 );

    QFontMetrics mainMetrics( widgetFont );
    qint32 gridX = 1, gridY = 1;
    QLineEdit* patientName = new QLineEdit;

    //Создание нового пациента
    Patient *patient = new Patient;

    patientName->setFixedHeight( 15 );
    QDateEdit* patientAge = new QDateEdit;

    QDateEdit* researchDate = new QDateEdit( QDate::currentDate() );

// Создание Заголовков

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
    leftThickSpin->setFixedSize( 70, 20 );
    rightThickSpin->setFixedSize( 70, 20 );
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
    magSpin->setFixedSize( 70, 20 );
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
    speedBloodMidRadio->setChecked( true );

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
    downVenaSpin->setFixedSize( 70, 20 );
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
    commonBileSpin->setFixedSize( 70, 20 );
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
    liverConclusionText->setMinimumSize( 600, 20 );
    liverConclusionText->setFixedHeight( 20 );

//ЖЕЛЧНЫЙ ПУЗЫРЬ
    QLabel* gallbladerLabel = new QLabel( " ЖЕЛЧНЫЙ ПУЗЫРЬ: " );

    //Размер
    QLineEdit* gallbladerSizeLine = new QLineEdit(" мм");
    gallbladerSizeLine->setFixedSize( 70, 20 );
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
    gallbladerWallSpin->setFixedSize( 70, 20 );
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
    gallbladerConclusionText->setMinimumSize( 600, 20 );
    gallbladerConclusionText->setFixedHeight( 20 );


//ПОДЖЕЛУДОЧНАЯ ЖЕЛЕЗА
    QLabel* pancreasLabel = new QLabel( "ПОДЖЕЛУДОЧНАЯ ЖЕЛЕЗА: визуализируется. Положение: типичное" );


    //Размеры
    QLabel* pancreasSizeHeadLabel = new QLabel( "Размер: головки:" );
    QLabel* pancreasSizeBodyLabel = new QLabel( ", тела:" );
    QLabel* pancreasSizeTailLabel = new QLabel( ", хвоста:" );
    QSpinBox* pancreasSizeHeadSpin = new QSpinBox;
    pancreasSizeHeadSpin->setFixedSize( 70, 20 );
    pancreasSizeHeadSpin->setRange( 0, 300 );
    pancreasSizeHeadSpin->setSuffix( " мм" );
    pancreasSizeHeadSpin->clear();
    QSpinBox* pancreasSizeBodySpin = new QSpinBox;
    pancreasSizeBodySpin->setFixedSize( 70, 20 );
    pancreasSizeBodySpin->setRange( 0, 300 );
    pancreasSizeBodySpin->setSuffix( " мм" );
    pancreasSizeBodySpin->clear();
    QSpinBox* pancreasSizeTailSpin = new QSpinBox;
    pancreasSizeTailSpin->setFixedSize( 70, 20 );
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
        pancreasConclusionText->setMinimumSize( 600, 20 );
        pancreasConclusionText->setFixedHeight( 20 );

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
    spleenSizeLine->setFixedSize( 70, 20 );
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
    QCheckBox* bellyWaterCheck = new QCheckBox( "Наличие свободной жидкости в брюшной полости: нет" );
    bellyWaterCheck->setFixedSize( 420, 20 );
    QObject::connect( bellyWaterCheck, &QCheckBox::stateChanged,
                          [&] { if ( !( bellyWaterCheck->isChecked() ) ) bellyWaterCheck->setText( "Наличие свободной жидкости в брюшной полости: нет" );
                                if ( ( bellyWaterCheck->isChecked() ) ) bellyWaterCheck->setText( "Наличие свободной жидкости в брюшной полости: есть" );
                                });

    //Заключение
    QLabel* spleenConclusionLabel = new QLabel( "ОПИСАНИЕ: " );
    QTextEdit* spleenConclusionText = new QTextEdit;
    spleenConclusionText->setMinimumSize( 600, 20 );
    spleenConclusionText->setFixedHeight( 20 );

//ЗАКЛЮЧЕНИЕ
    QLabel* mainConclusionLabel = new QLabel( "ЗАКЛЮЧЕНИЕ: " );
    QTextEdit* mainConclusionText = new QTextEdit;
    mainConclusionText->setMaximumSize( 1400, 50 );
    mainConclusionText->setMinimumSize( 700, 35 );
    //Шаблонные вставки
    QCheckBox* mainConclusionGepatomegCheck = new QCheckBox( "Гепатомегалия" );
    QObject::connect( mainConclusionGepatomegCheck, &QCheckBox::stateChanged,
                      [&] { if ( ( mainConclusionGepatomegCheck->isChecked() ) ) mainConclusionText->setText( mainConclusionText->toPlainText() + "Гепатомегалия. " );
                            if ( !( mainConclusionGepatomegCheck->isChecked() ) ) mainConclusionText->setText( mainConclusionText->toPlainText() );
                            });
    QCheckBox* mainConclusionDiffusalchangesLiverCheck = new QCheckBox( "Дифф. изменения печени" );
    QObject::connect( mainConclusionDiffusalchangesLiverCheck, &QCheckBox::stateChanged,
                      [&] { if ( ( mainConclusionDiffusalchangesLiverCheck->isChecked() ) ) mainConclusionText->setText( mainConclusionText->toPlainText() + "Диффузные изменения печени по типу жирового гепатоза. " );
                            if ( !( mainConclusionDiffusalchangesLiverCheck->isChecked() ) ) mainConclusionText->setText( mainConclusionText->toPlainText() );
                            });
    QCheckBox* mainConclusionDiffusalchangesPancreasCheck = new QCheckBox( "Дифф. изменения поджел. железы" );
    QObject::connect( mainConclusionDiffusalchangesPancreasCheck, &QCheckBox::stateChanged,
                      [&] { if ( ( mainConclusionDiffusalchangesPancreasCheck->isChecked() ) ) mainConclusionText->setText( mainConclusionText->toPlainText() + "Диффузные изменения поджелудочной железы. " );
                            if ( !( mainConclusionDiffusalchangesPancreasCheck->isChecked() ) ) mainConclusionText->setText( mainConclusionText->toPlainText() );
                            });
    QCheckBox* mainConclusionEchoFeaturesHoleCheck = new QCheckBox( "Эхо-призн. хр. калькул. холецистита" );
    QObject::connect( mainConclusionEchoFeaturesHoleCheck, &QCheckBox::stateChanged,
                      [&] { if ( ( mainConclusionEchoFeaturesHoleCheck->isChecked() ) ) mainConclusionText->setText( mainConclusionText->toPlainText() + "Эхо-признаки хр. холецистита. " );
                            if ( !( mainConclusionEchoFeaturesHoleCheck->isChecked() ) ) mainConclusionText->setText( mainConclusionText->toPlainText() );
                            });
    QCheckBox* mainConclusionCholeCalculCheck = new QCheckBox( "Эхо-призн. хр. калькул. холецистита" );
    QObject::connect( mainConclusionCholeCalculCheck, &QCheckBox::stateChanged,
                      [&] { if ( ( mainConclusionCholeCalculCheck->isChecked() ) ) mainConclusionText->setText( mainConclusionText->toPlainText() + "Эхо-признаки хр. калькулезного холецистита. " );
                            if ( !( mainConclusionCholeCalculCheck->isChecked() ) ) mainConclusionText->setText( mainConclusionText->toPlainText() );
                            });
    QCheckBox* mainConclusionGallbladerPolypCheck = new QCheckBox( "Полип желчного пузыря" );
    QObject::connect( mainConclusionGallbladerPolypCheck, &QCheckBox::stateChanged,
                      [&] { if ( ( mainConclusionGallbladerPolypCheck->isChecked() ) ) mainConclusionText->setText( mainConclusionText->toPlainText() + "Полип желчного пузыря. " );
                            if ( !( mainConclusionGallbladerPolypCheck->isChecked() ) ) mainConclusionText->setText( mainConclusionText->toPlainText() );
                            });
    QCheckBox* mainConclusionVolumetricLiverCheck = new QCheckBox( "Объем. образ. печени" );
    QObject::connect( mainConclusionVolumetricLiverCheck, &QCheckBox::stateChanged,
                      [&] { if ( ( mainConclusionVolumetricLiverCheck->isChecked() ) ) mainConclusionText->setText( mainConclusionText->toPlainText() + "Объемное образование печени. " );
                            if ( !( mainConclusionVolumetricLiverCheck->isChecked() ) ) mainConclusionText->setText( mainConclusionText->toPlainText() );
                            });
    QCheckBox* mainConclusionEchoFeaturesCystsCheck = new QCheckBox( "Эхо-призн. кисты печени" );
    QObject::connect( mainConclusionEchoFeaturesCystsCheck, &QCheckBox::stateChanged,
                      [&] { if ( ( mainConclusionEchoFeaturesCystsCheck->isChecked() ) ) mainConclusionText->setText( mainConclusionText->toPlainText() + "Эхо-признаки кисты печени. " );
                            if ( !( mainConclusionEchoFeaturesCystsCheck->isChecked() ) ) mainConclusionText->setText( mainConclusionText->toPlainText() );
                            });
    QCheckBox* mainConclusionEchoFeaturesHemangiomaCheck = new QCheckBox( "Эхо-призн. геманг. печени" );
    QObject::connect( mainConclusionEchoFeaturesHemangiomaCheck, &QCheckBox::stateChanged,
                      [&] { if ( ( mainConclusionEchoFeaturesHemangiomaCheck->isChecked() ) ) mainConclusionText->setText( mainConclusionText->toPlainText() + "Эхо-признаки гемангиомы печени. " );
                            if ( !( mainConclusionEchoFeaturesHemangiomaCheck->isChecked() ) ) mainConclusionText->setText( mainConclusionText->toPlainText() );
                            });
    QCheckBox* mainConclusionEchoFeaturesPortalCheck = new QCheckBox( "Эхо-призн. порт. гипертензии" );
    QObject::connect( mainConclusionEchoFeaturesPortalCheck, &QCheckBox::stateChanged,
                      [&] { if ( ( mainConclusionEchoFeaturesPortalCheck->isChecked() ) ) mainConclusionText->setText( mainConclusionText->toPlainText() + "Эхо-признаки портальной гипертензии. " );
                            if ( !( mainConclusionEchoFeaturesPortalCheck->isChecked() ) ) mainConclusionText->setText( mainConclusionText->toPlainText() );
                            });
    QCheckBox* mainConclusionEchoFeaturesBiliarCheck = new QCheckBox( "Эхо-призн. билиар. гипертензии" );
    QObject::connect( mainConclusionEchoFeaturesBiliarCheck, &QCheckBox::stateChanged,
                      [&] { if ( ( mainConclusionEchoFeaturesBiliarCheck->isChecked() ) ) mainConclusionText->setText( mainConclusionText->toPlainText() + "Эхо-признаки билиарной гипертензии. " );
                            if ( !( mainConclusionEchoFeaturesBiliarCheck->isChecked() ) ) mainConclusionText->setText( mainConclusionText->toPlainText() );
                            });
    QCheckBox* mainConclusionVolumeFormationCheck = new QCheckBox( "Объемное образ. поджелуд. жел." );
    QObject::connect( mainConclusionVolumeFormationCheck, &QCheckBox::stateChanged,
                      [&] { if ( ( mainConclusionVolumeFormationCheck->isChecked() ) ) mainConclusionText->setText( mainConclusionText->toPlainText() + "Объемное образование поджелудоной железы. " );
                            if ( !( mainConclusionVolumeFormationCheck->isChecked() ) ) mainConclusionText->setText( mainConclusionText->toPlainText() );
                            });
    QPushButton* mainConclusionReturnButton = new QPushButton( "Cбросить текст" );
    mainConclusionReturnButton->setMinimumHeight( 20 );
    QObject::connect( mainConclusionReturnButton, &QPushButton::clicked,
                      [&]{ mainConclusionGepatomegCheck->setChecked( false );
                           mainConclusionDiffusalchangesLiverCheck->setChecked( false );
                           mainConclusionDiffusalchangesPancreasCheck->setChecked( false );
                           mainConclusionEchoFeaturesHoleCheck->setChecked( false );
                           mainConclusionCholeCalculCheck->setChecked( false );
                           mainConclusionGallbladerPolypCheck->setChecked( false );
                           mainConclusionVolumetricLiverCheck->setChecked( false );
                           mainConclusionEchoFeaturesCystsCheck->setChecked( false );
                           mainConclusionEchoFeaturesHemangiomaCheck->setChecked( false );
                           mainConclusionEchoFeaturesPortalCheck->setChecked( false );
                           mainConclusionEchoFeaturesBiliarCheck->setChecked( false );
                           mainConclusionVolumeFormationCheck->setChecked( false );
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
    //labelName->setSizePolicy( QSizePolicy::Preferred, QSizePolicy::Minimum );
    //patientName->setSizePolicy( QSizePolicy::Preferred, QSizePolicy::Minimum );

    QHBoxLayout* ageLayout = new QHBoxLayout;
    ageLayout->addWidget( labelAge );
    ageLayout->addWidget( patientAge );

    QHBoxLayout* dateLayout = new QHBoxLayout;
    dateLayout->addWidget( labelDate );
    dateLayout->addWidget( researchDate );

    //Основной слой
    QFrame mainFrame;
    mainFrame.setFrameShape( QFrame::Box );
    mainLayout->addWidget( &mainFrame, gridX, gridY, 3, 2 );

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
    mainLayout->addWidget( &liverFrame, gridX + 1, 1, 13, 2 );
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
    QHBoxLayout* liverLeftShareLayout = new QHBoxLayout;
    liverLeftShareLayout->addWidget( leftShareCheck );
    liverLeftShareLayout->addWidget(thickLabel1 );
    liverLeftShareLayout->addWidget( leftThickSpin );
    liverLeftShareLayout->setSpacing( 4 );
    mainLayout->addLayout( liverLeftShareLayout, gridX, 1, Qt::AlignLeft  );
    gridX++;
    QHBoxLayout* liverRightShareLayout = new QHBoxLayout;
    liverRightShareLayout->addWidget( rightShareCheck );
    liverRightShareLayout->addWidget(thickLabel2 );
    liverRightShareLayout->addWidget( rightThickSpin );
    mainLayout->addLayout( liverRightShareLayout, gridX, 1, Qt::AlignLeft  );
    //Толщина
    leftThickSpin->setAutoFillBackground( true );
    //Контур и Эхоструктура
    QHBoxLayout* contourLayout = new QHBoxLayout;
    contourLayout->addWidget( contourLabel );
    QSpacerItem* contourSpacer = new QSpacerItem( 60 - mainMetrics.width( contourLabel->text() ) + mainMetrics.width( echogenLabel->text() ), 15, QSizePolicy::Minimum );
    contourLayout->addSpacerItem( contourSpacer );
    contourLayout->addWidget( contourStraight, 0, Qt::AlignLeft );
    contourLayout->addWidget( contourNotStraight );
    contourLayout->addWidget( contourHilly );
    contourLayout->addWidget( echoCheck );
    contourLayout->setSpacing( 1 );
    mainLayout->addLayout( contourLayout, ++gridX, 1, Qt::AlignLeft );
    //Эхогенность
    gridX++;
    QHBoxLayout* echogenLayout = new QHBoxLayout;
    echogenLayout->addWidget( echogenLabel );
    QSpacerItem* echogenSpacer = new QSpacerItem( 60, 15, QSizePolicy::Minimum );
    echogenLayout->addSpacerItem( echogenSpacer );
    echogenLayout->addWidget( echogenMidRadio );
    echogenLayout->addWidget( echogenUpRadio );
    echogenLayout->addWidget( echogenDownRadio );
    mainLayout->addLayout( echogenLayout, gridX, 1, Qt::AlignLeft );
    //Магистр. Ствол
    gridX++;
    QHBoxLayout* magHLayout = new QHBoxLayout;
    magHLayout->addWidget( magCheck );
    magHLayout->addWidget( magSpin );
    mainLayout->addLayout( magHLayout, gridX, 1, Qt::AlignLeft );
    //Скорость кровотока
    gridX++;
    QHBoxLayout* speedBloodLayout = new QHBoxLayout;
    speedBloodLayout->addWidget( speedBloodLabel );
    QSpacerItem* speedBloodSpacer = new QSpacerItem( 20, 15 );
    speedBloodLayout->addSpacerItem( speedBloodSpacer );
    //speedBloodLayout->setStretch( 1, 2 );
    speedBloodLayout->addWidget( speedBloodUpRadio );
    speedBloodLayout->addWidget( speedBloodMidRadio );
    speedBloodLayout->addWidget( speedBloodDownRadio );
    mainLayout->addLayout( speedBloodLayout, gridX, 1, Qt::AlignLeft );
    //Печеночные вены
    mainLayout->addWidget( hepaticCheck, ++gridX, 1 );
    //Нижняя полая вена
    QHBoxLayout* downVenaHLayout = new QHBoxLayout;
    downVenaHLayout->addWidget( downVenaCheck );
    downVenaHLayout->addWidget( downVenaSpin );
    mainLayout->addLayout( downVenaHLayout, ++gridX, 1, Qt::AlignLeft );
    //Внутрипеченочные желчные протоки
    mainLayout->addWidget( inhepaticCheck, ++gridX, 1 );
    //Общий желчный проток
    QHBoxLayout* commonBileHLayout = new QHBoxLayout;
    commonBileHLayout->addWidget( commonBileCheck );
    commonBileHLayout->addWidget( commonBileSpin );
    commonBileHLayout->addWidget( commonBileCheck2 );
    mainLayout->addLayout( commonBileHLayout, ++gridX, 1, Qt::AlignLeft );
    //Заключение
    QHBoxLayout* liverConclusionLayout = new QHBoxLayout;
    liverConclusionLayout->addWidget( liverConclusionLabel );
    liverConclusionLayout->addWidget( liverConclusionText );
    mainLayout->addLayout( liverConclusionLayout, ++gridX, 1 );


    //ЖЕЛЧНЫЙ ПУЗЫРЬ
    QFrame* gallbladerFrame = new QFrame;
    gallbladerFrame->setFrameShape( QFrame::Box );
    mainLayout->addWidget( gallbladerFrame, ++gridX, 1, 6, 2 );
    mainLayout->addWidget( gallbladerLabel, gridX, 1);
    //Размер
    QHBoxLayout* gallbladerSizeLayout = new QHBoxLayout;
    gallbladerSizeLayout->addWidget( gallbladerSizeLabel );
    gallbladerSizeLayout->addWidget( gallbladerSizeLine, 0, Qt::AlignLeft );
    mainLayout->addLayout( gallbladerSizeLayout, ++gridX, 1, Qt::AlignLeft );
    //Деформация
    QHBoxLayout* gallbladerDeformationLayout = new QHBoxLayout;
    gallbladerDeformationLayout->addWidget( gallbladerDeformationLabel );
    gallbladerDeformationLayout->addWidget( gallbladerDeformationNeckCheck );
    gallbladerDeformationLayout->addWidget( gallbladerDeformationBodyCheck );
    gallbladerDeformationLayout->addWidget( gallbladerDeformationBottomCheck );
    gallbladerDeformationLayout->setSpacing( 4 );
    mainLayout->addLayout( gallbladerDeformationLayout, ++gridX, 1, Qt::AlignLeft );
    //Стенки
    QHBoxLayout* gallbladerWallLayout = new QHBoxLayout;
    gallbladerWallSpin->setSuffix(" мм");
    gallbladerWallSpin->setRange( 0, 300 );
    gallbladerWallSpin->clear();
    gallbladerWallLayout->addWidget( gallbladerWallLabel );
    gallbladerWallLayout->addWidget( gallbladerWallSpin );
    mainLayout->addLayout( gallbladerWallLayout, ++gridX, 1, Qt::AlignLeft );
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
    mainLayout->addWidget( pancreasFrame, ++gridX, 1, 5, 2 );
    mainLayout->addWidget( pancreasLabel, gridX, 1 );
    //Размеры:
    QHBoxLayout* pancreasSizeLayout = new QHBoxLayout;
    pancreasSizeLayout->addWidget( pancreasSizeHeadLabel );
    pancreasSizeLayout->addWidget( pancreasSizeHeadSpin );
    pancreasSizeLayout->addWidget( pancreasSizeBodyLabel );
    pancreasSizeLayout->addWidget( pancreasSizeBodySpin );
    pancreasSizeLayout->addWidget( pancreasSizeTailLabel );
    pancreasSizeLayout->addWidget( pancreasSizeTailSpin );
    pancreasSizeLayout->setSpacing( 8 );
    mainLayout->addLayout( pancreasSizeLayout, ++gridX, 1, Qt::AlignLeft );
    //Контуры и Эхоструктура
    QHBoxLayout* pancreasContourLayout = new QHBoxLayout;
    pancreasContourLayout->addWidget( pancreasContourLabel );
    QSpacerItem* pancreasContourSpacer = new QSpacerItem( 60 - mainMetrics.width( pancreasContourLabel->text() ) + mainMetrics.width( pancreasEchogenLabel->text() ), 15, QSizePolicy::Minimum );
    pancreasContourLayout->addSpacerItem( pancreasContourSpacer );
    pancreasContourLayout->addWidget( pancreasContourStraight );
    pancreasContourLayout->addWidget( pancreasContourNotStraight );
    pancreasContourLayout->addWidget( pancreasContourHilly );
    pancreasContourLayout->addWidget( pancreasEchoCheck );
    mainLayout->addLayout( pancreasContourLayout, ++gridX, 1, Qt::AlignLeft );
    //Эхогенность
    QHBoxLayout* pancreasEchogenLayout = new QHBoxLayout;
    pancreasEchogenLayout->addWidget( pancreasEchogenLabel );
    QSpacerItem* pancreasEchogenSpacer = new QSpacerItem( 60 , 15, QSizePolicy::Minimum );
    pancreasEchogenLayout->addSpacerItem( pancreasEchogenSpacer );
    pancreasEchogenLayout->addWidget( pancreasEchogenMidRadio );
    pancreasEchogenLayout->addWidget( pancreasEchogenUpRadio );
    pancreasEchogenLayout->addWidget( pancreasEchogenDownRadio );
    mainLayout->addLayout( pancreasEchogenLayout, ++gridX, 1, Qt::AlignLeft);
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
     mainLayout->addWidget( spleenFrame, ++gridX, 1, 7, 2 );
     mainLayout->addWidget( spleenLabel, gridX, 1);
     //Положение
     //mainLayout->addWidget( spleenPlaceLabel, ++gridX, 1 );
    //Форма
     QHBoxLayout* spleenFormLayout = new QHBoxLayout;
     spleenFormLayout->addWidget( spleenFormLabel );
     spleenFormLayout->addWidget( spleenFormNormalRadio );
     mainLayout->addLayout( spleenFormLayout, ++gridX, 1, Qt::AlignLeft );
     //Размер
     QHBoxLayout* spleenSizeLayout = new QHBoxLayout;
     spleenSizeLayout->addWidget( spleenSizeLabel, 0, Qt::AlignLeft );
     spleenSizeLayout->addWidget( spleenSizeLine, 0, Qt::AlignLeft );
     mainLayout->addLayout( spleenSizeLayout, ++gridX, 1, Qt::AlignLeft );
     //Контур и Эхоструктура
     QHBoxLayout* spleenContourLayout = new QHBoxLayout;
     spleenContourLayout->addWidget( spleenContourLabel );
     QSpacerItem* spleenContourSpacer = new QSpacerItem( 60 + mainMetrics.width( spleenEchogenLabel->text() ) - mainMetrics.width( spleenContourLabel->text() ), 15, QSizePolicy::Minimum );
     spleenContourLayout->addSpacerItem( spleenContourSpacer );
     spleenContourLayout->addWidget( spleenContourStraight );
     spleenContourLayout->addWidget( spleenContourNotStraight );
     spleenContourLayout->addWidget( spleenContourHilly );
     spleenContourLayout->addWidget( spleenEchoCheck );
     mainLayout->addLayout( spleenContourLayout, ++gridX, 1, Qt::AlignLeft );
     //Эхогенность и Лимфатические узлы
     QHBoxLayout* spleenEchogenLayout = new QHBoxLayout;
     spleenEchogenLayout->addWidget( spleenEchogenLabel );
     QSpacerItem* spleenEchogenSpacer = new QSpacerItem( 60, 15, QSizePolicy::Minimum );
     spleenEchogenLayout->addSpacerItem( spleenEchogenSpacer );
     spleenEchogenLayout->addWidget( spleenEchogenMidRadio );
     spleenEchogenLayout->addWidget( spleenEchogenUpRadio );
     spleenEchogenLayout->addWidget( spleenEchogenDownRadio );
     spleenEchogenLayout->addWidget( spleenLimfaCheck );
     mainLayout->addLayout( spleenEchogenLayout, ++gridX, 1, Qt::AlignLeft );
     //Селезеночная вена
     mainLayout->addWidget( spleenVenaCheck, ++gridX, 1 );
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
     qint16 conclusionX = 0;
     mainConclusionPatternsLayout->addWidget( mainConclusionGepatomegCheck, ++conclusionX, 1 );
     mainConclusionGepatomegCheck->setMinimumHeight( 15 );
     mainConclusionPatternsLayout->addWidget( mainConclusionDiffusalchangesLiverCheck, conclusionX, 2 );
     mainConclusionDiffusalchangesLiverCheck->setMinimumHeight( 15 );
     mainConclusionPatternsLayout->addWidget( mainConclusionDiffusalchangesPancreasCheck, conclusionX, 3 );
     mainConclusionDiffusalchangesPancreasCheck->setMinimumHeight( 15 );
     mainConclusionPatternsLayout->addWidget( mainConclusionEchoFeaturesHoleCheck, ++conclusionX, 1 );
     mainConclusionEchoFeaturesHoleCheck->setMinimumHeight( 15 );
     mainConclusionPatternsLayout->addWidget( mainConclusionCholeCalculCheck, conclusionX, 2 );
     mainConclusionCholeCalculCheck->setMinimumHeight( 15 );
     mainConclusionPatternsLayout->addWidget( mainConclusionGallbladerPolypCheck, conclusionX, 3 );
     mainConclusionGallbladerPolypCheck->setMinimumHeight( 15 );
     mainConclusionPatternsLayout->addWidget( mainConclusionVolumetricLiverCheck, ++conclusionX, 1 );
     mainConclusionVolumetricLiverCheck->setMinimumHeight( 15 );
     mainConclusionPatternsLayout->addWidget( mainConclusionEchoFeaturesCystsCheck, conclusionX, 2 );
     mainConclusionEchoFeaturesCystsCheck->setMinimumHeight( 15 );
     mainConclusionPatternsLayout->addWidget( mainConclusionEchoFeaturesPortalCheck, conclusionX, 3 );
     mainConclusionEchoFeaturesPortalCheck->setMinimumHeight( 15 );
     mainConclusionPatternsLayout->addWidget( mainConclusionEchoFeaturesBiliarCheck, ++conclusionX, 1 );
     mainConclusionEchoFeaturesBiliarCheck->setMinimumHeight( 15 );
     mainConclusionPatternsLayout->addWidget( mainConclusionVolumeFormationCheck, conclusionX, 2 );
     mainConclusionVolumeFormationCheck->setMinimumHeight( 15 );
     mainConclusionPatternsLayout->addWidget( mainConclusionReturnButton, conclusionX, 3 );

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
                                              pWord->setProperty( "Visible", true );
                                            replaceString( pWord, "mainConclusionText", mainConclusionText->toPlainText() );





                                   }  );
         //Сохранить документ LAYOUT
              mainLayout->addWidget( liverSaveAllButton, ++gridX, 1, Qt::AlignRight );

 //ДОБАВЛЕНИЕ К mainTabWidget ВСЕХ ФОРМ И ИХ НАСТРОЙКА

              QTabWidget mainTabWidget;
              QWidget newPatientFormWidget;
              newPatientForm newPatientFormClass( &newPatientFormWidget );
              mainTabWidget.addTab( &newPatientFormWidget, "Пациент" );


              //ПЕЧЕНЬ
              QScrollArea LiverScrollArea;
              QWidget returnWidget;
              mainTabWidget.addTab( &LiverScrollArea, "Печень" );

              //ПОЧКИ
              QWidget kidneysWidget;
              QScrollArea kidneysScrollArea;
              Ui::kidneys kidneysClass( &kidneysWidget );
              kidneysScrollArea.setWidget( &kidneysWidget );
              kidneysWidget.resize( 710, 600 );
              mainTabWidget.addTab( &kidneysScrollArea, "Почки" );

              //Щитовидная железа
              QWidget thyroidWidget;
              QScrollArea thyroidScrollArea;
              Ui::thyroid thyroidClass( &thyroidWidget );
              thyroidScrollArea.setWidget( &thyroidWidget );
              thyroidWidget.resize( 710, 650 );
              QObject::connect( newPatientFormClass.patientMaleRadio, &QRadioButton::toggled, [&] {
                    thyroidClass.volumeNormalLabel->setText( "( норма 7-25 см. куб. )" );
              } );
              QObject::connect( newPatientFormClass.patientFemaleRadio, &QRadioButton::toggled, [&] {
                    thyroidClass.volumeNormalLabel->setText( "( норма 4,4-18 см. куб. )" );
              } );

              mainTabWidget.addTab( &thyroidScrollArea, "Щит. железа" );

              //Молочные железы
              QWidget mammaryWidget;
              QScrollArea mammaryScrollArea;
              Ui::mammary mammaryClass( &mammaryWidget );
              mammaryScrollArea.setWidget( &mammaryWidget );
              mammaryWidget.resize( 710, 710 );
              mainTabWidget.addTab( &mammaryScrollArea, "Молочн. железы" );


              LiverScrollArea.setWidget( &wgt );
              mainLayout->setHorizontalSpacing( 0 );
              mainLayout->setMargin( 10 );
              mainTabWidget.setFont( widgetFont );
              wgt.setLayout( mainLayout );
              wgt.resize( 710, 1000 );
              mainTabWidget.resize( 720, 600 );
              mainTabWidget.setMinimumSize( 750, 500 );
              mainTabWidget.setMaximumSize( 800, 600 );

              //НОВЫЙ ПАЦИЕНТ ПЕРВЫЙ
              QPushButton* newPatientButton = new QPushButton( "Новый пациент" );
              mainTabWidget.setCornerWidget( newPatientButton, Qt::Corner::TopLeftCorner );
              //Следующий пациент ( вся информация об предыдущем будет удалена )

              QObject::connect( newPatientButton, &QPushButton::clicked,
                                [&]
                                    {
                                        newPatientFormClass.patientNameLine->clear();
                                        newPatientFormClass.patientAgeDate->setDate( QDate::currentDate() );
                                        newPatientFormClass.patientMaleRadio->setChecked( true );
                                        newPatientFormClass.patientGroup->setExclusive( false );
                                        newPatientFormClass.patientMaleRadio->setChecked( false );
                                        newPatientFormClass.patientGroup->setExclusive( true );

                                        placeStdRadio->setChecked( true );
                                        leftShareCheck->setChecked( false );
                                        rightShareCheck->setChecked( false );
                                        leftThickSpin->clear();
                                        rightThickSpin->clear();

                                        contourHilly->setChecked( true );
                                        contourGroups->setExclusive( false );
                                        contourHilly->setChecked( false );
                                        contourGroups->setExclusive( true );

                                        echoCheck->setChecked( false );

                                        echogenDownRadio->setChecked( true );
                                        echogenGroup->setExclusive( false );
                                        echogenDownRadio->setChecked( false );
                                        echogenGroup->setExclusive( true );

                                        magCheck->setChecked( false );
                                        magSpin->clear();

                                        speedBloodMidRadio->setChecked( true );

                                        hepaticCheck->setChecked( false );
                                        downVenaCheck->setChecked( false );
                                        downVenaSpin->clear();
                                        inhepaticCheck->setChecked( false );
                                        commonBileCheck->setChecked( false );
                                        commonBileSpin->clear();
                                        commonBileCheck2->setChecked( false );

                                        liverConclusionText->clear();

                                        gallbladerSizeLine->setText( " мм" );
                                        gallbladerDeformationBodyCheck->setChecked( false );
                                        gallbladerDeformationBottomCheck->setChecked( false );
                                        gallbladerDeformationNeckCheck->setChecked( false );
                                        gallbladerWallSpin->clear();
                                        gallbladerContentCheck->setChecked( false );
                                        gallbladerConcrementsCheck->setChecked( false );
                                        gallbladerConclusionText->clear();

                                        pancreasSizeBodySpin->clear();
                                        pancreasSizeHeadSpin->clear();
                                        pancreasSizeTailSpin->clear();

                                        pancreasContourHilly->setChecked( true );
                                        pancreasContourGroups->setExclusive( false );
                                        pancreasContourHilly->setChecked( false );
                                        pancreasContourGroups->setExclusive( true );

                                        pancreasEchogenDownRadio->setChecked( true );
                                        pancreasEchogenGroups->setExclusive( false );
                                        pancreasEchogenDownRadio->setChecked( false );
                                        pancreasEchogenGroups->setExclusive( true );

                                        pancreasMainStreamCheck->setChecked( false );
                                        pancreasConclusionText->clear();

                                        spleenSizeLine->setText( " мм" );

                                        spleenContourHilly->setChecked( true );
                                        spleenContourGroups->setExclusive( false );
                                        spleenContourHilly->setChecked( false );
                                        spleenContourGroups->setExclusive( true );

                                        spleenEchogenDownRadio->setChecked( true );
                                        spleenEchogenGroups->setExclusive( false );
                                        spleenEchogenDownRadio->setChecked( false );
                                        spleenEchogenGroups->setExclusive( true );

                                        spleenVenaCheck->setChecked( false );
                                        bellyWaterCheck->setChecked( false );
                                        spleenConclusionText->clear();

                                        mainConclusionText->clear();

                                        //ПОЧКИ KIDNEYS

                                        kidneysClass.kidneysBladderSpin->clear();
                                        kidneysClass.kidneysBladderContainsCheck->setChecked( false );
                                        kidneysClass.kidneysBladderWallsContourCheck->setChecked( false );
                                        kidneysClass.kidneysBladderWallsWideCheck->setChecked( false );
                                        kidneysClass.kidneysBladderDropsCheck->setChecked( false );

                                        kidneysClass.kidneysRightContourCheck1->setChecked( false );
                                        kidneysClass.kidneysRightContourCheck2->setChecked( false );
                                        kidneysClass.kidneysRightSizeCheck->setChecked( false );
                                        kidneysClass.kidneysRightSizeLine->clear();
                                        kidneysClass.kidneysRightParenchymaSpin->clear();
                                        kidneysClass.kidneysRightEchoCheck->setChecked( false );
                                        kidneysClass.kidneysRightCalyxCheck->setChecked( false );
                                        kidneysClass.kidneysRightDiffCheck->setChecked( false );
                                        kidneysClass.kidneysRightCalyxEdit->clear();

                                        kidneysClass.kidneysLeftContourCheck1->setChecked( false );
                                        kidneysClass.kidneysLeftContourCheck2->setChecked( false );
                                        kidneysClass.kidneysLeftSizeCheck->setChecked( false );
                                        kidneysClass.kidneysLeftSizeLine->clear();
                                        kidneysClass.kidneysLeftParenchymaSpin->clear();
                                        kidneysClass.kidneysLeftEchoCheck->setChecked( false );
                                        kidneysClass.kidneysLeftCalyxCheck->setChecked( false );
                                        kidneysClass.kidneysLeftDiffCheck->setChecked( false );
                                        kidneysClass.kidneysLeftCalyxEdit->clear();

                                        kidneysClass.kidneysCDKCheck->setChecked( false );
                                        kidneysClass.kidneysProectionCheck->setChecked( false );
                                        kidneysClass.kidneysProectionEdit->clear();
                                        kidneysClass.kidneysConclusionText->clear();

                                        //ЩИТОВИДНАЯ ЖЕЛЕЗА THYROID

                                        thyroidClass.rightShareCheck->setChecked( false );
                                        thyroidClass.rightShareLengthSpin->clear();
                                        thyroidClass.rightShareWideSpin->clear();
                                        thyroidClass.rightShareThicknessSpin->clear();
                                        thyroidClass.rightShareVolumeSpin->clear();

                                        thyroidClass.leftShareCheck->setChecked( false );
                                        thyroidClass.leftShareLengthSpin->clear();
                                        thyroidClass.leftShareWideSpin->clear();
                                        thyroidClass.leftShareThicknessSpin->clear();
                                        thyroidClass.leftShareVolumeSpin->clear();

                                        thyroidClass.neckLymphoCheck->setChecked( false );
                                        thyroidClass.neckThicknessSpin->clear();
                                        thyroidClass.volumeSpin->clear();

                                        thyroidClass.echogenDownRadio->setChecked( true );
                                        thyroidClass.echogenGroup->setExclusive( false );
                                        thyroidClass.echogenDownRadio->setChecked( false );
                                        thyroidClass.echogenGroup->setExclusive( true );

                                        thyroidClass.structureCheck->setChecked( false );
                                        thyroidClass.contourCheck->setChecked( false );
                                        thyroidClass.creaturesCheck->setChecked( false );
                                        thyroidClass.creaturesEdit->clear();
                                        thyroidClass.neckLymphoCheck->setChecked( false );
                                        thyroidClass.neckLymphoEdit->clear();
                                        thyroidClass.mainConclusionText->clear();

                                        //Молочные железы MAMMARY
                                        mammaryClass.rightShapeCheck->setChecked( false );
                                        mammaryClass.rightClothCombo->setCurrentIndex( 0 );
                                        mammaryClass.rightVisualCheck->setChecked( false );
                                        mammaryClass.rightStreamCheck->setChecked( false );
                                        mammaryClass.rightDiffCheck->setChecked( false );
                                        mammaryClass.rightChangesCheck->setChecked( false );
                                        mammaryClass.rightChangesEdit->clear();
                                        mammaryClass.rightLymphoCheck->setChecked( false );
                                        mammaryClass.rightLymphoEdit->clear();

                                        mammaryClass.leftShapeCheck->setChecked( false );
                                        mammaryClass.leftClothCombo->setCurrentIndex( 0 );
                                        mammaryClass.leftVisualCheck->setChecked( false );
                                        mammaryClass.leftStreamCheck->setChecked( false );
                                        mammaryClass.leftDiffCheck->setChecked( false );
                                        mammaryClass.leftChangesCheck->setChecked( false );
                                        mammaryClass.leftChangesEdit->clear();
                                        mammaryClass.leftLymphoCheck->setChecked( false );
                                        mammaryClass.leftLymphoEdit->clear();

                                        mammaryClass.mainConclusionText->clear();






                                        mainTabWidget.setCurrentIndex( 0 );

                                    } );

              QWidget *passwordWidget = new QWidget();
              QLineEdit *passwordEdit = new QLineEdit( passwordWidget );
              passwordWidget->resize( 200, 200 );
              passwordWidget->show();
              QObject::connect( passwordEdit, &QLineEdit::textChanged, [&] {
                 if ( passwordEdit->text() == "1956" )
                 {
                     mainTabWidget.show();
                     passwordWidget->close();
                 }

              });
              //LiverScrollArea.resize( 720, 700 );
              //LiverScrollArea.show();





              //Изменение имени и возраста пациента
              //Изменение имени пациента

              QObject::connect( newPatientFormClass.patientNameLine , &QLineEdit::textChanged,
                                [&] {
                                      patient->setName( newPatientFormClass.patientNameLine->text() );
                                      patientName->setText( patient->getName() );
                                      kidneysClass.kidneysNameLine->setText( patient->getName() );
                                      thyroidClass.patientNameLine->setText( patient->getName() );
                                      mammaryClass.patientNameLine->setText( patient->getName() );
                                    }
                                );

              //Изменение возраста
              QObject::connect( newPatientFormClass.patientAgeDate, &QDateEdit::dateChanged,
                                [&] {
                                      patientAge->setDate( newPatientFormClass.patientAgeDate->date() );
                                      kidneysClass.kidneysAgeLine->setDate( newPatientFormClass.patientAgeDate->date() );
                                      thyroidClass.patientAgeDate->setDate( newPatientFormClass.patientAgeDate->date() );
                                      mammaryClass.patientAgeDate->setDate( newPatientFormClass.patientAgeDate->date() );
                                    }
                                );



              return a.exec();


}




