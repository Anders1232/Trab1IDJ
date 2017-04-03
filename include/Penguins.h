#ifndef PENGUINS_H
#define PENGUINS_H

#include "Gameobject.h"
#include "Sprite.h"

class Penguins: public GameObject
{
	public:
		Penguins(float x, float y);
		~Penguins();
		void Update(float dt);
		void Render(void);
		bool IsDead(void);
		void Shoot(void);
		void NotifyCollision(GameObject &other);
		bool Is(string type);
		static Penguins *player;
	private:
		Sprite bodySP;
		Sprite cannonSp;
		Vec2 speed;
		float linearSpeed;
		float cannonAngle;
		int hp;
};

#endif // PENGUINS_H
