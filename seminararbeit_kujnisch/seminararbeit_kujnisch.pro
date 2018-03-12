TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Console.cpp \
    Game.cpp \
    Menu.cpp

DISTFILES += \
    ../consoles.xml \
    ../games.xml \
    ../consoles.dtd \
    ../games.dtd

data.path = $$OUT_PWD/

data.files += $$PWD/*.dat

data.files += $$PWD/*.xml

data.files += $$PWD/*.dtd

INSTALLS += data

HEADERS += \
    header.h
