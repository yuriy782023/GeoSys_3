QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_basedatetime.cpp \
    basedatetime.cpp

HEADERS += \
    basedatetime.h
