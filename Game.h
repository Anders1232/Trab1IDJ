#ifndef GAME_H
#define GAME_H

#include<string>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>

class Game
{
	public:
		Game(std::string title,int width, int height);
		~Game();
		void Run(void);
		SDL_Renderer* GetRenderer(void) const;
		State& GetState(void) const;
		static Game& GetInstance(void) const;
	private:
		static Game* instance;
		SDL_Window* window;
		SDL_Renderer* renderer;
		State* state;
}

#endif // GAME_H
