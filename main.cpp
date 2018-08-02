#include <QApplication>
#include <QtWidgets>
#include <QLineEdit>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget wgt;

    QLineEdit* patientName = new QLineEdit;
    QLabel* labelName = new QLabel( "ФИО пациента: " );

    QVBoxLayout* mainLayout = new QVBoxLayout;
    QHBoxLayout* nameLayout = new QHBoxLayout;
    nameLayout->addWidget( labelName );
    nameLayout->addWidget( patientName );
    mainLayout->addLayout( nameLayout );
    wgt.setLayout( mainLayout );

    wgt.show();


    return a.exec();
}
