#include "RectOp.h"

SDL_Rect operator+(SDL_Rect const &rect, Vec2 const vec);
SDL_Rect CreateRect(int x, int y, int w, int h);
SDL_Rect CreateRect(void);

Vec2 RectOP::Center(SDL_Rect const &a)
{
	Vec2 ret;
	ret.x= a.x+(0.5 * a.w);
	ret.y= a.y+(0.5 * a.h);
	return ret;
}

Vec2 RectOP::DistanceBetweenCenter(SDL_Rect const &a, SDL_Rect const &b)
{
	return RectOP::Center(a)-RectOP::Center(b);
}


