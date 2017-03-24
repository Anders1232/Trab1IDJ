compilador = g++
arquivoSaida = JOGO.out
LIBS = -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf
FLAGS= -std=c++11 -Wall -pedantic -fmax-errors=5
DebugOrRelease= -g
binFolder= bin
#DEBUG= -g
#RELEASE= -O3

#regra geral
executavel: bin $(binFolder)/Game.o $(binFolder)/Sprite.o $(binFolder)/State.o $(binFolder)/main.o
	$(compilador) $(binFolder)/Game.o $(binFolder)/Sprite.o $(binFolder)/State.o $(binFolder)/main.o $(FLAGS) $(LIBS) -o $(binFolder)/$(arquivoSaida) $(DebugOrRelease)

#cria o diretório onde ficará os compilados e copia os resources para lá
.PHONY: bin
bin:
	mkdir -p $(binFolder)
	cp -R img $(binFolder)/img

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

$(binFolder)/Game.o: Game.cpp Game.h Error.h
	$(compilador) Game.cpp $(FLAGS) -o $(binFolder)/Game.o -c $(DebugOrRelease)
$(binFolder)/Sprite.o: Sprite.cpp Sprite.h Game.h Error.h
	$(compilador) Sprite.cpp $(FLAGS) -o $(binFolder)/Sprite.o -c $(DebugOrRelease)
$(binFolder)/State.o: State.cpp State.h
	$(compilador) State.cpp $(FLAGS) -o $(binFolder)/State.o -c $(DebugOrRelease)
$(binFolder)/main.o: main.cpp Game.h
	$(compilador) $(FLAGS) main.cpp -o $(binFolder)/main.o -c $(DebugOrRelease)
clear:
	rm -rf *.o bin


