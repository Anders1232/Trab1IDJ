#include "State.h"
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>

#define STATE_RENDER_X 0//esse valores calculam o offset em relação ao canto superior esquedo da imagem daquilo que será renderizado
#define STATE_RENDER_Y 0
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

void State::LoadAssets(void)
{

}

