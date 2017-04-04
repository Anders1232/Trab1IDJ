compilador = g++
arquivoSaida = JOGO.out
LIBS = -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf
FLAGS= -std=c++11 -Wall -pedantic -fmax-errors=5
DebugOrRelease= -g #-Ofast -mtune=native
binFolder= bin
#DEBUG= -g
#RELEASE= -O3
incFldr= include
srcFldr= src
INCLUDE_FLAGS= -I$(incFldr)


#regra geral
executavel: \
		bin $(binFolder)/Game.o\
		$(binFolder)/Sprite.o\
		$(binFolder)/State.o\
		$(binFolder)/main.o\
		$(binFolder)/Camera.o\
		$(binFolder)/InputManager.o\
		$(binFolder)/Alien.o\
		$(binFolder)/Resources.o\
		$(binFolder)/TileMap.o\
		$(binFolder)/Tileset.o\
		$(binFolder)/Vec2.o\
		$(binFolder)/Gameobject.o\
		$(binFolder)/Rect.o\
		$(binFolder)/Minion.o\
		$(binFolder)/Bullet.o\
		$(binFolder)/Timer.o\
		$(binFolder)/Animation.o\
		$(binFolder)/Penguins.o
	$(compilador)\
		$(binFolder)/Game.o\
		$(binFolder)/Sprite.o\
		$(binFolder)/State.o\
		$(binFolder)/InputManager.o\
		$(binFolder)/Camera.o\
		$(binFolder)/main.o\
		$(binFolder)/Alien.o\
		$(binFolder)/Resources.o\
		$(binFolder)/TileMap.o\
		$(binFolder)/Tileset.o\
		$(binFolder)/Vec2.o\
		$(binFolder)/Gameobject.o\
		$(binFolder)/Rect.o\
		$(binFolder)/Minion.o\
		$(binFolder)/Bullet.o\
		$(binFolder)/Timer.o\
		$(binFolder)/Animation.o\
		$(binFolder)/Penguins.o\
		$(FLAGS) $(LIBS) -o $(binFolder)/$(arquivoSaida) $(DebugOrRelease)

#cria o diretório onde ficará os compilados e copia os resources para lá
.PHONY: bin
bin:
	mkdir -p $(binFolder)
#	cp -R assets $(binFolder)

#desfaz tudo que algum make fez e faz denovo
.PHONY: all
all: clear executavel

.PHONY: gcc
gcc:
	$(eval compilador = gcc)
	$(eval flags += -lstdc++)
.PHONY: windows
windows:
	$(eval arquivoSaida = -o JOGO.exe)

$(binFolder)/Game.o: \
		$(srcFldr)/Game.cpp\
		$(binFolder)/Alien.o\
		$(incFldr)/Game.h\
		$(incFldr)/Resources.h\
		$(incFldr)/Error.h
	$(compilador)\
		$(srcFldr)/Game.cpp\
		$(FLAGS) -o $(binFolder)/Game.o -c $(DebugOrRelease) -I$(incFldr)
$(binFolder)/Sprite.o:\
		$(srcFldr)/Sprite.cpp\
		$(incFldr)/Sprite.h\
		$(incFldr)/Game.h\
		$(incFldr)/Error.h
	$(compilador)\
		$(srcFldr)/Sprite.cpp\
		$(FLAGS) -o $(binFolder)/Sprite.o -c $(DebugOrRelease) -I$(incFldr)
$(binFolder)/State.o:\
		$(srcFldr)/State.cpp\
		$(incFldr)/State.h\
		$(incFldr)/Sprite.h\
		$(incFldr)/Gameobject.h\
		$(incFldr)/Tileset.h\
		$(incFldr)/TileMap.h\
		$(incFldr)/InputManager.h
	$(compilador)\
		$(srcFldr)/State.cpp\
		$(FLAGS) -o $(binFolder)/State.o -c $(DebugOrRelease) -I$(incFldr)
$(binFolder)/main.o:\
		$(srcFldr)/main.cpp\
		$(incFldr)/Game.h
	$(compilador)\
		$(srcFldr)/main.cpp\
		$(FLAGS) -o $(binFolder)/main.o -c $(DebugOrRelease) -I$(incFldr)
$(binFolder)/Camera.o:\
		$(srcFldr)/Camera.cpp\
		$(incFldr)/Camera.h\
		$(incFldr)/Gameobject.h\
		$(incFldr)/Vec2.h
	$(compilador)\
		$(srcFldr)/Camera.cpp\
		$(FLAGS) -o $(binFolder)/Camera.o -c $(DebugOrRelease) -I$(incFldr)
$(binFolder)/InputManager.o:\
		$(srcFldr)/InputManager.cpp\
		$(incFldr)/InputManager.h
	$(compilador)\
		$(srcFldr)/InputManager.cpp\
		$(FLAGS) -o $(binFolder)/InputManager.o -c $(DebugOrRelease) -I$(incFldr)
$(binFolder)/Alien.o:\
		$(srcFldr)/Alien.cpp\
		$(incFldr)/Alien.h\
		$(incFldr)/Minion.h\
		$(incFldr)/Gameobject.h\
		$(incFldr)/Sprite.h\
		$(incFldr)/Vec2.h
	$(compilador)\
		$(srcFldr)/Alien.cpp\
		$(FLAGS) -o $(binFolder)/Alien.o -c $(DebugOrRelease) -I$(incFldr)
$(binFolder)/Resources.o:\
		$(srcFldr)/Resources.cpp\
		$(incFldr)/Resources.h\
		$(incFldr)/Error.h\
		$(incFldr)/Game.h
	$(compilador)\
		$(srcFldr)/Resources.cpp\
		$(FLAGS) -o $(binFolder)/Resources.o -c $(DebugOrRelease) -I$(incFldr)
$(binFolder)/Tileset.o:\
		$(srcFldr)/Tileset.cpp\
		$(incFldr)/Tileset.h\
		$(incFldr)/Error.h\
		$(incFldr)/Sprite.h
	$(compilador)\
		$(srcFldr)/Tileset.cpp\
		$(FLAGS) -o $(binFolder)/Tileset.o -c $(DebugOrRelease) -I$(incFldr)
$(binFolder)/TileMap.o:\
		$(srcFldr)/TileMap.cpp\
		$(incFldr)/TileMap.h\
		$(incFldr)/Tileset.h\
		$(incFldr)/Error.h
	$(compilador)\
		$(srcFldr)/TileMap.cpp\
		$(FLAGS) -o $(binFolder)/TileMap.o -c $(DebugOrRelease) -I$(incFldr)
$(binFolder)/Vec2.o:\
		$(srcFldr)/Vec2.cpp\
		$(incFldr)/Vec2.h\
		$(incFldr)/Error.h
	$(compilador)\
		$(srcFldr)/Vec2.cpp\
		$(FLAGS) -o $(binFolder)/Vec2.o -c $(DebugOrRelease) -I$(incFldr)
$(binFolder)/Gameobject.o:\
		$(srcFldr)/Gameobject.cpp\
		$(incFldr)/Gameobject.h\
		$(incFldr)/Rect.h
	$(compilador)\
		$(srcFldr)/Gameobject.cpp\
		$(FLAGS) -o $(binFolder)/Gameobject.o -c $(DebugOrRelease) -I$(incFldr)
$(binFolder)/Rect.o:\
		$(srcFldr)/Rect.cpp\
		$(incFldr)/Rect.h\
		$(incFldr)/Error.h\
		$(incFldr)/Vec2.h
	$(compilador)\
		$(srcFldr)/Rect.cpp\
		$(FLAGS) -o $(binFolder)/Rect.o -c $(DebugOrRelease) -I$(incFldr)
$(binFolder)/Minion.o:\
		$(srcFldr)/Minion.cpp\
		$(incFldr)/Minion.h\
		$(incFldr)/Error.h\
		$(incFldr)/Vec2.h\
		$(incFldr)/Gameobject.h\
		$(incFldr)/Sprite.h\
		$(incFldr)/Camera.h\
		$(incFldr)/InputManager.h\
		$(incFldr)/Bullet.h\
		$(incFldr)/Game.h
	$(compilador)\
		$(srcFldr)/Minion.cpp\
		$(FLAGS) -o $(binFolder)/Minion.o -c $(DebugOrRelease) -I$(incFldr)
$(binFolder)/Bullet.o:\
		$(srcFldr)/Bullet.cpp\
		$(incFldr)/Bullet.h\
		$(incFldr)/Error.h\
		$(incFldr)/Vec2.h\
		$(incFldr)/Sprite.h\
		$(incFldr)/Gameobject.h\
		$(incFldr)/Camera.h
	$(compilador)\
		$(srcFldr)/Bullet.cpp\
		$(FLAGS) -o $(binFolder)/Bullet.o -c $(DebugOrRelease) -I$(incFldr)
$(binFolder)/Penguins.o:\
		$(srcFldr)/Penguins.cpp\
		$(incFldr)/Penguins.h\
		$(incFldr)/Error.h\
		$(incFldr)/Vec2.h\
		$(incFldr)/Sprite.h\
		$(incFldr)/Gameobject.h\
		$(incFldr)/Camera.h\
		$(incFldr)/Timer.h\
		$(incFldr)/InputManager.h\
		$(incFldr)/Bullet.h\
		$(incFldr)/Animation.h
	$(compilador)\
		$(srcFldr)/Penguins.cpp\
		$(FLAGS) -o $(binFolder)/Penguins.o -c $(DebugOrRelease) -I$(incFldr)
$(binFolder)/Animation.o:\
		$(srcFldr)/Animation.cpp\
		$(incFldr)/Animation.h\
		$(incFldr)/Error.h\
		$(incFldr)/Vec2.h\
		$(incFldr)/Sprite.h\
		$(incFldr)/Gameobject.h\
		$(incFldr)/Camera.h\
		$(incFldr)/Timer.h\
		$(incFldr)/Animation.h
	$(compilador)\
		$(srcFldr)/Animation.cpp\
		$(FLAGS) -o $(binFolder)/Animation.o -c $(DebugOrRelease) -I$(incFldr)
$(binFolder)/Timer.o:\
		$(srcFldr)/Timer.cpp\
		$(incFldr)/Timer.h
	$(compilador)\
		$(srcFldr)/Timer.cpp\
		$(FLAGS) -o $(binFolder)/Timer.o -c $(DebugOrRelease) -I$(incFldr)


clear:
	rm -rf *.o bin


