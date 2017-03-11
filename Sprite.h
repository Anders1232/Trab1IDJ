#ifndef SPRITE_H
#define SPRITE_H

#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>

#include <string>

class Sprite
{
	public:
		Sprite(void);
		Sprite(std::string file);
		~Sprite();
		void Open(std::string file);
		void SetClip(int x, int y, int w, int h);
		void Render(int x, int y);
		int GetWidth(void);
		int GetHeight(void);
		bool IsOpen(void);
	private:
		SDL_Texture *texture;
		int width;
		int height;
		SDL_Rect clipRect;
};


#endif // SPRITE_H
