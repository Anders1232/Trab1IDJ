#include "Minion.h"
#include "cmath"
#include "Camera.h"
#include "InputManager.h"

#define VELOCIDADE_ANGULAR_MINION (1000)
#define MINION_DISTANCE_TO_CENTER (200)

Minion::Minion(GameObject *minionCenter, float arcOffset): center(minionCenter), sp("img/minion.png"), arc (arcOffset)
{
	Vec2 offSetFromOrigin= Vec2(0, MINION_DISTANCE_TO_CENTER).Rotate(arc);
	box= center->box.Center() + offSetFromOrigin- Vec2(box.w/2, box.h/2);
	box.w= sp.GetWidth();
	box.h= sp.GetHeight();
}
void Minion::Update(float dt)
{
	arc+= VELOCIDADE_ANGULAR_MINION;
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

}

