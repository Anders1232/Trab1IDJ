#ifndef VEC2OP_H
#define VEC2OP_H

#include <SDL2/SDL.h>

class Vec2
{
	public:
		Vec2(void);
		Vec2(float x, float y);
		Vec2(Vec2 const &b);
		Vec2 operator+(Vec2 const &b)const;
		Vec2 operator-(Vec2 const &b) const;
		Vec2 operator*(float b);
		Vec2& operator=(Vec2 const &b);
		float Magnitude(void)const;
		void Normalize(void);
		float DistanceTo(Vec2 const &b) const;
		float Inclination(void) const;
		float Inclination(Vec2 const &b) const;
		bool IsInRect(SDL_Rect const &rect);
		float x;
		float y;
};

#endif // VEC2OP_H
