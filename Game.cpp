#include "Game.h"

#define ErrorMsg(msg)std::cerr << "[ERROR] " << __FILE__ << " | " << __func__ << ":" << __LINE__ << "\t\t" << msg << endl
#define ERROR_PREFIX  "[ERROR] "<< __FILE__<<" | "<< __func__ <<":"<< __LINE__ <<"\t\t"

static void Error(char* errMsg)
{
	std::cerr << "[ERROR] " << __FILE__ << " | " << __func__ << ":" << __LINE__ << "\t\t" << errMsg << endl;
	exit(1);
}

Game::Game(std::string title,int width, int height)
{
	if(nullptr != instance)
	{
		Error("Second instantion of the game!");
	}
	instance= this;
	if(0 != SDL_Init(SDL_INIT_VIDEO))
	{
		Error(SDL_GetError());
	}
	int result= IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF);
	if(0 == result)
	{
		Error("Loading SDL_image failed");
	}
	if(0 == result & IMG_INIT_JPG)
	{
//		std::cerr << "[ERROR] " << __FILE__ << " | " << __func__ << ":" << __LINE__ << "\t\t" << "Error Loading IMG_INIT_JPG";
		Error("Loading IMG_INIT_JPG failed");
	}
	if(0 == result & IMG_INIT_PNG)
	{
//		std::cerr << "[ERROR] " << __FILE__ << " | " << __func__ << ":" << __LINE__ << "\t\t" << "Error Loading IMG_INIT_PNG";
		Error("Loading IMG_INIT_PNG failed");
	}
	if(0 == result & IMG_INIT_TIF)
	{
//		std::cerr << "[ERROR] " << __FILE__ << " | " << __func__ << ":" << __LINE__ << "\t\t" << "Error Loading IMG_INIT_TIF";
		Error("Loading IMG_INIT_TIF failed");
	}
	window= SDL_CreateWindow("Usando SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
	if(nullptr == window)
	{
		Error(SDL_GetError());
	}
	renderer= SDL_CreateRenderer(window, -1, 0);
	if(nullptr == window)
	{
		Error(SDL_GetError());
	}
	//iniciar o state
}

Game::~Game()
{
	IMG_Quit();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

Game& Game::GetInstance(void) const
{
	return *instance;
}

State& Game::GetState(void) const
{
	return *state;
}

SDL_Renderer* Game::GetRenderer(void)const
{
	return *renderer;
}
