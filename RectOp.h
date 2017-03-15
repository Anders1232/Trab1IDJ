#ifndef RECTOP_H
#define RECTOP_H

#include <SDL2/SDL.h>
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
