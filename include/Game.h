#ifndef GAME_H
#define GAME_H

#include <string>
#include <stack>
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
		static Game& GetInstance(void);
		SDL_Renderer* GetRenderer(void) const;
		State& GetCurrentState(void) const;
		void Push(State* state);
		void Run(void);
		float GetDeltaTime(void) const;
	private:
		void CalculateDeltaTime(void);
		void UpdateStack(void);

		unsigned int frameStart;
		float dt;
		static Game* instance;
		State* storedState;
		SDL_Window* window;
		SDL_Renderer* renderer;
		std::stack<std::unique_ptr<State>> stateStack;
		InputManager &inputManager;
};

#endif // GAME_H
