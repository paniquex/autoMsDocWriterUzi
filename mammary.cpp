/********************************************************************************
** Form generated from reading UI file 'mammary.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAMMARY_H
#define MAMMARY_H

#include <QtCore/QVariant>
#include <QtWidgets>
#include <QAxObject>
#include <QAxBase>
#include <QString>
#include <kidneys.cpp>

QT_BEGIN_NAMESPACE

class Ui_mammary
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *patientNameLayout;
    QLabel *patientNameLabel;
    QLineEdit *patientNameLine;
    QHBoxLayout *patientAgeLayout;
    QLabel *patientAgeLabel;
    QDateEdit *patientAgeDate;
    QHBoxLayout *researchDateLayout;
    QLabel *researchDateLabel;
    QDateEdit *researchDateDate;
    QLabel *protocallLabel;
    QLabel *rightMainLabel;
    QLabel *rightSizeLabel;
    QCheckBox *rightShapeCheck;
    QHBoxLayout *rightClothLayout;
    QLabel *rightClothLabel;
    QComboBox *rightClothCombo;
    QCheckBox *rightVisualCheck;
    QHBoxLayout *rightStreamLayout;
    QCheckBox *rightStreamCheck;
    QCheckBox *rightDiffCheck;
    QHBoxLayout *rightChangesLayout;
    QCheckBox *rightChangesCheck;
    QCheckBox *rightLymphoCheck;
    QLabel *leftMainLabel;
    QLabel *leftSizeLabel;
    QCheckBox *leftShapeCheck;
    QHBoxLayout *leftClothLayout;
    QLabel *leftClothLabel;
    QComboBox *leftClothCombo;
    QCheckBox *leftVisualCheck;
    QHBoxLayout *leftStreamLayout;
    QCheckBox *leftStreamCheck;
    QCheckBox *leftDiffCheck;
    QHBoxLayout *leftChangesLayout;
    QCheckBox *leftChangesCheck;
    QCheckBox *leftLymphoCheck;
    QLabel *mainConclusionLabel;
    QTextEdit *mainConclusionText;
    QPushButton *saveAllButton;
    QAxObject *pDocs;
    QAxObject *pWord;
    QString dirDocKidneys;
    QFrame *frame1;
    QFrame *frame2;
    QFrame *frame3;

    void setupUi(QWidget *mammary)
    {
        if (mammary->objectName().isEmpty())
            mammary->setObjectName(QStringLiteral("mammary"));
        mammary->resize(598, 513);
        gridLayout = new QGridLayout(mammary);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        patientNameLayout = new QHBoxLayout();
        patientNameLayout->setObjectName(QStringLiteral("patientNameLayout"));
        patientNameLabel = new QLabel(mammary);
        patientNameLabel->setObjectName(QStringLiteral("patientNameLabel"));

        patientNameLayout->addWidget(patientNameLabel);

        patientNameLine = new QLineEdit(mammary);
        patientNameLine->setObjectName(QStringLiteral("patientNameLine"));

        patientNameLayout->addWidget(patientNameLine);


        frame1 = new QFrame;
        frame1->setFrameShape( QFrame::Box );

        frame2 = new QFrame;
        frame2->setFrameShape( QFrame::Box );

        frame3 = new QFrame;
        frame3->setFrameShape( QFrame::Box );

        gridLayout->addWidget( frame1, 0, 0, 3, 1 );
        gridLayout->addWidget( frame2, 5, 0, 6, 1 );
        gridLayout->addWidget( frame3, 12, 0, 6, 1 );
        gridLayout->addLayout(patientNameLayout, 0, 0, Qt::AlignLeft);

        patientAgeLayout = new QHBoxLayout();
        patientAgeLayout->setObjectName(QStringLiteral("patientAgeLayout"));
        patientAgeLabel = new QLabel(mammary);
        patientAgeLabel->setObjectName(QStringLiteral("patientAgeLabel"));

        patientAgeLayout->addWidget(patientAgeLabel);

        patientAgeDate = new QDateEdit(mammary);
        patientAgeDate->setObjectName(QStringLiteral("patientAgeDate"));

        patientAgeLayout->addWidget(patientAgeDate);


        gridLayout->addLayout(patientAgeLayout, 1, 0, 1, 1);

        researchDateLayout = new QHBoxLayout();
        researchDateLayout->setObjectName(QStringLiteral("researchDateLayout"));
        researchDateLabel = new QLabel(mammary);
        researchDateLabel->setObjectName(QStringLiteral("researchDateLabel"));

        researchDateLayout->addWidget(researchDateLabel);

        researchDateDate = new QDateEdit(mammary);
        researchDateDate->setObjectName(QStringLiteral("researchDateDate"));

        researchDateLayout->addWidget(researchDateDate);


        gridLayout->addLayout(researchDateLayout, 2, 0, 1, 1);

        protocallLabel = new QLabel(mammary);
        protocallLabel->setObjectName(QStringLiteral("protocallLabel"));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(8);
        font.setBold(true);
        font.setWeight(75);
        protocallLabel->setFont(font);

        gridLayout->addWidget(protocallLabel, 3, 0, Qt::AlignLeft);

        rightMainLabel = new QLabel(mammary);
        rightMainLabel->setObjectName(QStringLiteral("rightMainLabel"));
        rightMainLabel->setFont(font);

        gridLayout->addWidget(rightMainLabel, 4, 0, Qt::AlignLeft);

        rightSizeLabel = new QLabel(mammary);
        rightSizeLabel->setObjectName(QStringLiteral("rightSizeLabel"));

        gridLayout->addWidget(rightSizeLabel, 5, 0, Qt::AlignLeft);

        rightShapeCheck = new QCheckBox( "Форма: обычная" );
        rightShapeCheck->setObjectName(QStringLiteral( "rightShapeCheck" ));

        QObject::connect( rightShapeCheck, &QCheckBox::stateChanged,
                          [&] {
                                            if ( !( rightShapeCheck->isChecked() ) ) rightShapeCheck->setText( "Форма: обычная" );
                                            if ( ( rightShapeCheck->isChecked() ) ) rightShapeCheck->setText("Форма: изменена");
                               });

        gridLayout->addWidget(rightShapeCheck, 6, 0, Qt::AlignLeft);

        rightClothLayout = new QHBoxLayout();
        rightClothLayout->setObjectName(QStringLiteral("rightClothLayout"));
        rightClothLabel = new QLabel(mammary);
        rightClothLabel->setObjectName(QStringLiteral("rightClothLabel"));

        rightClothLayout->addWidget(rightClothLabel);

        rightClothCombo = new QComboBox(mammary);
        rightClothCombo->addItem(QString());
        rightClothCombo->addItem(QString());
        rightClothCombo->addItem(QString());
        rightClothCombo->addItem(QString());
        rightClothCombo->setObjectName(QStringLiteral("rightClothCombo"));
        rightClothCombo->setEditable(false);
        rightClothCombo->setMinimumContentsLength(0);

        rightClothLayout->addWidget(rightClothCombo);


        gridLayout->addLayout(rightClothLayout, 7, 0, Qt::AlignLeft);

        rightVisualCheck = new QCheckBox(mammary);
        rightVisualCheck->setObjectName(QStringLiteral("rightVisualCheck"));
        QObject::connect( rightVisualCheck, &QCheckBox::stateChanged,
                          [&] {
                                            if ( !( rightVisualCheck->isChecked() ) ) rightVisualCheck->setText( "Визуализация протоков: плохая" );
                                            if ( ( rightVisualCheck->isChecked() ) ) rightVisualCheck->setText("Визуализация протоков: хорошая");
                               });

        gridLayout->addWidget(rightVisualCheck, 8, 0, Qt::AlignLeft);

        rightStreamLayout = new QHBoxLayout();
        rightStreamLayout->setObjectName(QStringLiteral("rightStreamLayout"));
        rightStreamCheck = new QCheckBox(mammary);
        rightStreamCheck->setObjectName(QStringLiteral("rightStreamCheck"));
        QObject::connect( rightStreamCheck, &QCheckBox::stateChanged,
                          [&] {
                                            if ( !( rightStreamCheck->isChecked() ) ) rightStreamCheck->setText( "Протоки: не расширены" );
                                            if ( ( rightStreamCheck->isChecked() ) ) rightStreamCheck->setText("Протоки:   расширены" );
                               });


        rightStreamLayout->addWidget(rightStreamCheck);

        rightDiffCheck = new QCheckBox(mammary);
        rightDiffCheck->setObjectName(QStringLiteral("rightDiffCheck"));
        QObject::connect( rightDiffCheck, &QCheckBox::stateChanged,
                          [&] {
                                            if ( !( rightDiffCheck->isChecked() ) ) rightDiffCheck->setText( "Диффузные изменения: нет" );
                                            if ( ( rightDiffCheck->isChecked() ) ) rightDiffCheck->setText("Диффузные изменения: есть");
                               });

        rightStreamLayout->addWidget(rightDiffCheck);


        gridLayout->addLayout(rightStreamLayout, 9, 0, Qt::AlignLeft);

        rightChangesLayout = new QHBoxLayout();
        rightChangesLayout->setObjectName(QStringLiteral("rightChangesLayout"));
        rightChangesCheck = new QCheckBox(mammary);
        rightChangesCheck->setObjectName(QStringLiteral("rightChangesCheck"));
        QObject::connect( rightChangesCheck, &QCheckBox::stateChanged,
                          [&] {
                                            if ( !( rightChangesCheck->isChecked() ) ) rightChangesCheck->setText( "Очаговые изменения: нет" );
                                            if ( ( rightChangesCheck->isChecked() ) ) rightChangesCheck->setText("Очаговые изменения: есть");
                               });

        rightChangesLayout->addWidget(rightChangesCheck);

        rightLymphoCheck = new QCheckBox(mammary);
        rightLymphoCheck->setObjectName(QStringLiteral("rightLymphoCheck"));
        QObject::connect( rightLymphoCheck, &QCheckBox::stateChanged,
                          [&] {
                                            if ( !( rightLymphoCheck->isChecked() ) ) rightLymphoCheck->setText( "Состояние региональных зон лимфооттока: не изменены" );
                                            if ( ( rightLymphoCheck->isChecked() ) ) rightLymphoCheck->setText( "Состояние региональных зон лимфооттока:    изменены" );
                               });

        rightChangesLayout->addWidget(rightLymphoCheck);


        gridLayout->addLayout(rightChangesLayout, 10, 0, Qt::AlignLeft);

        leftMainLabel = new QLabel(mammary);
        leftMainLabel->setObjectName(QStringLiteral("leftMainLabel"));
        leftMainLabel->setFont(font);

        gridLayout->addWidget(leftMainLabel, 11, 0, Qt::AlignLeft);

        leftSizeLabel = new QLabel(mammary);
        leftSizeLabel->setObjectName(QStringLiteral("leftSizeLabel"));

        gridLayout->addWidget(leftSizeLabel, 12, 0, Qt::AlignLeft);

        leftShapeCheck = new QCheckBox( "Форма: обычная" );
        leftShapeCheck->setObjectName(QStringLiteral( "leftShapeCheck" ));

        QObject::connect( leftShapeCheck, &QCheckBox::stateChanged,
                          [&] {
                                            if ( !( leftShapeCheck->isChecked() ) ) leftShapeCheck->setText( "Форма: обычная" );
                                            if ( ( leftShapeCheck->isChecked() ) ) leftShapeCheck->setText("Форма: изменена");
                               });

        gridLayout->addWidget(leftShapeCheck, 13, 0, Qt::AlignLeft);

        leftClothLayout = new QHBoxLayout();
        leftClothLayout->setObjectName(QStringLiteral("leftClothLayout"));
        leftClothLabel = new QLabel(mammary);
        leftClothLabel->setObjectName(QStringLiteral("leftClothLabel"));

        leftClothLayout->addWidget(leftClothLabel);

        leftClothCombo = new QComboBox(mammary);
        leftClothCombo->addItem(QString());
        leftClothCombo->addItem(QString());
        leftClothCombo->addItem(QString());
        leftClothCombo->addItem(QString());
        leftClothCombo->setObjectName(QStringLiteral("leftClothCombo"));
        leftClothCombo->setEditable(false);
        leftClothCombo->setMinimumContentsLength(0);

        leftClothLayout->addWidget(leftClothCombo);


        gridLayout->addLayout(leftClothLayout, 14, 0, Qt::AlignLeft);

        leftVisualCheck = new QCheckBox(mammary);
        leftVisualCheck->setObjectName(QStringLiteral("leftVisualCheck"));
        QObject::connect( leftVisualCheck, &QCheckBox::stateChanged,
                          [&] {
                                            if ( !( leftVisualCheck->isChecked() ) ) leftVisualCheck->setText( "Визуализация протоков: плохая" );
                                            if ( ( leftVisualCheck->isChecked() ) ) leftVisualCheck->setText("Визуализация протоков: хорошая");
                               });

        gridLayout->addWidget(leftVisualCheck, 15, 0, Qt::AlignLeft);

        leftStreamLayout = new QHBoxLayout();
        leftStreamLayout->setObjectName(QStringLiteral("leftStreamLayout"));
        leftStreamCheck = new QCheckBox(mammary);
        leftStreamCheck->setObjectName(QStringLiteral("leftStreamCheck"));
        QObject::connect( leftStreamCheck, &QCheckBox::stateChanged,
                          [&] {
                                            if ( !( leftStreamCheck->isChecked() ) ) leftStreamCheck->setText( "Протоки: не расширены" );
                                            if ( ( leftStreamCheck->isChecked() ) ) leftStreamCheck->setText("Протоки:   расширены" );
                               });


        leftStreamLayout->addWidget(leftStreamCheck);

        leftDiffCheck = new QCheckBox(mammary);
        leftDiffCheck->setObjectName(QStringLiteral("leftDiffCheck"));
        QObject::connect( leftDiffCheck, &QCheckBox::stateChanged,
                          [&] {
                                            if ( !( leftDiffCheck->isChecked() ) ) leftDiffCheck->setText( "Диффузные изменения: нет" );
                                            if ( ( leftDiffCheck->isChecked() ) ) leftDiffCheck->setText("Диффузные изменения: есть");
                               });

        leftStreamLayout->addWidget(leftDiffCheck);


        gridLayout->addLayout(leftStreamLayout, 16, 0, Qt::AlignLeft);

        leftChangesLayout = new QHBoxLayout();
        leftChangesLayout->setObjectName(QStringLiteral("leftChangesLayout"));
        leftChangesCheck = new QCheckBox(mammary);
        leftChangesCheck->setObjectName(QStringLiteral("leftChangesCheck"));
        QObject::connect( leftChangesCheck, &QCheckBox::stateChanged,
                          [&] {
                                            if ( !( leftChangesCheck->isChecked() ) ) leftChangesCheck->setText( "Очаговые изменения: нет" );
                                            if ( ( leftChangesCheck->isChecked() ) ) leftChangesCheck->setText("Очаговые изменения: есть");
                               });

        leftChangesLayout->addWidget(leftChangesCheck);

        leftLymphoCheck = new QCheckBox(mammary);
        leftLymphoCheck->setObjectName(QStringLiteral("leftLymphoCheck"));
        QObject::connect( leftLymphoCheck, &QCheckBox::stateChanged,
                          [&] {
                                            if ( !( leftLymphoCheck->isChecked() ) ) leftLymphoCheck->setText( "Состояние региональных зон лимфооттока: не изменены" );
                                            if ( ( leftLymphoCheck->isChecked() ) ) leftLymphoCheck->setText( "Состояние региональных зон лимфооттока:    изменены" );
                               });

        leftChangesLayout->addWidget(leftLymphoCheck);


        gridLayout->addLayout(leftChangesLayout, 17, 0, Qt::AlignLeft);

        mainConclusionLabel = new QLabel(mammary);
        mainConclusionLabel->setObjectName(QStringLiteral("mainConclusionLabel"));

        gridLayout->addWidget(mainConclusionLabel, 18, 0, Qt::AlignLeft);

        mainConclusionText = new QTextEdit(mammary);
        mainConclusionText->setObjectName(QStringLiteral("mainConclusionText"));
        mainConclusionText->setMinimumSize(QSize(650, 35));
        mainConclusionText->setMaximumSize(QSize(700, 50));

        gridLayout->addWidget(mainConclusionText, 19, 0, Qt::AlignLeft);

        saveAllButton = new QPushButton( "Сохранить документ" );
        saveAllButton->setFixedHeight( 20 );
        gridLayout->addWidget( saveAllButton, 20, 0, Qt::AlignRight );

        QObject::connect( saveAllButton, &QPushButton::clicked,
                          [&] {
                                                     pWord = new QAxObject( "Word.Application" );
                                                     pDocs = pWord->querySubObject( "Documents" );

                                                     dirDocKidneys = QCoreApplication::applicationDirPath() + "/template/uziMammary.docx";

                                                     pDocs->dynamicCall( "Add([Template], [NewTemplate], [DocumentType], [Visible])", dirDocKidneys );

                                                     pWord->setProperty( "DiplayAlerts()", false );

                                                     replaceString( pWord, "patientNameLine", patientNameLine->text() );
                                                     replaceString( pWord, "patientAgeDate", patientAgeDate->text() );
                                                     replaceString( pWord, "patientResearchDate", researchDateDate->text() );

                                                     replaceString( pWord, "rightShapeCheck", rightShapeCheck->text() );
                                                     replaceString( pWord, "rightClothCombo", rightClothCombo->currentText() );

                                                     replaceString( pWord, "rightVisualCheck", rightVisualCheck->text() );
                                                     replaceString( pWord, "rightStreamCheck", rightStreamCheck->text() );
                                                     replaceString( pWord, "rightDiffCheck", rightDiffCheck->text() );
                                                     replaceString( pWord, "rightChangesCheck", rightChangesCheck->text() );
                                                     replaceString( pWord, "rightLymphoCheck", rightLymphoCheck->text() );

                                                     replaceString( pWord, "leftShapeCheck", leftShapeCheck->text() );
                                                     replaceString( pWord, "leftClothCombo", leftClothCombo->currentText() );

                                                     replaceString( pWord, "leftVisualCheck", leftVisualCheck->text() );
                                                     replaceString( pWord, "leftStreamCheck", leftStreamCheck->text() );
                                                     replaceString( pWord, "leftDiffCheck", leftDiffCheck->text() );
                                                     replaceString( pWord, "leftChangesCheck", leftChangesCheck->text() );
                                                     replaceString( pWord, "leftLymphoCheck", leftLymphoCheck->text() );

                                                     replaceString( pWord, "mainConclusionText", mainConclusionText->toPlainText() );

                                                     pWord->setProperty( "Visible", true );

        } );

        rightClothCombo->setCurrentIndex(0);
        leftClothCombo->setCurrentIndex(0);

        retranslateUi(mammary);




        QMetaObject::connectSlotsByName(mammary);
    } // setupUi

    void retranslateUi(QWidget *mammary)
    {
        mammary->setWindowTitle(QApplication::translate("mammary", "Form", nullptr));
        patientNameLabel->setText(QApplication::translate("mammary", "\320\244\320\230\320\236", nullptr));
        patientAgeLabel->setText(QApplication::translate("mammary", "\320\223\320\276\320\264 \321\200\320\276\320\266\320\264\320\265\320\275\320\270\321\217:", nullptr));
        researchDateLabel->setText(QApplication::translate("mammary", "\320\224\320\260\321\202\320\260 \320\270\321\201\321\201\320\273\320\265\320\264\320\276\320\262\320\260\320\275\320\270\321\217:", nullptr));
        protocallLabel->setText(QApplication::translate("mammary", "\320\237\320\240\320\236\320\242\320\236\320\232\320\236\320\233 \320\243\320\233\320\254\320\242\320\240\320\220\320\227\320\222\320\243\320\232\320\236\320\222\320\236\320\223\320\236 \320\230\320\241\320\241\320\233\320\225\320\224\320\236\320\222\320\220\320\235\320\230\320\257 \320\234\320\236\320\233\320\236\320\247\320\235\320\253\320\245 \320\226\320\225\320\233\320\225\320\227", nullptr));
        rightMainLabel->setText(QApplication::translate("mammary", "\320\237\321\200\320\260\320\262\320\260\321\217 \320\274\320\276\320\273\320\276\321\207\320\275\320\260\321\217 \320\266\320\265\320\273\320\265\320\267\320\260:", nullptr));
        rightSizeLabel->setText(QApplication::translate("mammary", "\320\240\320\260\320\267\320\274\320\265\321\200: \321\201\321\200\320\265\320\264\320\275\320\270\320\271", nullptr));
        //rightShapeCheck->setText(QApplication::translate("mammary", "\320\244\320\276\321\200\320\274\320\260: \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\260", nullptr));
        rightClothLabel->setText(QApplication::translate("mammary", "\320\242\320\272\320\260\320\275\321\214, \321\204\320\276\321\200\320\274\320\270\321\200\321\203\321\216\321\211\320\260\321\217 \320\274\320\276\320\273\320\276\321\207\320\275\321\203\321\216 \320\266\320\265\320\273\320\265\320\267\321\203:", nullptr));
        rightClothCombo->setItemText(0, QApplication::translate("mammary", "\320\266\320\265\320\273\320\265\320\267\320\270\321\201\321\202\320\260\321\217", nullptr));
        rightClothCombo->setItemText(1, QApplication::translate("mammary", "\320\266\320\265\320\273\320\265\320\267\320\270\321\201\321\202\320\260\321\217 \320\270 \320\266\320\270\321\200\320\276\320\262\320\260\321\217", nullptr));
        rightClothCombo->setItemText(2, QApplication::translate("mammary", "\320\277\321\200\320\265\320\270\320\274\321\203\321\211\320\265\321\201\321\202\320\262\320\265\320\275\320\275\320\276 \320\266\320\270\321\200\320\276\320\262\320\260\321\217", nullptr));
        rightClothCombo->setItemText(3, QApplication::translate("mammary", "\320\266\320\270\321\200\320\276\320\262\320\260\321\217", nullptr));

        rightClothCombo->setCurrentText(QApplication::translate("mammary", "\320\266\320\265\320\273\320\265\320\267\320\270\321\201\321\202\320\260\321\217", nullptr));
        rightVisualCheck->setText(QApplication::translate("mammary", "\320\222\320\270\320\267\321\203\320\260\320\273\320\270\320\267\320\260\321\206\320\270\321\217 \320\277\321\200\320\276\321\202\320\276\320\272\320\276\320\262: \320\277\320\273\320\276\321\205\320\260\321\217", nullptr));
        rightStreamCheck->setText(QApplication::translate("mammary", "\320\237\321\200\320\276\321\202\320\276\320\272\320\270: \320\275\320\265 \321\200\320\260\321\201\321\210\320\270\321\200\320\265\320\275\321\213", nullptr));
        rightDiffCheck->setText(QApplication::translate("mammary", "\320\224\320\270\321\204\321\204\321\203\320\267\320\275\321\213\320\265 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217: \320\275\320\265\321\202", nullptr));
        rightChangesCheck->setText(QApplication::translate("mammary", "\320\236\321\207\320\260\320\263\320\276\320\262\321\213\320\265 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217: \320\275\320\265\321\202", nullptr));
        rightLymphoCheck->setText(QApplication::translate("mammary", "\320\241\320\276\321\201\321\202\320\276\321\217\320\275\320\270\320\265 \321\200\320\265\320\263\320\270\320\276\320\275\320\260\320\273\321\214\320\275\321\213\321\205 \320\267\320\276\320\275 \320\273\320\270\320\274\321\204\320\276\320\276\321\202\321\202\320\276\320\272\320\260: \320\275\320\265 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\321\213", nullptr));
        leftMainLabel->setText(QApplication::translate("mammary", "\320\233\320\265\320\262\320\260\321\217 \320\274\320\276\320\273\320\276\321\207\320\275\320\260\321\217 \320\266\320\265\320\273\320\265\320\267\320\260:", nullptr));
        leftSizeLabel->setText(QApplication::translate("mammary", "\320\240\320\260\320\267\320\274\320\265\321\200: \321\201\321\200\320\265\320\264\320\275\320\270\320\271", nullptr));
        //leftShapeCheck->setText(QApplication::translate("mammary", "\320\244\320\276\321\200\320\274\320\260: \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\260", nullptr));
        leftClothLabel->setText(QApplication::translate("mammary", "\320\242\320\272\320\260\320\275\321\214, \321\204\320\276\321\200\320\274\320\270\321\200\321\203\321\216\321\211\320\260\321\217 \320\274\320\276\320\273\320\276\321\207\320\275\321\203\321\216 \320\266\320\265\320\273\320\265\320\267\321\203:", nullptr));
        leftClothCombo->setItemText(0, QApplication::translate("mammary", "\320\266\320\265\320\273\320\265\320\267\320\270\321\201\321\202\320\260\321\217", nullptr));
        leftClothCombo->setItemText(1, QApplication::translate("mammary", "\320\266\320\265\320\273\320\265\320\267\320\270\321\201\321\202\320\260\321\217 \320\270 \320\266\320\270\321\200\320\276\320\262\320\260\321\217", nullptr));
        leftClothCombo->setItemText(2, QApplication::translate("mammary", "\320\277\321\200\320\265\320\270\320\274\321\203\321\211\320\265\321\201\321\202\320\262\320\265\320\275\320\275\320\276 \320\266\320\270\321\200\320\276\320\262\320\260\321\217", nullptr));
        leftClothCombo->setItemText(3, QApplication::translate("mammary", "\320\266\320\270\321\200\320\276\320\262\320\260\321\217", nullptr));

        leftClothCombo->setCurrentText(QApplication::translate("mammary", "\320\266\320\265\320\273\320\265\320\267\320\270\321\201\321\202\320\260\321\217", nullptr));
        leftVisualCheck->setText(QApplication::translate("mammary", "\320\222\320\270\320\267\321\203\320\260\320\273\320\270\320\267\320\260\321\206\320\270\321\217 \320\277\321\200\320\276\321\202\320\276\320\272\320\276\320\262: \320\277\320\273\320\276\321\205\320\260\321\217", nullptr));
        leftStreamCheck->setText(QApplication::translate("mammary", "\320\237\321\200\320\276\321\202\320\276\320\272\320\270: \320\275\320\265 \321\200\320\260\321\201\321\210\320\270\321\200\320\265\320\275\321\213", nullptr));
        leftDiffCheck->setText(QApplication::translate("mammary", "\320\224\320\270\321\204\321\204\321\203\320\267\320\275\321\213\320\265 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217: \320\275\320\265\321\202", nullptr));
        leftChangesCheck->setText(QApplication::translate("mammary", "\320\236\321\207\320\260\320\263\320\276\320\262\321\213\320\265 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217: \320\275\320\265\321\202", nullptr));
        leftLymphoCheck->setText(QApplication::translate("mammary", "\320\241\320\276\321\201\321\202\320\276\321\217\320\275\320\270\320\265 \321\200\320\265\320\263\320\270\320\276\320\275\320\260\320\273\321\214\320\275\321\213\321\205 \320\267\320\276\320\275 \320\273\320\270\320\274\321\204\320\276\320\276\321\202\321\202\320\276\320\272\320\260: \320\275\320\265 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\321\213", nullptr));
        mainConclusionLabel->setText(QApplication::translate("mammary", "\320\227\320\220\320\232\320\233\320\256\320\247\320\225\320\235\320\230\320\225:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mammary: public Ui_mammary {
    public:
        mammary( QWidget* wgt ) {
            setupUi( wgt );
        }
    };
} // namespace Ui

QT_END_NAMESPACE

#endif // MAMMARY_H
