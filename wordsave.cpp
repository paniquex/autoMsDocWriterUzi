#include "wordsave.h"
#include "formofliver.h"
#include <QtWidgets>
#include <QAxObject>

wordSave::wordSave()
{

}


void wordSave::slotLiverSaveAll() {
        QAxObject* pWord = new QAxObject( "Word.Application");
        QAxObject* pDocs = pWord->querySubObject( "Documents" );
        pDocs = pDocs->querySubObject( "Add()" );
        QAxObject* pRange = pDocs->querySubObject( "Range()" );

       // pRange->dynamicCall( "SetRange( int, int )", 50, 100);
       // pRange->setProperty( "Text", "Hello, Qt Word" );

    //Заголовок
        QAxObject* rangeHeadText = pDocs->querySubObject( "Range()" );
        rangeHeadText->dynamicCall( "Setrange( int, int )", 30, 500 );
        extern formOfLiver liverForm;

        //rangeHeadText->setProperty( "Text", "АО \"Группа компаний Медси\"\nПациент: " + liverForm.patientName->text() );

        pWord->setProperty( "Visible", true );


       // pNewDoc->querySubObject( Op)
    }
