#ifndef FACE_H
#define FACE_H

#include "Gameobject.h"
#include "Sprite.h"
#include "InputManager.h"

class Face: public GameObject
{
	public:
		Face(float x, float y);
		void Damage(int damage);
		void Update(float dt);
		void Render(void);
		bool IsDead(void);
		~Face(void);
	private:
		int hitpoints;
		Sprite sp;
		InputManager &inputManager;
};

#endif // FACE_H
