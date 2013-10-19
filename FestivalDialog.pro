#-------------------------------------------------
#
# Project created by QtCreator 2013-10-19T00:00:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FestivalDialog
TEMPLATE = app


SOURCES += main.cpp\
        festivaldialog.cpp

HEADERS  += festivaldialog.h

QMAKE_CXXFLAGS += -Wno-ignored-qualifiers

unix:!macx: LIBS += -L$$PWD/../../../opt/festival-2.1/festival/src/lib/ -lFestival
INCLUDEPATH += $$PWD/../../../opt/festival-2.1/festival/src/include
DEPENDPATH += $$PWD/../../../opt/festival-2.1/festival/src/include
unix:!macx: PRE_TARGETDEPS += $$PWD/../../../opt/festival-2.1/festival/src/lib/libFestival.a

unix:!macx: LIBS += -L$$PWD/../../../opt/festival-2.1/speech_tools/lib/ -lestools
INCLUDEPATH += $$PWD/../../../opt/festival-2.1/speech_tools/include
DEPENDPATH += $$PWD/../../../opt/festival-2.1/speech_tools/include
unix:!macx: PRE_TARGETDEPS += $$PWD/../../../opt/festival-2.1/speech_tools/lib/libestools.a

unix:!macx: LIBS += -L$$PWD/../../../opt/festival-2.1/speech_tools/lib/ -lestbase
INCLUDEPATH += $$PWD/../../../opt/festival-2.1/speech_tools/include
DEPENDPATH += $$PWD/../../../opt/festival-2.1/speech_tools/include
unix:!macx: PRE_TARGETDEPS += $$PWD/../../../opt/festival-2.1/speech_tools/lib/libestbase.a

unix:!macx: LIBS += -L$$PWD/../../../opt/festival-2.1/speech_tools/lib/ -leststring
INCLUDEPATH += $$PWD/../../../opt/festival-2.1/speech_tools/include
DEPENDPATH += $$PWD/../../../opt/festival-2.1/speech_tools/include
unix:!macx: PRE_TARGETDEPS += $$PWD/../../../opt/festival-2.1/speech_tools/lib/libeststring.a

unix:!macx: LIBS += -L$$PWD/../../../usr/lib/ -lncurses
INCLUDEPATH += $$PWD/../../../usr/include
DEPENDPATH += $$PWD/../../../usr/include

unix:!macx: LIBS += -L$$PWD/../../../usr/lib/ -lasound
INCLUDEPATH += $$PWD/../../../usr/include
DEPENDPATH += $$PWD/../../../usr/include
