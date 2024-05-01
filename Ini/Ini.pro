QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_ini.cpp \
            ini.cpp \
            prepareini.cpp \
            compareini.cpp \
            ../File/file.cpp \
            ../Error/error.cpp \
            ../Error/sloterror.cpp \
            ../File/preparefile.cpp \
            ../File/comparefile.cpp

HEADERS +=  ini.h \
            prepareini.h \
            compareini.h \
            ../File/file.h \
            ../Error/error.h \
            ../Error/sloterror.h \
            ../File/preparefile.h \
            ../File/comparefile.h

