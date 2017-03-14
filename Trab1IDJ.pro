TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Game.cpp \
    Sprite.cpp \
    State.cpp

TARGET = JOGO

QMAKE_CXXFLAGS += -finline-functions -Wall -pedantic -std=c++11
QMAKE_CFLAGS += -finline-functions -Wall -pedantic -std=c99

QMAKE_CFLAGS_RELEASE += -O3
QMAKE_CXXFLAGS_RELEASE += -O3

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    Game.h \
    Error.h \
    Sprite.h \
    State.h

LIBS += -lSDL2 -lSDL2_image

