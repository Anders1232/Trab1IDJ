#include "State.h"

State::State(void): popRequested(false), quitRequested(false)
{
}
State::~State(void);
void StateAddObject(GameObject *object)
{
	objectArray.push_back(std::unique_ptr<GameObject>(ptr));
}
bool State::PopRequested(void)
{
	return popRequested;
}
bool State::QuitRequested(void)
{
	return quitRequested;
}
void State::UpdateArray(float dt)
{
	for(unsigned int cont=0; cont < objectArray.size(); cont++)
	{
		objectArray.at(cont)->Update(Game::GetInstance().GetDeltaTime());
		if(objectArray.at(cont)->IsDead())
		{
			objectArray.erase(objectArray.begin()+cont);
		}
	}
}
void State::RenderArray(void)
{
	for(unsigned int cont=0; cont < objectArray.size(); cont++)
	{
		objectArray[cont]->Render();
	}
}

