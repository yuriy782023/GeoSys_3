QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_testerror.cpp \
    compareerror.cpp \
    error.cpp \
    sloterror.cpp

HEADERS += \
    compareerror.h \
    error.h \
    sloterror.h
