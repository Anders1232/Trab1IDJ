#include "Minion.h"
#include "cmath"
#include "Camera.h"
#include "InputManager.h"
#include "Error.h"
#include "Bullet.h"
#include "Game.h"


Minion::Minion(GameObject *minionCenter, float arcOffset): center(minionCenter), sp("img/minion.png"), arc (arcOffset/CONVERSAO_GRAUS_RADIANOS)
{
//	rotation=
	Vec2 offSetFromOrigin= Vec2(0, MINION_DISTANCE_TO_CENTER).Rotate(arc);
	float scale= ( (float)(rand()%6+10) )/10;
	sp.SetScale( scale);
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
//	std::cout << WHERE << " arc= " <<arc <<endl;
	sp.Render(
			box.x-Camera::pos.x,
			box.y-Camera::pos.y,
			arc*CONVERSAO_GRAUS_RADIANOS);
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

