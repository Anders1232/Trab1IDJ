#include "Alien.h"
#include "RectOp.h"
#include "Camera.h"
#include "InputManager.h"
#include "Error.h"

#define DISTANCE_NEAR_ENOUGH ALIEN_MOVE_SPEED

Alien::Alien(float x, float y, int nMinions): sp("Alien.png")
{
	box.x= x;
	box.y= y;
	box.w= sp.GetWidth();
	box.h= sp.GetHeight();
//	for(int count=0; count < nMinions; count++)
//	{
//		minionArray.emplace_back(Minion());
//	}
}
Alien::~Alien(void)
{
	std::cout << WHERE << "\t needs to be implemented" << endl;
}

void Alien::Update(float dt)
{
	InputManager &inputManager= InputManager::GetInstance();
	if(inputManager.KeyPress(LEFT_MOUSE_BUTTON))
	{
		taskQueue.emplace(
					(Alien::Action::ActionType::SHOOT,//caraca
					inputManager.GetMouseX()+Camera::pos.x,
					inputManager.GetMouseY()+Camera::pos.y)
				);
	}
	if(inputManager.KeyPress(RIGHT_MOUSE_BUTTON))
	{
		taskQueue.emplace(
					(Alien::Action::ActionType::MOVE,//caraca
					inputManager.GetMouseX()+Camera::pos.x,
					inputManager.GetMouseY()+Camera::pos.y)
				);
	}

	if(0 < taskQueue.size())
	{
		if(Alien::Action::ActionType::MOVE==taskQueue.front().type)
		{
			Vec2 mousePos(inputManager.GetMouseX(), inputManager.GetMouseY());
			Vec2 distance = taskQueue.front().pos-Vec2(box.x, box.y);
			if(DISTANCE_NEAR_ENOUGH >= distance.Magnitude())
			{
				box.x= taskQueue.front().pos.x;
				box.y= taskQueue.front().pos.y;
				taskQueue.pop();
			}
			else
			{
				distance.Normalize();
				distance= distance*sqrt(ALIEN_MOVE_SPEED)*dt;
				box.x+= distance.x;
				box.y+= distance.y;
			}
		}
		else
		{
			taskQueue.pop();
		}
	}
}
void Alien::Render(void)
{
	sp.Render(box.x, box.y);
	for(unsigned int count=0; count < minionArray.size(); count++)
	{
		minionArray[count].Render();
	}
}
bool Alien::IsDead(void)
{
	return (0 >=hp);
}
