TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += source/main.cpp \
	source/Game.cpp \
	source/Sprite.cpp \
	source/State.cpp \
	source/Gameobject.cpp \
	source/RectOp.cpp \
	source/Vec2.cpp \
	source/Tileset.cpp \
	source/TileMap.cpp \
	source/Resources.cpp \
	source/InputManager.cpp \
	source/Camera.cpp \
	source/Alien.cpp \
	source/Minion.cpp

TARGET = JOGO

QMAKE_CXXFLAGS += -Wall -pedantic -std=c++11
QMAKE_CFLAGS += -Wall -pedantic -std=c99

QMAKE_CXXFLAGS_DEBUG += -g
QMAKE_CFLAGS_DEBUG += -g

QMAKE_CFLAGS_RELEASE += -O3
QMAKE_CXXFLAGS_RELEASE += -O3

include(deployment.pri)
qtcAddDeployment()

INCLUDEPATH += include/

HEADERS += \
	include/Game.h \
	include/Error.h \
	include/Sprite.h \
	include/State.h \
	include/Gameobject.h \
	include/RectOp.h \
	include/Vec2.h \
	include/Tileset.h \
	include/TileMap.h \
	include/Resources.h \
	include/InputManager.h \
	include/Camera.h \
	include/Alien.h \
	include/Minion.h

LIBS += -lSDL2 -lSDL2_image

