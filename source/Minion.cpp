#include "Minion.h"
#include "cmath"
#include "Camera.h"
#include "InputManager.h"

#define VELOCIDADE_ANGULAR_MINION (20)
#define MINION_DISTANCE_TO_CENTER (100)

Minion::Minion(GameObject *minionCenter, float arcOffset): center(minionCenter), sp("img/minion.png"), arc (arcOffset)
{
	Vec2 offSetFromOrigin= Vec2(0, MINION_DISTANCE_TO_CENTER).Rotate(arc);
	box= center->box + offSetFromOrigin;
}
void Minion::Update(float dt)
{
	arc+= VELOCIDADE_ANGULAR_MINION;
	Vec2 offSetFromOrigin= Vec2(0, MINION_DISTANCE_TO_CENTER).Rotate(arc);
	box= center->box.Center() + offSetFromOrigin;
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

}

