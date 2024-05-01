QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  \
    ../Error/error.cpp \
    ../Error/sloterror.cpp \
    comparefile.cpp \
    file.cpp \
    preparefile.cpp \
    tst_testfile.cpp


HEADERS += \
    ../Error/error.h \
    ../Error/sloterror.h \
    comparefile.h \
    file.h \
    preparefile.h

