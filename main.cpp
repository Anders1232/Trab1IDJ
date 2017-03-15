#include <iostream>
#include"Game.h"
#include<stdlib.h>
#include<time.h>

using std::cout;
using std::endl;

int main(int argc, char **argv)
{
	srand(time(NULL));
	Game game(std::string("Francisco Anderson 11/0117964"), 1024, 600);
	game.Run();
	return 0;
}

