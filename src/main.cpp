#include <iostream>
#include"Game.h"
#include "StageState.h"

using std::cout;
using std::endl;

int main(int argc, char **argv)
{
	Game game(std::string("Francisco Anderson 11/0117964"), 1024, 600);
	game.Push(new StageState());
	game.Run();
	return 0;
}

