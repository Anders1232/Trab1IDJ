#include "RectOp.h"

SDL_Rect operator+(SDL_Rect const &rect, Vec2 const vec)
{
	return CreateRect(rect.x+vec.x, rect.y+vec.y, rect.w, rect.h);
}
SDL_Rect CreateRect(int x, int y, int w, int h)
{
	SDL_Rect rect;
	rect.x=x;
	rect.y=y;
	rect.w=w;
	rect.h=h;
	return rect;
}
SDL_Rect CreateRect(void)
{
	SDL_Rect rect;
	rect.x=0;
	rect.y=0;
	rect.w=0;
	rect.h=0;
	return rect;
}

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


