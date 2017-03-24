#include "Face.h"
#include <cmath>
#include "Vec2.h"
#include "Camera.h"
#include "Error.h"

#define SPAWN_CIRCULAR_AO_REDOR_DO_MOUSE 1
#define RAIO_AO_REDOR_DO_MOUSE 150

Face::Face(float x, float y): sp("img/penguinface.png"), inputManager(InputManager::GetInstance())
{
	box.w= sp.GetWidth();
	box.h= sp.GetHeight();
#ifdef SPAWN_ONDE_CLICOU
	box.x= x-(box.w*0.5);
	box.y= y-(box.h*0.5);RAIO_AO_REDOR_DO_MOUSE
#elif SPAWN_EM_QUALQUER_LUGAR_PERTO_DO_MOUSE
	box.x= x-(rand()%100);
	box.y= y-(rand()%100);
#elif SPAWN_CIRCULAR_AO_REDOR_DO_MOUSE
//	box.x= x-(box.w*0.5);
//	box.y= y-(box.h*0.5);
	//rotacionando
	int angulo= rand();
	box.x= x-(box.w*0.5)+RAIO_AO_REDOR_DO_MOUSE*cos(angulo);
	box.y= y-(box.h*0.5)+RAIO_AO_REDOR_DO_MOUSE*sin(angulo);
#endif
	hitpoints=30;
	sp.Rotate(rand());
}
void Face::Damage(int damage)
{
	hitpoints-= damage;
}
void Face::Update(float dt)
{
	if(inputManager.MousePress(LEFT_MOUSE_BUTTON))
	{
		int mouseX, mouseY;
		mouseX= inputManager.GetMouseX();
		mouseY= inputManager.GetMouseY();
		if(Vec2(mouseX, mouseY).IsInRect(box))
		{
			// Aplica dano
			Damage(rand() % 10 + 10);
		}

	}
}
void Face::Render(void)
{
	std::cout << WHERE << "TODO: ajustar" << endl;
	sp.Render(box.x-Camera::pos.x, box.y-Camera::pos.y);
}
bool Face::IsDead(void)
{
	return (hitpoints<=0);
}

Face::~Face()
{

}
