TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Game.cpp \
    Sprite.cpp \
    State.cpp \
    Gameobject.cpp \
    RectOp.cpp \
    Vec2.cpp \
    Face.cpp \
    Tileset.cpp \
    TileMap.cpp

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
    State.h \
    Gameobject.h \
    RectOp.h \
    Vec2.h \
    Face.h \
    Tileset.h \
    TileMap.h

LIBS += -lSDL2 -lSDL2_image

