#-------------------------------------------------
#
# Project created by QtCreator 2018-08-02T09:42:10
#
#-------------------------------------------------

QT       += core gui widgets axcontainer

VERSION = 1.0.0.1
QMAKE_TARGET_COMPANY = Paniquex
QMAKE_TARGET_PRODUCT = Pattern Word Changer
QMAKE_TARGET_DESCRIPTION = It automatized filling word document
QMAKE_TARGET_COPYRIGHT = Nikita Kuzmin

TARGET = docTest1
TEMPLATE = app


# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
    patient.cpp \
    formofliver.cpp \
    kidneys.cpp \
    newpatientform.cpp \
    thyroid.cpp \
    mammary.cpp

HEADERS += \
    patient.h \
    formofliver.h \
    newpatientform.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
    kidneys.ui \
    thyroid.ui \
    mammary.ui
