#ifndef RECTOP_H
#define RECTOP_H

#ifdef _WIN32
	//windows
#elif __APPLE__
	#include "TargetConditionals.h"
	//mac
#elif __linux__
	#include <SDL2/SDL.h>
#else
	#include <SDL2/SDL.h>
//	#error "Unknown compiler"
#endif

#include "Vec2.h"

SDL_Rect operator+(SDL_Rect const &rect, Vec2 const vec);
SDL_Rect CreateRect(int x, int y, int w, int h);
SDL_Rect CreateRect(void);

class RectOP
{
	public:
		static Vec2 Center(SDL_Rect const &a);
		static Vec2 DistanceBetweenCenter(SDL_Rect const &a, SDL_Rect const &b);
};

#endif // RECTOP_H
