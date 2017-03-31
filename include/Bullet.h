#ifndef BULLET_H
#define BULLET_H

#include "Gameobject.h"
#include "Sprite.h"
#include "Vec2.h"
#include <string>

using std::string;

class Bullet: public GameObject
{
	public:
		Bullet(
				float x,
				float y,
				float angle,
				float speed,
				float maxDistance,
				float frameTime,
				int frameCount,
				string sprite
			);
		~Bullet(void);
		void Update(float dt);
		void Render(void);
		bool IsDead(void);
	private:
		Sprite sp;
		Vec2 speed;
		float distanceLeft;
};

#endif // BULLET_H
