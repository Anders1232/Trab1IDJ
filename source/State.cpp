#include "State.h"
#include "Game.h"
#include "Error.h"
#include "Camera.h"
#include "Alien.h"
#include "Penguins.h"

#ifdef _WIN32
	//windows
#elif __APPLE__
	#include "TargetConditionals.h"
	//mac
#elif __linux__
	#include <SDL2/SDL.h>
	#include<SDL2/SDL_image.h>
#else
	#error "Unknown compiler"
#endif

#define STATE_RENDER_X 0//esse valores calculam o offset em relação ao canto superior esquedo da imagem daquilo que será renderizado
#define STATE_RENDER_Y 0
State::State(void): bg("img/ocean.jpg"), tileSet(64, 64,"img/tileset.png"), inputManager(InputManager::GetInstance())
{
	REPORT_I_WAS_HERE;
	tileMap= new TileMap(std::string("map/tileMap.txt"), &tileSet);
	quitRequested=false;
	REPORT_I_WAS_HERE;
	objectArray.emplace_back(std::unique_ptr<Alien>( new Alien (512, 300, 3) ) );
	objectArray.emplace_back(std::unique_ptr<Penguins>( new Penguins (704, 640) ) );
}

State::~State(void)
{
	objectArray.clear();
	delete tileMap;
}

//void State::Update(float dt)
void State::Update()
{
	REPORT_I_WAS_HERE;
//	Input();
	if(inputManager.KeyPress(ESCAPE_KEY) || inputManager.QuitRequested())
	{
		quitRequested= true;
	}
/*	if(inputManager.IsKeyDown(ESPACE_KEY))
	{
		AddObject((float)inputManager.GetMouseX()+Camera::pos.x, (float)inputManager.GetMouseY()+Camera::pos.y);
	}
*/
	for(unsigned int cont=0; cont < objectArray.size(); cont++)
	{
		objectArray.at(cont)->Update(Game::GetInstance().GetDeltaTime());
		if(objectArray.at(cont)->IsDead())
		{
			objectArray.erase(objectArray.begin()+cont);
		}
	}
	Camera::Update(Game::GetInstance().GetDeltaTime());
	REPORT_I_WAS_HERE;
}

void State::Render(void)
{
	//renderizar o bg
	REPORT_I_WAS_HERE;
	bg.Render(STATE_RENDER_X, STATE_RENDER_Y);
	REPORT_I_WAS_HERE;
	tileMap->RenderLayer(0, Camera::pos.x, Camera::pos.y);
//	tileMap->Render(Camera::pos.x, Camera::pos.y);
	REPORT_I_WAS_HERE;
	for(unsigned int cont=0; cont < objectArray.size(); cont++)
	{
		objectArray[cont]->Render();
	}
	tileMap->RenderLayer(1, Camera::pos.x, Camera::pos.y);
}

bool State::QuitRequested()
{
	return quitRequested;
}

void State::AddObject(GameObject *ptr)
{
	objectArray.push_back(std::unique_ptr<GameObject>(ptr));
}

