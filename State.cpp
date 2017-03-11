#include "State.h"
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>

#define STATE_RENDER_X 1024
#define STATE_RENDER_Y 600

State::State(void): bg("img/ocean.jpg")
{
	quitRequested=false;
}


//void State::Update(float dt)
void State::Update()
{
	if(SDL_QuitRequested())
	{
		quitRequested= true;
	}
}

void State::Render(void)
{
	//renderizar o bg
	bg.Render(STATE_RENDER_X, STATE_RENDER_Y);
}

bool State::QuitRequested()
{
	return quitRequested;
}
