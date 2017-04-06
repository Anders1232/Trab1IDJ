#ifndef SPRITE_H
#define SPRITE_H

#ifdef _WIN32
	//windows
#elif __APPLE__
	#include "TargetConditionals.h"
	//mac
#elif __linux__
	#include <SDL2/SDL.h>
	#include<SDL2/SDL_image.h>
#else
	#error "Unknown compiler"
#endif


#include <string>

class Sprite
{
	public:
		Sprite(void);
		Sprite(std::string file);
		~Sprite();
		void Open(std::string file);
		void SetClip(int x, int y, int w, int h);
		void Render(int x, int y) const;
		void Rotate(double angle);
		int GetWidth(void) const;
		int GetHeight(void) const;
		SDL_Texture* GetTexture(void) const;
		bool IsOpen(void) const;
	private:
		SDL_Texture *texture;
		int width;
		int height;
		SDL_Rect clipRect;
		double angle;
};


#endif // SPRITE_H
