#ifndef ALIEN_H
#define ALIEN_H

#include "Minion.h"
#include "Gameobject.h"
#include "Sprite.h"
#include "Vec2.h"
#include <queue>
#include <vector>

#define ALIEN_MOVE_SPEED (50)

using std::queue;
using std::vector;

class Alien: public GameObject
{
	public:
		Alien(float X, float y, int nMinions);
		~Alien(void);
		void Update(float dt);
		void Render(void);
		bool IsDead(void);
	private:
		class Action;
		Sprite sp;
		Vec2 speed;
		int hp;
		queue<Action> taskQueue;
		vector<Minion> minionArray;
};


class Alien::Action
{
	public:
		enum ActionType
		{
			MOVE,
			SHOOT
		} type;
		Action(ActionType type, float x, float y);
		Vec2 pos;
};

#endif // ALIEN_H
