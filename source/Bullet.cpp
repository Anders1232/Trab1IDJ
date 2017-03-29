#include "Bullet.h"
#include "Camera.h"

Bullet::Bullet(
		float x,
		float y,
		float angle,
		float speed,
		float maxDistance,
		string sprite
	): GameObject(), sp(sprite)
{
	box.x= Camera::pos.x+x;
	box.y= Camera::pos.y+y;
	box.w= sp.GetWidth();
	box.h= sp.GetHeight();
	this->speed= {1.0, 0.};
	this->speed.Rotate(angle);
	this->speed = this->speed*sqrt(speed);
	distanceLeft= maxDistance;
}

void Bullet::Update(float dt)
{
	box= box + speed*dt;
	distanceLeft-= speed.Magnitude()*dt;
}
void Bullet::Render(void)
{
	sp.Render(box.x- Camera::pos.x, box.y- Camera::pos.y);
}
bool Bullet::IsDead(void)
{
	return (distanceLeft<=0);
}

Bullet::~Bullet()
{}
