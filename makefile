SOURCE_FILES= main.cpp \
    Game.cpp \
    Sprite.cpp \
    State.cpp \
    Gameobject.cpp \
    RectOp.cpp \
    Vec2.cpp \
    Face.cpp \
    Tileset.cpp
LIS = -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf
FLAGS= -std=c++11 -Wall -pedantic -fmax-errors=5
DEBUG= -g
RELEASE= -O3

COMPILER= g++
COM
