#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SDL2/SDL.h>

class GameObject
{
	public:
		virtual ~GameObject(void);
		virtual void Update(float dt)=0;
		virtual void Render(void)=0;
		virtual bool IsDead(void)=0;
		SDL_Rect box;
	private:

};

#endif // GAMEOBJECT_H
