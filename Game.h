#ifndef GAME_H
#define GAME_H

#include<string>
#include"State.h"
#include "InputManager.h"
#ifdef _WIN32
	//windows
#elif __APPLE__
	#include "TargetConditionals.h"
	//mac
#elif __linux__
	// linux
#else
	#error "Unknown compiler"
#endif


class Game
{
	public:
		Game(std::string title,int width, int height);
		~Game();
		void Run(void);
		SDL_Renderer* GetRenderer(void) const;
		State& GetState(void) const;
		static Game& GetInstance(void);
	private:
		static Game* instance;
#define CHECK_SDL_ERRO
		SDL_Window* window;
		SDL_Renderer* renderer;
		State* state;
		InputManager &inputManager;
};

#endif // GAME_H
