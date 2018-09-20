/********************************************************************************
** Form generated from reading UI file 'kidneys.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef KIDNEYS_H
#define KIDNEYS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QPushButton>
#include <QAxObject>
#include <QAxBase>
#include <QCoreApplication>

void replaceString(QAxObject* pActiveDoc, const QString& oldString, const QString& newString);

QT_BEGIN_NAMESPACE

class kidneysForm
{
public:
    QCheckBox *kidneysCDKCheck;
    QFrame *kidneysFrame2;
    QCheckBox *kidneysProectionCheck;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QFrame *kidneysFrame1;
    QHBoxLayout *kidneysNameLayout;
    QLabel *kidneysNameLabel;
    QLineEdit *kidneysNameLine;
    QHBoxLayout *kidneysAgeLayout;
    QLabel *kidneysAgeLabel;
    QDateEdit *kidneysAgeLine;
    QHBoxLayout *kidneysDateLayout;
    QLabel *kidneysDateLabel;
    QDateEdit *kidneysDateEdit;
    QLabel *kidneysMainLabel;
    QFrame *kidneysFrame3;
    QFrame *kidneysFrame4;
    QHBoxLayout *kidneysBladderLayout;
    QLabel *kidneysBladderLabel;
    QSpinBox *kidneysBladderSpin;
    QCheckBox *kidneysBladderContainsCheck;
    QHBoxLayout *kidneysBladderWallsLayout;
    QCheckBox *kidneysBladderWallsContourCheck;
    QCheckBox *kidneysBladderWallsWideCheck;
    QCheckBox *kidneysBladderDropsCheck;
    QHBoxLayout *kidneysRightPlaceLayout;
    QLabel *kidneysRightPlaceLabel;
    QCheckBox *kidneysRightPlaceCheck;
    QCheckBox *kidneysRightContourCheck1;
    QCheckBox *kidneysRightContourCheck2;
    QHBoxLayout *kidneysRightSizeLayout;
    QCheckBox *kidneysRightSizeCheck;
    QLineEdit *kidneysRightSizeLine;
    QLabel *kidneysRightParenchymaLabel;
    QSpinBox *kidneysRightParenchymaSpin;
    QHBoxLayout *kidneysRightEchoLayout;
    QCheckBox *kidneysRightEchoCheck;
    QCheckBox *kidneysRightDiffCheck;
    QCheckBox *kidneysRightCalyxCheck;
    QTextEdit *kidneysRightCalyxEdit;
    QHBoxLayout *kidneysLeftPlaceLayout;
    QLabel *kidneysLeftPlaceLabel;
    QCheckBox *kidneysLeftPlaceCheck;
    QCheckBox *kidneysLeftContourCheck1;
    QCheckBox *kidneysLeftContourCheck2;
    QHBoxLayout *kidneysLeftSizeLayout;
    QCheckBox *kidneysLeftSizeCheck;
    QLineEdit *kidneysLeftSizeLine;
    QLabel *kidneysLeftParenchymaLabel;
    QSpinBox *kidneysLeftParenchymaSpin;
    QHBoxLayout *kidneysLeftEchoLayout;
    QCheckBox *kidneysLeftEchoCheck;
    QCheckBox *kidneysLeftDiffCheck;
    QCheckBox *kidneysLeftCalyxCheck;
    QTextEdit *kidneysLeftCalyxEdit;
    QTextEdit *kidneysProectionEdit;
    QLabel *kidneysConclusionLabel;
    QTextEdit *kidneysConclusionText;
    QPushButton *kidneysSaveAllButton;
    QAxObject *pWord;
    QAxObject *pDocs;
    QString dirDocKidneys;
    qint16 gridIndex = 0;

    void setupUi(QWidget *centralwidget)
    {
//        if (MainWindow->objectName().isEmpty())
//            MainWindow->setObjectName(QStringLiteral("MainWindow"));
//        MainWindow->setEnabled(true);
//        MainWindow->resize(700, 700);
//        MainWindow->setMinimumSize( 500, 300 );
//        MainWindow->setMaximumSize( 700, 700 );
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        centralwidget->setEnabled(true);
        centralwidget->setContextMenuPolicy(Qt::NoContextMenu);
        centralwidget->setAcceptDrops(false);
        centralwidget->setAutoFillBackground(false);
        gridLayout = new QGridLayout;
        gridLayout->setSizeConstraint( QLayout::SizeConstraint::SetNoConstraint );
        //gridLayout->SetFixedSize( 700, 700 );
        centralwidget->setLayout( gridLayout );

        kidneysFrame1 = new QFrame;
        kidneysFrame1->setFrameShape( QFrame::Box );
        gridLayout->addWidget( kidneysFrame1, gridIndex, 0, 3, 1 );
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        kidneysNameLayout = new QHBoxLayout();
        kidneysNameLayout->setObjectName(QStringLiteral("kidneysNameLayout"));
        kidneysNameLabel = new QLabel(centralwidget);
        kidneysNameLabel->setObjectName(QStringLiteral("kidneysNameLabel"));

        kidneysNameLayout->addWidget(kidneysNameLabel);

        kidneysNameLine = new QLineEdit(centralwidget);
        kidneysNameLine->setObjectName(QStringLiteral("kidneysNameLine"));
        kidneysNameLine->setMinimumSize( 651, 15 );
        kidneysNameLine->setFixedHeight( 15 );
        kidneysNameLine->setMouseTracking(true);

        kidneysNameLayout->addWidget( kidneysNameLine, 0, Qt::AlignLeft );


        gridLayout->addLayout(kidneysNameLayout, gridIndex++, 0,  Qt::AlignLeft );

        kidneysAgeLayout = new QHBoxLayout();
        kidneysAgeLayout->setObjectName(QStringLiteral("kidneysAgeLayout"));
        kidneysAgeLabel = new QLabel(centralwidget);
        kidneysAgeLabel->setObjectName(QStringLiteral("kidneysAgeLabel"));

        kidneysAgeLayout->addWidget(kidneysAgeLabel);

        kidneysAgeLine = new QDateEdit(centralwidget);
        kidneysAgeLine->setObjectName(QStringLiteral("kidneysAgeLine"));

        kidneysAgeLayout->addWidget(kidneysAgeLine);


        gridLayout->addLayout(kidneysAgeLayout, gridIndex++, 0 );

        kidneysDateLayout = new QHBoxLayout();
        kidneysDateLayout->setSpacing( 0 );
        kidneysDateLayout->setObjectName(QStringLiteral("kidneysDateLayout"));
        kidneysDateLabel = new QLabel(centralwidget);
        kidneysDateLabel->setObjectName(QStringLiteral("kidneysDateLabel"));

        kidneysDateLayout->addWidget(kidneysDateLabel);

        kidneysDateEdit = new QDateEdit(centralwidget);
        kidneysDateEdit->setObjectName(QStringLiteral("kidneysDateEdit"));
        kidneysDateEdit->setWrapping(false);
        kidneysDateEdit->setFrame(true);
        kidneysDateEdit->setAlignment(Qt::AlignLeading|Qt::AlignRight|Qt::AlignTop);
        kidneysDateEdit->setReadOnly(false);
        kidneysDateEdit->setAccelerated(false);
        kidneysDateEdit->setKeyboardTracking(true);
        kidneysDateEdit->setProperty("showGroupSeparator", QVariant(false));
        kidneysDateEdit->setCalendarPopup(false);
        kidneysDateEdit->setDate( QDate::currentDate() );

        kidneysDateLayout->addWidget(kidneysDateEdit );


        gridLayout->addLayout(kidneysDateLayout, gridIndex++, 0 );

        kidneysMainLabel = new QLabel(centralwidget);
        kidneysMainLabel->setObjectName(QStringLiteral("kidneysMainLabel"));
        kidneysMainLabel->setMinimumSize(QSize(1000, 20));
        kidneysMainLabel->setMaximumSize(QSize(1000, 30));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(8);
        font.setBold(false);
        font.setWeight(50);
        kidneysMainLabel->setFont(font);
        kidneysMainLabel->setScaledContents(false);
        kidneysMainLabel->setWordWrap(false);
        kidneysMainLabel->setMargin(10);

        gridLayout->addWidget(kidneysMainLabel, gridIndex++, 0, Qt::AlignRight );

        kidneysBladderLayout = new QHBoxLayout();
        kidneysBladderLayout->setObjectName(QStringLiteral("kidneysBladderLayout"));
        kidneysBladderLabel = new QLabel(centralwidget);
        kidneysBladderLabel->setObjectName(QStringLiteral("kidneysBladderLabel"));

        kidneysBladderLayout->addWidget(kidneysBladderLabel);

        kidneysFrame2 = new QFrame;
        kidneysFrame2->setFrameShape( QFrame::Box );
        gridLayout->addWidget( kidneysFrame2, gridIndex, 0, 4, 1 );
        kidneysBladderSpin = new QSpinBox(centralwidget);
        kidneysBladderSpin->setObjectName(QStringLiteral("kidneysBladderSpin"));

        kidneysBladderSpin->setMaximum( 1000 );
        kidneysBladderSpin->clear();

        kidneysBladderLayout->addWidget(kidneysBladderSpin);

        gridLayout->addLayout(kidneysBladderLayout, gridIndex++, 0, Qt::AlignLeft );

        kidneysBladderContainsCheck = new QCheckBox( "Содержимое: неоднородное" );

        kidneysBladderContainsCheck->setObjectName(QStringLiteral("kidneysBladderContainsCheck"));
        QObject::connect( kidneysBladderContainsCheck, &QCheckBox::stateChanged,
                          [&] {
                                            if ( !( kidneysBladderContainsCheck->isChecked() ) ) kidneysBladderContainsCheck->setText("Содержимое: неоднородное");
                                            if ( ( kidneysBladderContainsCheck->isChecked() ) ) kidneysBladderContainsCheck->setText("Содержимое:   однородное");
                               });


        gridLayout->addWidget(kidneysBladderContainsCheck, gridIndex++, 0, Qt::AlignLeft );

        kidneysBladderWallsLayout = new QHBoxLayout();
        kidneysBladderWallsLayout->setObjectName(QStringLiteral("kidneysBladderWallsLayout"));
        kidneysBladderWallsContourCheck = new QCheckBox(centralwidget);
        kidneysBladderWallsContourCheck->setObjectName(QStringLiteral("kidneysBladderWallsContourCheck"));
        QObject::connect( kidneysBladderWallsContourCheck, &QCheckBox::stateChanged,
                          [&] {
                                            if ( !( kidneysBladderWallsContourCheck->isChecked() ) ) kidneysBladderWallsContourCheck->setText("Cтенки: неровные");
                                            if ( ( kidneysBladderWallsContourCheck->isChecked() ) ) kidneysBladderWallsContourCheck->setText("Стенки:   ровные");
                               });
        kidneysBladderWallsContourCheck->setChecked(false);
        kidneysBladderWallsContourCheck->setTristate(false);

        kidneysBladderWallsLayout->addWidget(kidneysBladderWallsContourCheck);

        kidneysBladderWallsWideCheck = new QCheckBox(centralwidget);
        kidneysBladderWallsWideCheck->setObjectName(QStringLiteral("kidneysBladderWallsWideCheck"));
        QObject::connect( kidneysBladderWallsWideCheck, &QCheckBox::stateChanged,
                          [&] {
                                            if ( !( kidneysBladderWallsWideCheck->isChecked() ) ) kidneysBladderWallsWideCheck->setText("не утолщены");
                                            if ( ( kidneysBladderWallsWideCheck->isChecked() ) ) kidneysBladderWallsWideCheck->setText("  утолщены");
                               });

        kidneysBladderWallsLayout->addWidget(kidneysBladderWallsWideCheck);


        gridLayout->addLayout(kidneysBladderWallsLayout, gridIndex++, 0, Qt::AlignLeft );

        kidneysBladderDropsCheck = new QCheckBox(centralwidget);
        kidneysBladderDropsCheck->setObjectName(QStringLiteral("kidneysBladderDropsCheck"));
        QObject::connect( kidneysBladderDropsCheck, &QCheckBox::stateChanged,
                          [&] {
                                            if ( !( kidneysBladderDropsCheck->isChecked() ) ) kidneysBladderDropsCheck->setText("Мочеточниковые выбросы: не изменены с обеих сторон");
                                            if ( ( kidneysBladderDropsCheck->isChecked() ) ) kidneysBladderDropsCheck->setText("Мочеточниковые выбросы:    изменены с обеих сторон");
                               });

        gridLayout->addWidget(kidneysBladderDropsCheck, gridIndex++, 0, Qt::AlignLeft );

        kidneysRightPlaceLayout = new QHBoxLayout();
        kidneysRightPlaceLayout->setObjectName(QStringLiteral("kidneysRightPlaceLayout"));
        kidneysRightPlaceLabel = new QLabel(centralwidget);
        kidneysRightPlaceLabel->setObjectName(QStringLiteral("kidneysRightPlaceLabel"));
        QFont font1;
        font1.setPointSize(10);
        kidneysRightPlaceLabel->setFont(font1);
        QFrame* kidneysFrame3 = new QFrame;
        kidneysFrame3->setFrameShape( QFrame::Box );
        gridLayout->addWidget( kidneysFrame3, gridIndex, 0, 5, 1 );

        kidneysRightPlaceCheck = new QCheckBox( "расположена низко" );
        QObject::connect( kidneysRightPlaceCheck, &QCheckBox::stateChanged,
                          [&] {
                                            if ( !( kidneysRightPlaceCheck->isChecked() ) ) kidneysRightPlaceCheck->setText( "расположена низко" );
                                            if ( ( kidneysRightPlaceCheck->isChecked() ) ) kidneysRightPlaceCheck->setText( "расположена обычно" );
                               });

        kidneysRightPlaceLayout->addWidget(kidneysRightPlaceLabel);
        kidneysRightPlaceLayout->addWidget( kidneysRightPlaceCheck );

        kidneysRightContourCheck1 = new QCheckBox(centralwidget);
        kidneysRightContourCheck1->setObjectName(QStringLiteral("kidneysRightContourCheck1"));
        QObject::connect( kidneysRightContourCheck1, &QCheckBox::stateChanged,
                          [&] {
                                            if ( !( kidneysRightContourCheck1->isChecked() ) ) kidneysRightContourCheck1->setText("Контуры: нечеткие, ");
                                            if ( ( kidneysRightContourCheck1->isChecked() ) ) kidneysRightContourCheck1->setText("Контуры:    четкие, ");
                               });

        kidneysRightPlaceLayout->addWidget(kidneysRightContourCheck1);

        kidneysRightContourCheck2 = new QCheckBox(centralwidget);
        kidneysRightContourCheck2->setObjectName(QStringLiteral("kidneysRightCountourCheck2"));
        QObject::connect( kidneysRightContourCheck2, &QCheckBox::stateChanged,
                          [&] {
                                            if ( !( kidneysRightContourCheck2->isChecked() ) ) kidneysRightContourCheck2->setText("неровные");
                                            if ( ( kidneysRightContourCheck2->isChecked() ) ) kidneysRightContourCheck2->setText("   ровные");
                               });

        kidneysRightPlaceLayout->addWidget(kidneysRightContourCheck2);


        gridLayout->addLayout(kidneysRightPlaceLayout, gridIndex++, 0, Qt::AlignLeft );

        kidneysRightSizeLayout = new QHBoxLayout();
        kidneysRightSizeLayout->setObjectName(QStringLiteral("kidneysRightSizeLayout"));
        kidneysRightSizeCheck = new QCheckBox(centralwidget);
        kidneysRightSizeCheck->setObjectName(QStringLiteral("kidneysRightSizeCheck"));
        QObject::connect( kidneysRightSizeCheck, &QCheckBox::stateChanged,
                          [&] {
                                            if ( !( kidneysRightSizeCheck->isChecked() ) ) kidneysRightSizeCheck->setText("Размеры: не увеличены");
                                            if ( ( kidneysRightSizeCheck->isChecked() ) ) kidneysRightSizeCheck->setText("Размеры:     увеличены");
                               });

        kidneysRightSizeLayout->addWidget(kidneysRightSizeCheck);

        kidneysRightSizeLine = new QLineEdit(centralwidget);
        kidneysRightSizeLine->setObjectName(QStringLiteral("kidneysrightSizeLine"));

        kidneysRightSizeLayout->addWidget( kidneysRightSizeLine, 0, Qt::AlignLeft );

        kidneysRightParenchymaLabel = new QLabel(centralwidget);
        kidneysRightParenchymaLabel->setObjectName(QStringLiteral("kidneysRightParenchymaLabel"));

        kidneysRightSizeLayout->addWidget(kidneysRightParenchymaLabel);

        kidneysRightParenchymaSpin = new QSpinBox(centralwidget);
        kidneysRightParenchymaSpin->setObjectName(QStringLiteral("kidneysRightParenchymaSpin"));
        kidneysRightParenchymaSpin->setMaximum(1000);
        kidneysRightParenchymaSpin->clear();

        kidneysRightSizeLayout->addWidget(kidneysRightParenchymaSpin);


        gridLayout->addLayout(kidneysRightSizeLayout, gridIndex++, 0, Qt::AlignLeft );

        kidneysRightEchoLayout = new QHBoxLayout();
        kidneysRightEchoLayout->setObjectName(QStringLiteral("kidneysRightEchoLayout"));
        kidneysRightEchoCheck = new QCheckBox(centralwidget);
        kidneysRightEchoCheck->setObjectName(QStringLiteral("kidneysRightEchoCheck"));
        QObject::connect( kidneysRightEchoCheck, &QCheckBox::stateChanged,
                          [&] {
                                            if ( !( kidneysRightEchoCheck->isChecked() ) ) kidneysRightEchoCheck->setText("Эхоструктура паренхимы: неоднородная, ");
                                            if ( ( kidneysRightEchoCheck->isChecked() ) ) kidneysRightEchoCheck->setText("Эхоструктура паренхимы:    однородная, ");
                               });


        kidneysRightEchoLayout->addWidget(kidneysRightEchoCheck);

        kidneysRightDiffCheck = new QCheckBox(centralwidget);
        kidneysRightDiffCheck->setObjectName(QStringLiteral("kidneysRightDiffCheck"));
        QObject::connect( kidneysRightDiffCheck, &QCheckBox::stateChanged,
                          [&] {
                                            if ( !( kidneysRightDiffCheck->isChecked() ) ) kidneysRightDiffCheck->setText("кортико-медуллярная дифференциация: не выражена. ");
                                            if ( ( kidneysRightDiffCheck->isChecked() ) ) kidneysRightDiffCheck->setText("кортико-медуллярная дифференциация:     выражена.");
                               });


        kidneysRightEchoLayout->addWidget(kidneysRightDiffCheck);


        gridLayout->addLayout(kidneysRightEchoLayout, gridIndex++, 0, Qt::AlignLeft );

        kidneysRightCalyxCheck = new QCheckBox(centralwidget);
        kidneysRightCalyxCheck->setObjectName(QStringLiteral("kidneysRightCalyxCheck"));
        QObject::connect( kidneysRightCalyxCheck, &QCheckBox::stateChanged,
                          [&] {
                                            if ( !( kidneysRightCalyxCheck->isChecked() ) ) kidneysRightCalyxCheck->setText("Чашечно-лоханочная система: не расширена.");
                                            if ( ( kidneysRightCalyxCheck->isChecked() ) ) kidneysRightCalyxCheck->setText("Чашечно-лоханочная система:     расширена.");
                               });

        gridLayout->addWidget(kidneysRightCalyxCheck, gridIndex++, 0, Qt::AlignLeft );
        kidneysRightCalyxEdit = new QTextEdit;
        kidneysRightCalyxEdit->setFixedSize( 670, 20 );
        kidneysRightCalyxEdit->setMaximumSize( 700, 30 );
        gridLayout->addWidget( kidneysRightCalyxEdit, gridIndex++, 0, Qt::AlignLeft );


        kidneysLeftPlaceLayout = new QHBoxLayout();
        kidneysLeftPlaceLayout->setObjectName(QStringLiteral("kidneysLeftPlaceLayout"));
        kidneysLeftPlaceLabel = new QLabel(centralwidget);
        kidneysLeftPlaceLabel->setObjectName(QStringLiteral("kidneysLeftPlaceLabel"));
        QFont font2;
        font2.setPointSize(10);
        kidneysLeftPlaceLabel->setFont(font2);
        kidneysFrame4 = new QFrame;
        kidneysFrame4->setFrameShape( QFrame::Box );
        gridLayout->addWidget( kidneysFrame4, gridIndex, 0, 5, 1 );

        kidneysLeftPlaceCheck = new QCheckBox( "расположена низко" );
        QObject::connect( kidneysLeftPlaceCheck, &QCheckBox::stateChanged,
                          [&] {
                                            if ( !( kidneysLeftPlaceCheck->isChecked() ) ) kidneysLeftPlaceCheck->setText( "расположена низко" );
                                            if ( ( kidneysLeftPlaceCheck->isChecked() ) ) kidneysLeftPlaceCheck->setText( "расположена обычно" );
                               });

        kidneysLeftPlaceLayout->addWidget(kidneysLeftPlaceLabel);
        kidneysLeftPlaceLayout->addWidget( kidneysLeftPlaceCheck );

        kidneysLeftContourCheck1 = new QCheckBox(centralwidget);
        kidneysLeftContourCheck1->setObjectName(QStringLiteral("kidneysLeftContourCheck1"));
        QObject::connect( kidneysLeftContourCheck1, &QCheckBox::stateChanged,
                          [&] {
                                            if ( !( kidneysLeftContourCheck1->isChecked() ) ) kidneysLeftContourCheck1->setText("Контуры: нечеткие, ");
                                            if ( ( kidneysLeftContourCheck1->isChecked() ) ) kidneysLeftContourCheck1->setText("Контуры:    четкие, ");
                               });

        kidneysLeftPlaceLayout->addWidget(kidneysLeftContourCheck1);

        kidneysLeftContourCheck2 = new QCheckBox(centralwidget);
        kidneysLeftContourCheck2->setObjectName(QStringLiteral("kidneysLeftCountourCheck2"));
        QObject::connect( kidneysLeftContourCheck2, &QCheckBox::stateChanged,
                          [&] {
                                            if ( !( kidneysLeftContourCheck2->isChecked() ) ) kidneysLeftContourCheck2->setText("неровные");
                                            if ( ( kidneysLeftContourCheck2->isChecked() ) ) kidneysLeftContourCheck2->setText("   ровные");
                               });

        kidneysLeftPlaceLayout->addWidget( kidneysLeftContourCheck2 );


        gridLayout->addLayout(kidneysLeftPlaceLayout, gridIndex++, 0, Qt::AlignLeft );

        kidneysLeftSizeLayout = new QHBoxLayout();
        kidneysLeftSizeLayout->setObjectName(QStringLiteral("kidneysLeftSizeLayout"));
        kidneysLeftSizeCheck = new QCheckBox(centralwidget);
        kidneysLeftSizeCheck->setObjectName(QStringLiteral("kidneysLeftSizeCheck"));
        QObject::connect( kidneysLeftSizeCheck, &QCheckBox::stateChanged,
                          [&] {
                                            if ( !( kidneysLeftSizeCheck->isChecked() ) ) kidneysLeftSizeCheck->setText("Размеры: не увеличены");
                                            if ( ( kidneysLeftSizeCheck->isChecked() ) ) kidneysLeftSizeCheck->setText("Размеры:     увеличены");
                               });

        kidneysLeftSizeLayout->addWidget(kidneysLeftSizeCheck);

        kidneysLeftSizeLine = new QLineEdit(centralwidget);
        kidneysLeftSizeLine->setObjectName(QStringLiteral("kidneysLeftSizeLine"));

        kidneysLeftSizeLayout->addWidget( kidneysLeftSizeLine, 0, Qt::AlignLeft );

        kidneysLeftParenchymaLabel = new QLabel(centralwidget);
        kidneysLeftParenchymaLabel->setObjectName(QStringLiteral("kidneysLeftParenchymaLabel"));

        kidneysLeftSizeLayout->addWidget(kidneysLeftParenchymaLabel);

        kidneysLeftParenchymaSpin = new QSpinBox(centralwidget);
        kidneysLeftParenchymaSpin->setObjectName(QStringLiteral("kidneysLeftParenchymaSpin"));
        kidneysLeftParenchymaSpin->setMaximum(1000);
        kidneysLeftParenchymaSpin->clear();

        kidneysLeftSizeLayout->addWidget(kidneysLeftParenchymaSpin);


        gridLayout->addLayout(kidneysLeftSizeLayout, gridIndex++, 0, Qt::AlignLeft );

        kidneysLeftEchoLayout = new QHBoxLayout();
        kidneysLeftEchoLayout->setObjectName(QStringLiteral("kidneysLeftEchoLayout"));
        kidneysLeftEchoCheck = new QCheckBox(centralwidget);
        kidneysLeftEchoCheck->setObjectName(QStringLiteral("kidneysLeftEchoCheck"));
        QObject::connect( kidneysLeftEchoCheck, &QCheckBox::stateChanged,
                          [&] {
                                            if ( !( kidneysLeftEchoCheck->isChecked() ) ) kidneysLeftEchoCheck->setText("Эхоструктура паренхимы: неоднородная, ");
                                            if ( ( kidneysLeftEchoCheck->isChecked() ) ) kidneysLeftEchoCheck->setText("Эхоструктура паренхимы:    однородная, ");
                               });


        kidneysLeftEchoLayout->addWidget(kidneysLeftEchoCheck);

        kidneysLeftDiffCheck = new QCheckBox(centralwidget);
        kidneysLeftDiffCheck->setObjectName(QStringLiteral("kidneysLeftDiffCheck"));
        QObject::connect( kidneysLeftDiffCheck, &QCheckBox::stateChanged,
                          [&] {
                                            if ( !( kidneysLeftDiffCheck->isChecked() ) ) kidneysLeftDiffCheck->setText("кортико-медуллярная дифференциация: не выражена. ");
                                            if ( ( kidneysLeftDiffCheck->isChecked() ) ) kidneysLeftDiffCheck->setText("кортико-медуллярная дифференциация:     выражена.");
                               });


        kidneysLeftEchoLayout->addWidget(kidneysLeftDiffCheck);


        gridLayout->addLayout(kidneysLeftEchoLayout, gridIndex++, 0, Qt::AlignLeft );

        kidneysLeftCalyxCheck = new QCheckBox(centralwidget);
        //kidneysLeftCalyxCheck->setObjectName(QStringLiteral("kidneysLeftCalyxCheck"));
        QObject::connect( kidneysLeftCalyxCheck, &QCheckBox::stateChanged,
                          [&] {
                                            if ( !( kidneysLeftCalyxCheck->isChecked() ) ) kidneysLeftCalyxCheck->setText("Чашечно-лоханочная система: не расширена.");
                                            if ( ( kidneysLeftCalyxCheck->isChecked() ) ) kidneysLeftCalyxCheck->setText("Чашечно-лоханочная система:     расширена.");
                               });

        gridLayout->addWidget(kidneysLeftCalyxCheck, gridIndex++, 0, Qt::AlignLeft );


        kidneysLeftCalyxEdit = new QTextEdit;
        kidneysLeftCalyxEdit->setFixedSize( 670, 20 );
        kidneysLeftCalyxEdit->setMaximumSize( 700, 30 );
        gridLayout->addWidget( kidneysLeftCalyxEdit, gridIndex++, 0, Qt::AlignLeft );

        kidneysCDKCheck = new QCheckBox( "При ЦДК не регистрируется неизменный интраренальный кровоток с обеих сторон." );
        kidneysProectionCheck = new QCheckBox( "В проекции надпочечников патологических образований не выявлено." );
        QObject::connect( kidneysCDKCheck, &QCheckBox::stateChanged,
                          [&] {
                                            if ( !( kidneysCDKCheck->isChecked() ) ) kidneysCDKCheck->setText( "При ЦДК не регистрируется неизменный интраренальный кровоток с обеих сторон." );
                                            if ( ( kidneysCDKCheck->isChecked() ) ) kidneysCDKCheck->setText("При ЦДК   регистрируется неизменный интраренальный кровоток с обеих сторон.");
                               });
        QObject::connect( kidneysProectionCheck, &QCheckBox::stateChanged,
                          [&] {
                                            if ( !( kidneysProectionCheck->isChecked() ) ) kidneysProectionCheck->setText( "В проекции надпочечников патологических образований не выявлено." );
                                            if ( ( kidneysProectionCheck->isChecked() ) ) kidneysProectionCheck->setText( "В проекции надпочечников патологических образований    выявлено." );
                               });

        gridLayout->addWidget( kidneysCDKCheck, gridIndex++, 0, Qt::AlignLeft );
        gridLayout->addWidget( kidneysProectionCheck, gridIndex++, 0, Qt::AlignLeft );
        kidneysProectionEdit = new QTextEdit;

        gridLayout->addWidget( kidneysProectionEdit, gridIndex++, 0, Qt::AlignLeft );
        kidneysProectionEdit->setFixedSize( 670, 20 );
        kidneysProectionEdit->setMaximumSize( 700, 30 );

        kidneysConclusionLabel = new QLabel( "ЗАКЛЮЧЕНИЕ: " );
        kidneysConclusionText = new QTextEdit;
        kidneysConclusionText->setFixedSize( 670, 50 );
        kidneysConclusionText->setMaximumSize( 700, 50 );
        gridLayout->addWidget( kidneysConclusionLabel, gridIndex++, 0, Qt::AlignLeft );
        gridLayout->addWidget( kidneysConclusionText, gridIndex++, 0, Qt::AlignLeft );

        kidneysSaveAllButton = new QPushButton( "Сохранить документ" );
        gridLayout->addWidget( kidneysSaveAllButton, gridIndex++, 0, Qt::AlignCenter );

        gridLayout->setSpacing( 2 );

        QObject::connect( kidneysSaveAllButton, &QPushButton::clicked,
                          [&] {
                                                     pWord = new QAxObject( "Word.Application" );
                                                     pDocs = pWord->querySubObject( "Documents" );

                                                     dirDocKidneys = QCoreApplication::applicationDirPath() + "/template/uziKidneys.docx";

                                                     pDocs->dynamicCall( "Add([Template], [NewTemplate], [DocumentType], [Visible])", dirDocKidneys );

                                                     pWord->setProperty( "DiplayAlerts()", false );

                                                     replaceString( pWord, "kidneysNameLine", kidneysNameLine->text() );
                                                     replaceString( pWord, "kidneysAgeLine", kidneysAgeLine->text() );
                                                     replaceString( pWord, "kidneysDateEdit", kidneysDateEdit->text() );

                                                     //Мочевой пузырь
                                                     replaceString( pWord, "kidneysBladderSpin", kidneysBladderSpin->text() );
                                                     replaceString( pWord, "kidneysBladderContainsCheck", kidneysBladderContainsCheck->text() );
                                                     replaceString( pWord, "kidneysBladderWallsContourCheck", kidneysBladderWallsContourCheck->text() );
                                                     replaceString( pWord, "kidneysBladderWallsWideCheck", kidneysBladderWallsWideCheck->text() );
                                                     replaceString( pWord, "kidneysBladderDropsCheck", kidneysBladderDropsCheck->text() );


                                                     //Правая почка
                                                     replaceString( pWord, "kidneysRightContour1Ch", kidneysRightContourCheck1->text() );
                                                     replaceString( pWord, "kidneysRightContour2Ch", kidneysRightContourCheck2->text() );
                                                     replaceString( pWord, "kidneysRightSizeCheck", kidneysRightSizeCheck->text() );
                                                     replaceString( pWord, "kidneysrightSizeSpin", kidneysRightSizeLine->text() );
                                                     replaceString( pWord, "RightParenchymaSpin", kidneysRightParenchymaSpin->text() );
                                                     replaceString( pWord, "kidneysRightEchoCheck", kidneysRightEchoCheck->text() );
                                                     replaceString( pWord, "kidneysRightDiffCheck", kidneysRightDiffCheck->text() );
                                                     replaceString( pWord, "kidneysRightCalyxCheck", kidneysRightCalyxCheck->text() );
                                                     replaceString( pWord, "kidneysRightCalyxEdit", kidneysRightCalyxEdit->toPlainText() );


                                                     //Левая почка
                                                     replaceString( pWord, "kidneysLeftContour1Ch", kidneysLeftContourCheck1->text() );
                                                     replaceString( pWord, "kidneysLeftContour2Ch", kidneysLeftContourCheck2->text() );
                                                     replaceString( pWord, "kidneysLeftSizeCheck", kidneysLeftSizeCheck->text() );
                                                     replaceString( pWord, "kidneysLeftSizeSpin", kidneysLeftSizeLine->text() );
                                                     replaceString( pWord, "LeftParenchymaSpin", kidneysLeftParenchymaSpin->text() );
                                                     replaceString( pWord, "kidneysLeftEchoCheck", kidneysLeftEchoCheck->text() );
                                                     replaceString( pWord, "kidneysLeftDiffCheck", kidneysLeftDiffCheck->text() );
                                                     replaceString( pWord, "kidneysLeftCalyxCheck", kidneysLeftCalyxCheck->text() );
                                                     replaceString( pWord, "kidneysLeftCalyxEdit", kidneysLeftCalyxEdit->toPlainText() );


                                                     //Заключение и 2 чек-бокса
                                                     replaceString( pWord, "kidneysCDKCheck", kidneysCDKCheck->text() );
                                                     replaceString( pWord, "kidneysProectionCheck", kidneysProectionCheck->text() );
                                                     replaceString( pWord, "kidneysProectionEdit", kidneysProectionEdit->toPlainText() );
                                                     replaceString( pWord, "kidenysConclusionText", kidneysConclusionText->toPlainText() );

                                                     pWord->setProperty( "Visible", true );

                              } );


#ifndef QT_NO_SHORTCUT
        kidneysNameLabel->setBuddy(kidneysNameLine);
        kidneysAgeLabel->setBuddy(kidneysAgeLine);
        kidneysDateLabel->setBuddy(kidneysDateEdit);
        kidneysBladderLabel->setBuddy(kidneysBladderSpin);
        kidneysRightPlaceLabel->setBuddy(kidneysRightContourCheck1);
        kidneysRightParenchymaLabel->setBuddy(kidneysRightParenchymaSpin);
        kidneysLeftPlaceLabel->setBuddy(kidneysLeftContourCheck1);
        kidneysLeftParenchymaLabel->setBuddy(kidneysLeftParenchymaSpin);
#endif // QT_NO_SHORTCUT

        retranslateUi( centralwidget );

        QMetaObject::connectSlotsByName( centralwidget );
    } // setupUi

    void retranslateUi(QWidget *centralwidget)
    {
        centralwidget->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        kidneysNameLabel->setText(QApplication::translate("MainWindow", "\320\244\320\230\320\236: ", nullptr));
        kidneysNameLine->setText(QString());
        kidneysAgeLabel->setText(QApplication::translate("MainWindow", "\320\223\320\276\320\264 \321\200\320\276\320\266\320\264\320\265\320\275\320\270\321\217: ", nullptr));
        kidneysDateLabel->setText(QApplication::translate("MainWindow", "\320\224\320\260\321\202\320\260 \320\270\321\201\321\201\320\273\320\265\320\264\320\276\320\262\320\260\320\275\320\270\321\217: ", nullptr));
        kidneysDateEdit->setSpecialValueText(QString());
        kidneysMainLabel->setText(QApplication::translate("MainWindow", "\320\237\320\240\320\236\320\242\320\236\320\232\320\236\320\233 \320\243\320\233\320\254\320\242\320\240\320\220\320\227\320\222\320\243\320\232\320\236\320\222\320\236\320\223\320\236 \320\230\320\241\320\241\320\233\320\225\320\224\320\236\320\222\320\220\320\235\320\230\320\257 \320\237\320\236\320\247\320\225\320\232", nullptr));
        kidneysBladderLabel->setText(QApplication::translate("MainWindow", "\320\234\320\276\321\207\320\265\320\262\320\276\320\271 \320\277\321\203\320\267\321\213\321\200\321\214: ", nullptr));
        kidneysBladderSpin->setSuffix(QApplication::translate("MainWindow", " \321\201\320\274. \320\272\321\203\320\261.", nullptr));
        //kidneysBladderContainsCheck->setText(QApplication::translate("MainWindow", "\320\241\320\276\320\264\320\265\321\200\320\266\320\270\320\274\320\276\320\265: \320\276\320\264\320\275\320\276\321\200\320\276\320\264\320\275\320\276\320\265", nullptr));
        kidneysBladderWallsContourCheck->setText(QApplication::translate("MainWindow", "\320\241\321\202\320\265\320\275\320\272\320\270: \320\275\320\265\321\200\320\276\320\262\320\275\321\213\320\265, ", nullptr));
        kidneysBladderWallsWideCheck->setText(QApplication::translate("MainWindow", "\320\275\320\265 \321\203\321\202\320\276\320\273\321\211\320\265\320\275\321\213", nullptr));
        kidneysBladderDropsCheck->setText(QApplication::translate("MainWindow", "\320\234\320\276\321\207\320\265\321\202\320\276\321\207\320\275\320\270\320\272\320\276\320\262\321\213\320\265 \320\262\321\213\320\261\321\200\320\276\321\201\321\213: \320\275\320\265 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\321\213 \321\201 \320\276\320\261\320\265\320\270\321\205 \321\201\321\202\320\276\321\200\320\276\320\275", nullptr));
        kidneysRightPlaceLabel->setText( "Правая почка: " );
        kidneysRightContourCheck1->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\275\321\202\321\203\321\200\321\213 \320\275\320\265\321\207\320\265\321\202\320\272\320\270\320\265,", nullptr));
        kidneysRightContourCheck2->setText(QApplication::translate("MainWindow", "\320\275\320\265\321\200\320\276\320\262\320\275\321\213\320\265", nullptr));
        kidneysRightSizeCheck->setText(QApplication::translate("MainWindow", "\320\240\320\260\320\267\320\274\320\265\321\200\321\213: \320\275\320\265 \321\203\320\262\320\265\320\273\320\270\321\207\320\265\320\275\321\213", nullptr));
        kidneysRightSizeLine->setText( " мм" );
        kidneysRightParenchymaLabel->setText(QApplication::translate("MainWindow", "\320\237\320\260\321\200\320\265\320\275\321\205\320\270\320\274\320\260 \320\262 \321\201\321\200\320\265\320\264\320\275\320\265\320\274 \321\201\320\265\320\263\320\274\320\265\320\275\321\202\320\265 \321\202\320\276\320\273\321\211\320\270\320\275\320\276\320\271: ", nullptr));
        kidneysRightParenchymaSpin->setSuffix(QApplication::translate("MainWindow", " \320\274\320\274", nullptr));
        kidneysRightEchoCheck->setText(QApplication::translate("MainWindow", "\320\255\321\205\320\276\321\201\321\202\321\200\321\203\320\272\321\202\321\203\321\200\320\260 \320\277\320\260\321\200\320\265\320\275\321\205\320\270\320\274\321\213 \320\275\320\265\320\276\320\264\320\275\320\276\321\200\320\276\320\264\320\275\320\260\321\217, ", nullptr));
        kidneysRightDiffCheck->setText(QApplication::translate("MainWindow", "\320\272\320\276\321\200\321\202\320\270\320\272\320\276-\320\274\320\265\320\264\321\203\320\273\320\273\321\217\321\200\320\275\320\260\321\217 \320\264\320\270\321\204\321\204\320\265\321\200\320\265\320\275\321\206\320\270\320\260\321\206\320\270\321\217 \320\275\320\265 \320\262\321\213\321\200\320\260\320\266\320\265\320\275\320\260.", nullptr));
        kidneysRightCalyxCheck->setText(QApplication::translate("MainWindow", "\320\247\320\260\321\210\320\265\321\207\320\275\320\276-\320\273\320\276\321\205\320\260\320\275\320\276\321\207\320\275\320\260\321\217 \321\201\320\270\321\201\321\202\320\265\320\274\320\260 \320\275\320\265 \321\200\320\260\321\201\321\210\320\270\321\200\320\265\320\275\320\260.", nullptr));
        kidneysLeftPlaceLabel->setText( "Левая почка: " );
        kidneysLeftContourCheck1->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\275\321\202\321\203\321\200\321\213 \320\275\320\265\321\207\320\265\321\202\320\272\320\270\320\265,", nullptr));
        kidneysLeftContourCheck2->setText(QApplication::translate("MainWindow", "\320\275\320\265\321\200\320\276\320\262\320\275\321\213\320\265", nullptr));
        kidneysLeftSizeCheck->setText(QApplication::translate("MainWindow", "\320\240\320\260\320\267\320\274\320\265\321\200\321\213: \320\275\320\265 \321\203\320\262\320\265\320\273\320\270\321\207\320\265\320\275\321\213", nullptr));
        kidneysLeftSizeLine->setText( " мм" );
        kidneysLeftParenchymaLabel->setText(QApplication::translate("MainWindow", "\320\237\320\260\321\200\320\265\320\275\321\205\320\270\320\274\320\260 \320\262 \321\201\321\200\320\265\320\264\320\275\320\265\320\274 \321\201\320\265\320\263\320\274\320\265\320\275\321\202\320\265 \321\202\320\276\320\273\321\211\320\270\320\275\320\276\320\271: ", nullptr));
        kidneysLeftParenchymaSpin->setSuffix(QApplication::translate("MainWindow", " \320\274\320\274", nullptr));
        kidneysLeftEchoCheck->setText(QApplication::translate("MainWindow", "\320\255\321\205\320\276\321\201\321\202\321\200\321\203\320\272\321\202\321\203\321\200\320\260 \320\277\320\260\321\200\320\265\320\275\321\205\320\270\320\274\321\213 \320\275\320\265\320\276\320\264\320\275\320\276\321\200\320\276\320\264\320\275\320\260\321\217, ", nullptr));
        kidneysLeftDiffCheck->setText(QApplication::translate("MainWindow", "\320\272\320\276\321\200\321\202\320\270\320\272\320\276-\320\274\320\265\320\264\321\203\320\273\320\273\321\217\321\200\320\275\320\260\321\217 \320\264\320\270\321\204\321\204\320\265\321\200\320\265\320\275\321\206\320\270\320\260\321\206\320\270\321\217 \320\275\320\265 \320\262\321\213\321\200\320\260\320\266\320\265\320\275\320\260.", nullptr));
        kidneysLeftCalyxCheck->setText(QApplication::translate("MainWindow", "\320\247\320\260\321\210\320\265\321\207\320\275\320\276-\320\273\320\276\321\205\320\260\320\275\320\276\321\207\320\275\320\260\321\217 \321\201\320\270\321\201\321\202\320\265\320\274\320\260 \320\275\320\265 \321\200\320\260\321\201\321\210\320\270\321\200\320\265\320\275\320\260.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class kidneys: public kidneysForm {
    public:
        kidneys( QWidget* kidneysWidget ) {
            setupUi( kidneysWidget );
        }
    };
} // namespace Ui

QT_END_NAMESPACE

 // KIDNEYS_H

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
#endif
