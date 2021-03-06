#include "State.h"

State::State(void): popRequested(false), quitRequested(false)
{
}
State::~State(void)
{
}
void State::AddObject(GameObject *object)
{
	objectArray.push_back(std::unique_ptr<GameObject>(object));
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
		objectArray.at(cont)->Update(dt);
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

