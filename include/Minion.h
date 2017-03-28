#ifndef MINION_H
#define MINION_H

#include "Gameobject.h"
#include "Vec2.h"
#include "Sprite.h"

class Minion: public GameObject
{
	public:
		Minion(GameObject *minionCenter, float arcOffset =0);
		void Update(float dt);
		void Render(void);
		bool IsDead(void);
		void Shoot(Vec2 pos);
	private:
		GameObject *center;
		Sprite sp;
		float arc;
};

#endif // MINION_H
