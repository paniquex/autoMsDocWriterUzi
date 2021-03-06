/********************************************************************************
** Form generated from reading UI file 'thyroid.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef THYROID_H
#define THYROID_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <QtWidgets/QPushButton>
#include <QAxObject>
#include <QAxBase>
#include <QString>
#include <kidneys.cpp>

QT_BEGIN_NAMESPACE


class Ui_thyroid
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *patientNameLayout;
    QLabel *patientNameLabel;
    QLineEdit *patientNameLine;
    QHBoxLayout *patientAgeLayout;
    QLabel *patientAgeLabel;
    QDateEdit *patientAgeDate;
    QHBoxLayout *patientResearchLayout;
    QLabel *patientResearchLabel;
    QDateEdit *patientResearchDate;
    QLabel *protocallLabel;
    QCheckBox *rightShareCheck;
    QHBoxLayout *rightShareLayout;
    QLabel *rightShareSizeLabel;
    QHBoxLayout *rightShareSizeSpinLayout;
    QVBoxLayout *rightShareSizeLayout;
    QLabel *rightShareLengthLabel;
    QLabel *rightShareWideLabel;
    QLabel *rightShareThicknessLabe;
    QLabel *rightShareVolumeLabel;
    QVBoxLayout *rightShareSpinLayout;
    QSpinBox *rightShareLengthSpin;
    QSpinBox *rightShareWideSpin;
    QSpinBox *rightShareThicknessSpin;
    QDoubleSpinBox *rightShareVolumeSpin;
    QCheckBox *leftShareCheck;
    QHBoxLayout *leftShareLayout;
    QLabel *leftShareSizeLabel;
    QHBoxLayout *leftShareSizeSpinLayout;
    QVBoxLayout *leftShareSizeLayout;
    QLabel *leftShareLengthLabel;
    QLabel *leftShareWideLabel;
    QLabel *leftShareThicknessLabel;
    QLabel *leftShareVolumeLabel;
    QVBoxLayout *leftShareSpinLayout;
    QSpinBox *leftShareLengthSpin;
    QSpinBox *leftShareWideSpin;
    QSpinBox *leftShareThicknessSpin;
    QDoubleSpinBox *leftShareVolumeSpin;
    QHBoxLayout *neckThicknessLayout;
    QLabel *neckThicknessLabel;
    QDoubleSpinBox *neckThicknessSpin;
    QHBoxLayout *volumeLayout;
    QLabel *volumeLabel;
    QDoubleSpinBox *volumeSpin;
    QLabel *volumeNormalLabel;
    QHBoxLayout *echogenLayout;
    QLabel *echogenLabel;
    QRadioButton *echogenMidRadio;
    QRadioButton *echogenUpRadio;
    QRadioButton *echogenDownRadio;
    QHBoxLayout *structureLayout;
    QCheckBox *structureCheck;
    QCheckBox *contourCheck;
    QHBoxLayout *creaturesLayout;
    QCheckBox *creaturesCheck;
    QTextEdit *creaturesEdit;
    QCheckBox *neckLymphoCheck;
    QTextEdit *neckLymphoEdit;
    QLabel *mainConclusionLabel;
    QTextEdit *mainConclusionText;
    QButtonGroup *echogenGroup;
    QPushButton *saveAllButton;
    QAxObject *pDocs;
    QAxObject *pWord;
    QString dirDocKidneys;
    QFrame* frame1;
    QFrame* frame2;
    QFrame* frame3;
    QFrame* frame4;

    void setupUi(QWidget *thyroid)
    {


        if (thyroid->objectName().isEmpty())
            thyroid->setObjectName(QStringLiteral("thyroid"));
        thyroid->resize(522, 642);
        thyroid->setMinimumSize(QSize(0, 0));
        thyroid->setMaximumSize(QSize(700, 800));
        gridLayout = new QGridLayout(thyroid);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setVerticalSpacing( 2 );
        frame1 = new QFrame;
        frame1->setFrameShape( QFrame::Box );

        gridLayout->addWidget( frame1, 0, 0, 3, 1 );

        frame2 = new QFrame;
        frame2->setFrameShape( QFrame::Box );
        gridLayout->addWidget( frame2, 4, 0, 2, 1 );

        frame3 = new QFrame;
        frame3->setFrameShape( QFrame::Box );
        gridLayout->addWidget( frame3, 6, 0, 2 , 1 );

        frame4 = new QFrame;
        frame4->setFrameShape( QFrame::Box );
        gridLayout->addWidget( frame4, 8, 0, 8, 1 );

        patientNameLayout = new QHBoxLayout();
        patientNameLayout->setObjectName(QStringLiteral("patientNameLayout"));
        patientNameLabel = new QLabel(thyroid);
        patientNameLabel->setObjectName(QStringLiteral("patientNameLabel"));

        patientNameLayout->addWidget(patientNameLabel);

        patientNameLine = new QLineEdit(thyroid);
        patientNameLine->setObjectName(QStringLiteral("patientNameLine"));
        patientNameLine->setFixedSize( 644, 15 );
        patientNameLayout->addWidget(patientNameLine, 0, Qt::AlignLeft );

        gridLayout->addLayout(patientNameLayout, 0, 0, Qt::AlignLeft );

        patientAgeLayout = new QHBoxLayout();
        patientAgeLayout->setObjectName(QStringLiteral("patientAgeLayout"));
        patientAgeLabel = new QLabel(thyroid);
        patientAgeLabel->setObjectName(QStringLiteral("patientAgeLabel"));

        patientAgeLayout->addWidget(patientAgeLabel);

        patientAgeDate = new QDateEdit(thyroid);
        patientAgeDate->setObjectName(QStringLiteral("patientAgeDate"));
        patientAgeDate->setFixedWidth( 330 );


        patientAgeLayout->addWidget(patientAgeDate, 1, Qt::AlignRight );


        gridLayout->addLayout(patientAgeLayout, 1, 0, Qt::AlignLeft );

        patientResearchLayout = new QHBoxLayout();
        patientResearchLayout->setObjectName(QStringLiteral("patientResearchLayout"));
        patientResearchLabel = new QLabel(thyroid);
        patientResearchLabel->setObjectName(QStringLiteral("patientResearchLabel"));

        patientResearchLayout->addWidget(patientResearchLabel);

        patientResearchDate = new QDateEdit(thyroid);
        patientResearchDate->setObjectName(QStringLiteral("patientResearchDate"));
        patientResearchDate->setFixedWidth( 330 );
        patientResearchDate->setDate( QDate::currentDate() );

        patientResearchLayout->addWidget (patientResearchDate, 1, Qt::AlignRight );


        gridLayout->addLayout(patientResearchLayout, 2, 0, Qt::AlignLeft);

        protocallLabel = new QLabel(thyroid);
        protocallLabel->setObjectName(QStringLiteral("protocallLabel"));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(7);
        font.setBold(true);
        font.setWeight(75);
        protocallLabel->setFont(font);
        protocallLabel->setFixedSize( 720, 15 );

        gridLayout->addWidget(protocallLabel, 3, 0, Qt::AlignHCenter );

        rightShareCheck = new QCheckBox(thyroid);
        rightShareCheck->setObjectName(QStringLiteral("rightShareCheck"));
        QObject::connect( rightShareCheck, &QCheckBox::stateChanged,
                          [&] {
                                            if ( !( rightShareCheck->isChecked() ) ) rightShareCheck->setText( "Правая доля не увеличена" );
                                            if ( ( rightShareCheck->isChecked() ) ) rightShareCheck->setText( "Правая доля   увеличена" );
                               });


        gridLayout->addWidget( rightShareCheck, 4, 0, Qt::AlignLeft );

        rightShareLayout = new QHBoxLayout();
        rightShareLayout->setObjectName(QStringLiteral("rightShareLayout"));
        rightShareSizeLabel = new QLabel(thyroid);
        rightShareSizeLabel->setObjectName(QStringLiteral("rightShareSizeLabel"));
        rightShareSizeLabel->setLayoutDirection(Qt::LeftToRight);

        rightShareLayout->addWidget(rightShareSizeLabel);

        rightShareSizeSpinLayout = new QHBoxLayout();
        rightShareSizeSpinLayout->setObjectName(QStringLiteral("rightShareSizeSpinLayout"));
        rightShareSizeLayout = new QVBoxLayout();
        rightShareSizeLayout->setObjectName(QStringLiteral("rightShareSizeLayout"));
        rightShareLengthLabel = new QLabel(thyroid);
        rightShareLengthLabel->setObjectName(QStringLiteral("rightShareLengthLabel"));

        rightShareSizeLayout->addWidget(rightShareLengthLabel);

        rightShareWideLabel = new QLabel(thyroid);
        rightShareWideLabel->setObjectName(QStringLiteral("rightShareWideLabel"));

        rightShareSizeLayout->addWidget(rightShareWideLabel);

        rightShareThicknessLabe = new QLabel(thyroid);
        rightShareThicknessLabe->setObjectName(QStringLiteral("rightShareThicknessLabe"));

        rightShareSizeLayout->addWidget(rightShareThicknessLabe);

        rightShareVolumeLabel = new QLabel(thyroid);
        rightShareVolumeLabel->setObjectName(QStringLiteral("rightShareVolumeLabel"));

        rightShareSizeLayout->addWidget(rightShareVolumeLabel);


        rightShareSizeSpinLayout->addLayout(rightShareSizeLayout);

        rightShareSpinLayout = new QVBoxLayout();
        rightShareSpinLayout->setObjectName(QStringLiteral("rightShareSpinLayout"));
        rightShareLengthSpin = new QSpinBox(thyroid);
        rightShareLengthSpin->setObjectName(QStringLiteral("rightShareLengthSpin"));
        rightShareLengthSpin->setMaximum(1000);
        rightShareLengthSpin->clear();

        rightShareSpinLayout->addWidget(rightShareLengthSpin);

        rightShareWideSpin = new QSpinBox(thyroid);
        rightShareWideSpin->setObjectName(QStringLiteral("rightShareWideSpin"));
        rightShareWideSpin->setMaximum(1000);
        rightShareWideSpin->clear();

        rightShareSpinLayout->addWidget(rightShareWideSpin);

        rightShareThicknessSpin = new QSpinBox(thyroid);
        rightShareThicknessSpin->setObjectName(QStringLiteral("rightShareThicknessSpin"));
        rightShareThicknessSpin->setMaximum(1000);
        rightShareThicknessSpin->clear();

        rightShareSpinLayout->addWidget(rightShareThicknessSpin);

        rightShareVolumeSpin = new QDoubleSpinBox(thyroid);
        rightShareVolumeSpin->setObjectName(QStringLiteral("rightShareVolumeSpin"));
        rightShareVolumeSpin->setDecimals(1);
        rightShareVolumeSpin->setSingleStep( 0.1 );
        rightShareVolumeSpin->setMaximum(1000);
        rightShareVolumeSpin->clear();

        rightShareSpinLayout->addWidget(rightShareVolumeSpin);


        rightShareSizeSpinLayout->addLayout(rightShareSpinLayout);


        rightShareLayout->addLayout(rightShareSizeSpinLayout);


        gridLayout->addLayout(rightShareLayout, 5, 0, Qt::AlignLeft);

        leftShareCheck = new QCheckBox(thyroid);
        leftShareCheck->setObjectName(QStringLiteral("leftShareCheck"));
        QObject::connect( leftShareCheck, &QCheckBox::stateChanged,
                          [&] {
                                            if ( !( leftShareCheck->isChecked() ) ) leftShareCheck->setText( "Левая доля не увеличена" );
                                            if ( ( leftShareCheck->isChecked() ) ) leftShareCheck->setText("Левая доля   увеличена");
                               });

        gridLayout->addWidget(leftShareCheck, 6, 0, Qt::AlignLeft);

        leftShareLayout = new QHBoxLayout();
        leftShareLayout->setObjectName(QStringLiteral("leftShareLayout"));
        leftShareSizeLabel = new QLabel(thyroid);
        leftShareSizeLabel->setObjectName(QStringLiteral("leftShareSizeLabel"));
        leftShareSizeLabel->setLayoutDirection(Qt::LeftToRight);

        leftShareLayout->addWidget(leftShareSizeLabel);

        leftShareSizeSpinLayout = new QHBoxLayout();
        leftShareSizeSpinLayout->setObjectName(QStringLiteral("leftShareSizeSpinLayout"));
        leftShareSizeLayout = new QVBoxLayout();
        leftShareSizeLayout->setObjectName(QStringLiteral("leftShareSizeLayout"));
        leftShareLengthLabel = new QLabel(thyroid);
        leftShareLengthLabel->setObjectName(QStringLiteral("leftShareLengthLabel"));

        leftShareSizeLayout->addWidget(leftShareLengthLabel);

        leftShareWideLabel = new QLabel(thyroid);
        leftShareWideLabel->setObjectName(QStringLiteral("leftShareWideLabel"));

        leftShareSizeLayout->addWidget(leftShareWideLabel);

        leftShareThicknessLabel = new QLabel(thyroid);
        leftShareThicknessLabel->setObjectName(QStringLiteral("leftShareThicknessLabel"));

        leftShareSizeLayout->addWidget(leftShareThicknessLabel);

        leftShareVolumeLabel = new QLabel(thyroid);
        leftShareVolumeLabel->setObjectName(QStringLiteral("leftShareVolumeLabel"));

        leftShareSizeLayout->addWidget(leftShareVolumeLabel);


        leftShareSizeSpinLayout->addLayout(leftShareSizeLayout);

        leftShareSpinLayout = new QVBoxLayout();
        leftShareSpinLayout->setObjectName(QStringLiteral("leftShareSpinLayout"));
        leftShareLengthSpin = new QSpinBox(thyroid);
        leftShareLengthSpin->setObjectName(QStringLiteral("leftShareLengthSpin"));
        leftShareLengthSpin->setMaximum(1000);
        leftShareLengthSpin->clear();

        leftShareSpinLayout->addWidget(leftShareLengthSpin);

        leftShareWideSpin = new QSpinBox(thyroid);
        leftShareWideSpin->setObjectName(QStringLiteral("leftShareWideSpin"));
        leftShareWideSpin->setMaximum(1000);
        leftShareWideSpin->clear();

        leftShareSpinLayout->addWidget(leftShareWideSpin);

        leftShareThicknessSpin = new QSpinBox(thyroid);
        leftShareThicknessSpin->setObjectName(QStringLiteral("leftShareThicknessSpin"));
        leftShareThicknessSpin->setMaximum(1000);
        leftShareThicknessSpin->clear();

        leftShareSpinLayout->addWidget(leftShareThicknessSpin);

        leftShareVolumeSpin = new QDoubleSpinBox(thyroid);
        leftShareVolumeSpin->setObjectName(QStringLiteral("leftShareVolumeSpin"));
        leftShareVolumeSpin->setDecimals(1);
        leftShareVolumeSpin->setSingleStep( 0.1 );
        leftShareVolumeSpin->setMaximum(1000);
        leftShareVolumeSpin->clear();

        leftShareSpinLayout->addWidget(leftShareVolumeSpin);


        leftShareSizeSpinLayout->addLayout(leftShareSpinLayout);


        leftShareLayout->addLayout(leftShareSizeSpinLayout);


        gridLayout->addLayout(leftShareLayout, 7, 0, Qt::AlignLeft);

        neckThicknessLayout = new QHBoxLayout();
        neckThicknessLayout->setObjectName(QStringLiteral("neckThicknessLayout"));
        neckThicknessLabel = new QLabel(thyroid);
        neckThicknessLabel->setFixedHeight( 15 );
        neckThicknessLabel->setObjectName(QStringLiteral("neckThicknessLabel"));

        neckThicknessLayout->addWidget(neckThicknessLabel);

        neckThicknessSpin = new QDoubleSpinBox(thyroid);
        neckThicknessSpin->setMaximumHeight( 15 );
        neckThicknessSpin->setSingleStep( 0.1 );
        neckThicknessSpin->setDecimals( 1 );
        neckThicknessSpin->setObjectName(QStringLiteral("neckThicknessSpin"));
        neckThicknessSpin->setMaximum(1000);
        neckThicknessSpin->clear();

        neckThicknessLayout->addWidget(neckThicknessSpin);
        gridLayout->addLayout(neckThicknessLayout, 8, 0, Qt::AlignTop | Qt::AlignLeft );

        volumeLayout = new QHBoxLayout();
        volumeLayout->setObjectName(QStringLiteral("volumeLayout"));
        volumeLabel = new QLabel(thyroid);
        volumeLabel->setMaximumHeight( 15 );
        volumeLabel->setObjectName(QStringLiteral("volumeLabel"));

        volumeLayout->addWidget(volumeLabel);

        volumeSpin = new QDoubleSpinBox(thyroid);
        volumeSpin->setMaximumHeight( 15 );
        volumeSpin->setObjectName(QStringLiteral("volumeSpin"));
        volumeSpin->setMaximum(1000);
        volumeSpin->setSingleStep(0.1);
        volumeSpin->setDecimals( 1 );
        volumeSpin->clear();

        volumeLayout->addWidget( volumeSpin );

        volumeNormalLabel = new QLabel(thyroid);
        volumeNormalLabel->setFixedHeight( 15 );
        volumeNormalLabel->setObjectName(QStringLiteral("volumeNormalLabel"));

        volumeLayout->addWidget(volumeNormalLabel);


        gridLayout->addLayout(volumeLayout, 9, 0, Qt::AlignTop | Qt::AlignLeft );

        echogenLayout = new QHBoxLayout();
        echogenLayout->setObjectName(QStringLiteral("echogenLayout"));
        echogenLabel = new QLabel(thyroid);
        echogenLabel->setObjectName(QStringLiteral("echogenLabel"));

        echogenLayout->addWidget(echogenLabel);

        echogenMidRadio = new QRadioButton(thyroid);
        echogenGroup = new QButtonGroup(thyroid);
        echogenGroup->setObjectName(QStringLiteral("echogenGroup"));
        echogenGroup->addButton(echogenMidRadio);
        echogenMidRadio->setObjectName(QStringLiteral("echogenMidRadio"));

        echogenLayout->addWidget(echogenMidRadio);

        echogenUpRadio = new QRadioButton(thyroid);
        echogenGroup->addButton(echogenUpRadio);
        echogenUpRadio->setObjectName(QStringLiteral("echogenUpRadio"));

        echogenLayout->addWidget(echogenUpRadio);

        echogenDownRadio = new QRadioButton(thyroid);
        echogenGroup->addButton(echogenDownRadio);
        echogenDownRadio->setObjectName(QStringLiteral("echogenDownRadio"));

        echogenLayout->addWidget(echogenDownRadio);


        gridLayout->addLayout(echogenLayout, 10, 0, Qt::AlignLeft);

        structureLayout = new QHBoxLayout();
        structureLayout->setObjectName(QStringLiteral("structureLayout"));
        structureCheck = new QCheckBox(thyroid);
        structureCheck->setObjectName(QStringLiteral("structureCheck"));
        QObject::connect( structureCheck, &QCheckBox::stateChanged,
                          [&] {
                                            if ( !( structureCheck->isChecked() ) ) structureCheck->setText("Структура: неоднородная");
                                            if ( ( structureCheck->isChecked() ) ) structureCheck->setText("Структура: однородная");
                               });

        structureLayout->addWidget(structureCheck);

        contourCheck = new QCheckBox(thyroid);
        contourCheck->setObjectName(QStringLiteral("contourCheck"));
        QObject::connect( contourCheck, &QCheckBox::stateChanged,
                          [&] {
                                            if ( !( contourCheck->isChecked() ) ) contourCheck->setText("Контуры: неровные");
                                            if ( ( contourCheck->isChecked() ) ) contourCheck->setText("Контуры: ровные");
                               });

        structureLayout->addWidget(contourCheck);


        gridLayout->addLayout(structureLayout, 11, 0, Qt::AlignLeft);

        creaturesLayout = new QHBoxLayout();
        creaturesLayout->setObjectName(QStringLiteral("creaturesLayout"));
        creaturesCheck = new QCheckBox(thyroid);
        creaturesCheck->setObjectName(QStringLiteral("creaturesCheck"));
        QObject::connect( creaturesCheck, &QCheckBox::stateChanged,
                          [&] {
                                            if ( !( creaturesCheck->isChecked() ) ) creaturesCheck->setText("Очаговые образования: нет");
                                            if ( ( creaturesCheck->isChecked() ) ) creaturesCheck->setText("Очаговвые образования: есть");
                               });

        creaturesLayout->addWidget(creaturesCheck);

        neckLymphoCheck = new QCheckBox(thyroid);
        neckLymphoCheck->setObjectName(QStringLiteral("neckLymphoCheck"));
        QObject::connect( neckLymphoCheck, &QCheckBox::stateChanged,
                          [&] {
                                            if ( !( neckLymphoCheck->isChecked() ) ) neckLymphoCheck->setText("Шейные лимфоузлы: не изменены");
                                            if ( ( neckLymphoCheck->isChecked() ) ) neckLymphoCheck->setText("Шейные лимфоузлы: изменены");
                               });

        creaturesEdit = new QTextEdit();
        neckLymphoEdit = new QTextEdit();

        creaturesEdit->setMinimumSize(QSize(650, 20));
        creaturesEdit->setMaximumSize(QSize(700, 30));
        neckLymphoEdit->setMinimumSize(QSize(650, 20));
        neckLymphoEdit->setMaximumSize(QSize(700, 30));

        gridLayout->addLayout( creaturesLayout, 12, 0, Qt::AlignLeft);
        gridLayout->addWidget( creaturesEdit, 13, 0, Qt::AlignLeft );
        gridLayout->addWidget( neckLymphoCheck, 14, 0, Qt::AlignLeft );
        gridLayout->addWidget( neckLymphoEdit, 15, 0, Qt::AlignLeft );





        mainConclusionLabel = new QLabel(thyroid);
        mainConclusionLabel->setObjectName(QStringLiteral("mainConclusionLabel"));

        gridLayout->addWidget(mainConclusionLabel, 16, 0, Qt::AlignLeft);

        mainConclusionText = new QTextEdit(thyroid);
        mainConclusionText->setObjectName(QStringLiteral("mainConclusionText"));
        mainConclusionText->setMinimumSize(QSize(650, 35));
        mainConclusionText->setMaximumSize(QSize(700, 50));

        gridLayout->addWidget(mainConclusionText, 17, 0, Qt::AlignLeft );

        saveAllButton = new QPushButton( "Сохранить документ" );
        gridLayout->addWidget( saveAllButton, 18, 0, Qt::AlignCenter );
        gridLayout->setSpacing( 4 );


        QObject::connect( saveAllButton, &QPushButton::clicked,
                          [&] {
                                                     pWord = new QAxObject( "Word.Application" );
                                                     pDocs = pWord->querySubObject( "Documents" );

                                                     dirDocKidneys = QCoreApplication::applicationDirPath() + "/template/uziThyroid.docx";

                                                     pDocs->dynamicCall( "Add([Template], [NewTemplate], [DocumentType], [Visible])", dirDocKidneys );

                                                     pWord->setProperty( "DiplayAlerts()", false );

                                                     replaceString( pWord, "patientNameLine", patientNameLine->text() );
                                                     replaceString( pWord, "patientAgeDate", patientAgeDate->text() );
                                                     replaceString( pWord, "patientResearchDate", patientResearchDate->text() );

                                                     replaceString( pWord, "rightShareCheck", rightShareCheck->text() );
                                                     replaceString( pWord, "rightShareLengthSpin", rightShareLengthSpin->text() );
                                                     replaceString( pWord, "rightShareWideSpin", rightShareWideSpin->text() );
                                                     replaceString( pWord, "rightShareThicknessSpin", rightShareThicknessSpin->text() );
                                                     replaceString( pWord, "rightShareVolumeSpin", rightShareVolumeSpin->text() );

                                                     replaceString( pWord, "leftShareCheck", leftShareCheck->text() );
                                                     replaceString( pWord, "leftShareLengthSpin", leftShareLengthSpin->text() );
                                                     replaceString( pWord, "leftShareWideSpin", leftShareWideSpin->text() );
                                                     replaceString( pWord, "leftShareThicknessSpin", leftShareThicknessSpin->text() );
                                                     replaceString( pWord, "leftShareVolumeSpin", leftShareVolumeSpin->text() );

                                                     replaceString( pWord, "neckThicknessSpin", neckThicknessSpin->text() );
                                                     replaceString( pWord, "volumeSpin", volumeSpin->text() );
                                                     replaceString( pWord, "volumeNormalLabel", volumeNormalLabel->text() );

                                                     if ( echogenMidRadio->isChecked() )
                                                     {
                                                         replaceString( pWord, "echogenRadio", echogenMidRadio->text() );
                                                     }
                                                     else if ( echogenUpRadio->isChecked() )
                                                     {
                                                         replaceString( pWord, "echogenRadio", echogenUpRadio->text() );
                                                     }
                                                     else
                                                     {
                                                         replaceString( pWord, "echogenRadio", echogenDownRadio->text() );
                                                     }

                                                     replaceString( pWord, "structureCheck", structureCheck->text() );
                                                     replaceString( pWord, "contourCheck", contourCheck->text() );
                                                     replaceString( pWord, "creaturesCheck", creaturesCheck->text() );
                                                     replaceString( pWord, "creaturesEdit", creaturesEdit->toPlainText() );
                                                     replaceString( pWord, "neckLymphoCheck", neckLymphoCheck->text() );
                                                     replaceString( pWord, "neckLymphoEdit", neckLymphoEdit->toPlainText() );

                                                     replaceString( pWord, "mainConclusionText", mainConclusionText->toPlainText() );

                                                     pWord->setProperty( "Visible", true );


                        });




        retranslateUi(thyroid);

        QMetaObject::connectSlotsByName(thyroid);
    } // setupUi

    void retranslateUi(QWidget *thyroid)
    {
        thyroid->setWindowTitle(QApplication::translate("thyroid", "Form", nullptr));
        patientNameLabel->setText(QApplication::translate("thyroid", "\320\244\320\230\320\236:", nullptr));
        patientAgeLabel->setText(QApplication::translate("thyroid", "\320\223\320\276\320\264 \321\200\320\276\320\266\320\264\320\265\320\275\320\270\321\217:", nullptr));
        patientResearchLabel->setText(QApplication::translate("thyroid", "\320\224\320\260\321\202\320\260 \320\270\321\201\321\201\320\273\320\265\320\264\320\276\320\262\320\260\320\275\320\270\321\217", nullptr));
        protocallLabel->setText(QApplication::translate("thyroid", "\320\237\320\240\320\236\320\242\320\236\320\232\320\236\320\233 \320\243\320\233\320\254\320\242\320\240\320\220\320\227\320\222\320\243\320\232\320\236\320\222\320\236\320\223\320\236 \320\230\320\241\320\241\320\233\320\225\320\224\320\236\320\222\320\220\320\235\320\230\320\257 \320\251\320\230\320\242\320\236\320\222\320\230\320\224\320\235\320\236\320\231 \320\226\320\225\320\233\320\225\320\227\320\253", nullptr));
        rightShareCheck->setText(QApplication::translate("thyroid", "\320\237\321\200\320\260\320\262\320\260\321\217 \320\264\320\276\320\273\321\217 \320\275\320\265 \321\203\320\262\320\265\320\273\320\270\321\207\320\265\320\275\320\260", nullptr));
        rightShareSizeLabel->setText(QApplication::translate("thyroid", "\320\240\320\260\320\267\320\274\320\265\321\200\321\213:", nullptr));
        rightShareLengthLabel->setText(QApplication::translate("thyroid", "\320\224\320\273\320\270\320\275\320\260:", nullptr));
        rightShareWideLabel->setText(QApplication::translate("thyroid", "\320\250\320\270\321\200\320\270\320\275\320\260:", nullptr));
        rightShareThicknessLabe->setText(QApplication::translate("thyroid", "\320\242\320\276\320\273\321\211\320\270\320\275\320\260", nullptr));
        rightShareVolumeLabel->setText(QApplication::translate("thyroid", "\320\236\320\261\321\212\320\265\320\274 \320\277\321\200\320\260\320\262\320\276\320\271 \320\264\320\276\320\273\320\270: ", nullptr));
        rightShareLengthSpin->setSuffix(QApplication::translate("thyroid", " (\320\274\320\274)", nullptr));
        rightShareWideSpin->setSuffix(QApplication::translate("thyroid", " (\320\274\320\274)", nullptr));
        rightShareThicknessSpin->setSuffix(QApplication::translate("thyroid", " (\320\274\320\274)", nullptr));
        rightShareVolumeSpin->setSuffix(QApplication::translate("thyroid", " \321\201\320\274.\320\272\321\203\320\261", nullptr));
        leftShareCheck->setText( "Левая доля не увеличена" );
        leftShareSizeLabel->setText(QApplication::translate("thyroid", "\320\240\320\260\320\267\320\274\320\265\321\200\321\213:", nullptr));
        leftShareLengthLabel->setText(QApplication::translate("thyroid", "\320\224\320\273\320\270\320\275\320\260:", nullptr));
        leftShareWideLabel->setText(QApplication::translate("thyroid", "\320\250\320\270\321\200\320\270\320\275\320\260:", nullptr));
        leftShareThicknessLabel->setText(QApplication::translate("thyroid", "\320\242\320\276\320\273\321\211\320\270\320\275\320\260", nullptr));
        leftShareVolumeLabel->setText(QApplication::translate("thyroid", "\320\236\320\261\321\212\320\265\320\274 \320\273\320\265\320\262\320\276\320\271 \320\264\320\276\320\273\320\270: ", nullptr));
        leftShareLengthSpin->setSuffix(QApplication::translate("thyroid", " (\320\274\320\274)", nullptr));
        leftShareWideSpin->setSuffix(QApplication::translate("thyroid", " (\320\274\320\274)", nullptr));
        leftShareThicknessSpin->setSuffix(QApplication::translate("thyroid", " (\320\274\320\274)", nullptr));
        leftShareVolumeSpin->setSuffix(QApplication::translate("thyroid", " \321\201\320\274.\320\272\321\203\320\261", nullptr));
        neckThicknessLabel->setText(QApplication::translate("thyroid", "\320\242\320\276\320\273\321\211\320\270\320\275\320\260 \320\277\320\265\321\200\320\265\321\210\320\265\320\271\320\272\320\260:", nullptr));
        neckThicknessSpin->setSuffix(QApplication::translate("thyroid", " \320\274\320\274", nullptr));
        neckThicknessSpin->setPrefix(QString());
        volumeLabel->setText(QApplication::translate("thyroid", "\320\236\320\261\321\211\320\270\320\271 \320\276\320\261\321\212\320\265\320\274: ", nullptr));
        volumeSpin->setPrefix(QString());
        volumeSpin->setSuffix(QApplication::translate("thyroid", " \321\201\320\274. \320\272\321\203\320\261.", nullptr));
        volumeNormalLabel->setText(QApplication::translate("thyroid", "( \320\275\320\276\321\200\320\274\320\260 4,4-18 \321\201\320\274. \320\272\321\203\320\261. )", nullptr));
        echogenLabel->setText(QApplication::translate("thyroid", "\320\255\321\205\320\276\320\263\320\265\320\275\320\275\320\276\321\201\321\202\321\214: ", nullptr));
        echogenMidRadio->setText(QApplication::translate("thyroid", "\321\201\321\200\320\265\320\264\320\275\321\217\321\217", nullptr));
        echogenUpRadio->setText(QApplication::translate("thyroid", "\320\277\320\276\320\262\321\213\321\210\320\265\320\275\320\260", nullptr));
        echogenDownRadio->setText(QApplication::translate("thyroid", "\320\277\320\276\320\275\320\270\320\266\320\265\320\275\320\260", nullptr));
        structureCheck->setText(QApplication::translate("thyroid", "\320\241\321\202\321\200\321\203\320\272\321\202\321\203\321\200\320\260: \320\275\320\265\320\276\320\264\320\275\320\276\321\200\320\276\320\264\320\275\320\260\321\217", nullptr));
        contourCheck->setText(QApplication::translate("thyroid", "\320\232\320\276\320\275\321\202\321\203\321\200\321\213: \320\275\320\265\321\200\320\276\320\262\320\275\321\213\320\265", nullptr));
        creaturesCheck->setText(QApplication::translate("thyroid", "\320\236\321\207\320\260\320\263\320\276\320\262\321\213\320\265 \320\276\320\261\321\200\320\260\320\267\320\276\320\262\320\260\320\275\320\270\321\217: \320\275\320\265\321\202", nullptr));
        neckLymphoCheck->setText(QApplication::translate("thyroid", "\320\250\320\265\320\271\320\275\321\213\320\265 \320\273\320\270\320\274\321\204\320\276\321\203\320\267\321\213: \320\275\320\265 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\321\213", nullptr));
        mainConclusionLabel->setText(QApplication::translate("thyroid", "\320\227\320\220\320\232\320\233\320\256\320\247\320\225\320\235\320\230\320\225: ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class thyroid: public Ui_thyroid {
    public:
        thyroid( QWidget* wgt )
        {
             setupUi( wgt );
        }
    };
} // namespace Ui

QT_END_NAMESPACE

#endif // THYROID_H
