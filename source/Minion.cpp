#include "Minion.h"
#include "cmath"
#include "Camera.h"
#include "InputManager.h"
#include "Error.h"
#include "Bullet.h"
#include "Game.h"

#define VELOCIDADE_ANGULAR_MINION (2)
#define MINION_DISTANCE_TO_CENTER (150)
#define MINION_BULLET_SPEED (80)
#define MINION_BULLET_MAX_DISTANCE (500)

Minion::Minion(GameObject *minionCenter, float arcOffset): center(minionCenter), sp("img/minion.png"), arc (arcOffset)
{
	Vec2 offSetFromOrigin= Vec2(0, MINION_DISTANCE_TO_CENTER).Rotate(arc);
	box.w= sp.GetWidth();
	box.h= sp.GetHeight();
	box= center->box.Center() + offSetFromOrigin- Vec2(box.w/2, box.h/2);
}
void Minion::Update(float dt)
{
	arc+= VELOCIDADE_ANGULAR_MINION*dt;
	Vec2 offSetFromOrigin= Vec2(0, MINION_DISTANCE_TO_CENTER).Rotate(arc);
	box= center->box.Center() + offSetFromOrigin - Vec2(box.w/2, box.h/2);
}
void Minion::Render(void)
{
	InputManager &inputManager= InputManager::GetInstance();
	sp.Render(
			box.x-Camera::pos.x,
			box.y-Camera::pos.y);
}
bool Minion::IsDead(void)
{
	return false;
}
void Minion::Shoot(Vec2 pos)
{
	Bullet* bullet= new Bullet(
				box.x-Camera::pos.x,
				box.y-Camera::pos.y,
				(pos-box).Inclination(),
				MINION_BULLET_SPEED,
				MINION_BULLET_MAX_DISTANCE,
				"img/minionbullet2.png"
			);
	Game::GetInstance().GetState().AddObject(bullet);
}

