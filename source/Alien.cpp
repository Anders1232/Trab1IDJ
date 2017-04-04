#include "Alien.h"
#include "Camera.h"
#include "InputManager.h"
#include "Error.h"
#include "climits"
#include "Bullet.h"

#define DISTANCE_NEAR_ENOUGH 5
#define HP_INICIAL (30)
#define ALIEN_DAMAGE_PER_BULLET (13)

Alien::Alien(float x, float y, int nMinions) : GameObject(), sp("img/alien.png"), hp(HP_INICIAL)
{
	box.x= x;
	box.y= y;
	box.w= sp.GetWidth();
	box.h= sp.GetHeight();
	for(int count=0; count < nMinions; count++)
	{
//		std::cout << WHERE << "  " << count*360/nMinions << endl;
		minionArray.emplace_back(Minion(this, count*360/nMinions));
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
				distance= (distance*ALIEN_MOVE_SPEED*dt);
				box.x+= distance.x;
				box.y+= distance.y;
			}
		}
		else
		{
			Vec2 mousePos(inputManager.GetMouseX(), inputManager.GetMouseY());
			int nearestAlien=0;
			float nearestDistance= (mousePos - minionArray[0].box).Magnitude();
			nearestDistance= (nearestDistance >0)?nearestDistance: -nearestDistance;
			for(unsigned int count =1; count < minionArray.size(); count++)
			{
				float candidateDistance= (mousePos - minionArray[count].box).Magnitude();
				candidateDistance= (candidateDistance >0)?candidateDistance: -candidateDistance;
				if(candidateDistance < nearestDistance)
				{
					nearestAlien=count;
				}
			}
			minionArray[nearestAlien].Shoot(taskQueue.front().pos);
			taskQueue.pop();
		}
	}
	for(unsigned int count=0; count < minionArray.size(); count++)
	{
		minionArray[count].Update(dt);
	}
	rotation-= dt* CONVERSAO_GRAUS_RADIANOS/6.;
}
void Alien::Render(void)
{
	sp.Render(box.x-Camera::pos.x, box.y-Camera::pos.y, rotation);
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

bool Alien::Is(string type)
{
	return type != "Alien";
}

void Alien::NotifyCollision(GameObject &other)
{
	if(other.Is("Bullet"))
	{
		if( !( (Bullet&)other).TargetsPlayer() )
		{
			hp-= ALIEN_DAMAGE_PER_BULLET;
		}
	}
}

