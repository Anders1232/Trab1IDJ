#include "Face.h"

Face::Face(float x, float y): sp("img/penguimface.png")
{
	box.w= sp.GetWidth();
	box.h= sp.GetHeight();
	box.x= x-(box.w*0.5);
	box.y= y-(box.y*0.5);
	hitpoints=30;
}
void Face::Damage(int damage)
{
	hitpoints-= damage;
}
void Face::Update(float dt)
{

}
void Face::Render(void)
{
	sp.Render(box.x, box.y);
}
bool Face::IsDead(void)
{
	return (hitpoints<=0);
}

