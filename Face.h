#ifndef FACE_H
#define FACE_H

#include "Gameobject.h"
#include "Sprite.h"

class Face: public GameObject
{
	public:
		Face(float x, float y);
		void Damage(int damage);
		void Update(float dt);
		void Render(void);
		bool IsDead(void);
	private:
		int hitpoints;
		Sprite sp;
};

#endif // FACE_H
