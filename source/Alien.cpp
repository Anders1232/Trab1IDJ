#include "Alien.h"
#include "Camera.h"
#include "InputManager.h"
#include "Error.h"

#define DISTANCE_NEAR_ENOUGH ALIEN_MOVE_SPEED/4
#define HP_INICIAL (30)

Alien::Alien(float x, float y, int nMinions): sp("img/alien.png"), hp(HP_INICIAL)
{
	box.x= x;
	box.y= y;
	box.w= sp.GetWidth();
	box.h= sp.GetHeight();
	for(int count=0; count < nMinions; count++)
	{
		minionArray.emplace_back(Minion(this, rand()));
	}
}
Alien::~Alien(void)
{
	while(0 < taskQueue.size())
	{
		taskQueue.pop();
	}
	minionArray.clear();
}

void Alien::Update(float dt)
{
	InputManager &inputManager= InputManager::GetInstance();
	if(inputManager.MousePress(LEFT_MOUSE_BUTTON))
	{
		Alien::Action action(Alien::Action::ActionType::SHOOT,//caraca
							 (int)(inputManager.GetMouseX()+(Camera::pos.x)),
							 (int)(inputManager.GetMouseY()+Camera::pos.y));
		taskQueue.emplace(action);
	}
	if(inputManager.MousePress(RIGHT_MOUSE_BUTTON))
	{
		Action action(Alien::Action::ActionType::MOVE,//caraca
					(inputManager.GetMouseX()+Camera::pos.x)-box.w/2,
					(inputManager.GetMouseY()+Camera::pos.y)-box.h/2
				);
		taskQueue.push(action);
	}
//	TEMP_REPORT_I_WAS_HERE;
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
				distance= (distance*sqrt(ALIEN_MOVE_SPEED*dt));
				box.x+= distance.x;
				box.y+= distance.y;
			}
		}
		else
		{
			taskQueue.pop();
		}
	}
	for(unsigned int count=0; count < minionArray.size(); count++)
	{
		minionArray[count].Update(dt);
	}
}
void Alien::Render(void)
{
	sp.Render(box.x-Camera::pos.x, box.y-Camera::pos.y);
	for(unsigned int count=0; count < minionArray.size(); count++)
	{
		minionArray[count].Render();
	}
}
bool Alien::IsDead(void)
{
	return (0 >=hp);
}

Alien::Action::Action(ActionType type, float x, float y): type(type), pos(x, y)
{
}

