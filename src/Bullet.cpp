#include "Bullet.h"
#include "Camera.h"
#include "Error.h"

Bullet::Bullet(
		float x,
		float y,
		float angle,
		float speed,
		float maxDistance,
		string sprite
	): GameObject(), sp(sprite)
{
	box.x= Camera::pos.x+x -sp.GetWidth()/2;
	box.y= Camera::pos.y+y -sp.GetHeight()/2;
	box.w= sp.GetWidth();
	box.h= sp.GetHeight();
	rotation= angle*CONVERSAO_GRAUS_RADIANOS;
	this->speed= {1.0, 0.0};
	this->speed=this->speed.Rotate(angle);
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
//	std::cout << WHERE << " rotation= " <<rotation <<endl;
	sp.Render(box.x- Camera::pos.x, box.y- Camera::pos.y, rotation);
}
bool Bullet::IsDead(void)
{
	return (distanceLeft<=0);
}

Bullet::~Bullet()
{}
