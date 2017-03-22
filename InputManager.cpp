#include "InputManager.h"
#include "string.h"

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

InputManager::InputManager():quitRequested(false), updateCounter(0), mouseX(0), mouseY(0)
{
	memset(keyState, 0, 416*sizeof(bool));
	memset(keyUpdate, 0, 416*sizeof(int));
	memset(mouseState, 0, 6*sizeof(bool));
	memset(mouseUpdate, 0, 6*sizeof(int));
}
InputManager::~InputManager()
{
}
InputManager& InputManager::GetInstance(void)
{
	static InputManager inputManager;
	return inputManager;
}
void InputManager::Update(void)
{
	SDL_GetMouseState(&mouseX, &mouseY);
	quitRequested= false;
	updateCounter++;
	SDL_Event event;
	while(SDL_PollEvent(&event))
	{
		if(SDL_KEYDOWN == event.type)
		{
			if(!event.key.repeat)
			{
				int keyCode= event.key.keysym.sym;
				if(keyCode >= 0x40000000)
				{
					keyCode = keyCode- 0x40000000+ 0x7F;
				}
				keyState[keyCode]= true;
				keyUpdate[keyCode]= updateCounter;
			}
		}
		else if (SDL_KEYUP == event.type)
		{
			if(!event.key.repeat)
			{
				int keyCode= event.key.keysym.sym;
				if(keyCode >= 0x40000000)
				{
					keyCode = keyCode- 0x40000000+ 0x7F;
				}
				keyState[keyCode]= false;
//				keyUpdate[keyCode]= updateCounter;
			}
		}
		else if(SDL_MOUSEBUTTONDOWN == event.type)
		{
			mouseState[event.button.button]= true;
			mouseUpdate[event.button.button]= updateCounter;
		}
		else if(SDL_MOUSEBUTTONUP == event.type)
		{
			mouseState[event.button.button]= false;
		}
		else if(SDL_QUIT == event.type)
		{
			quitRequested=true;
		}
	}
}
#define AJUST_KEY(k)if(k >= 0x40000000)\
{\
	k=k-0x40000000+0x7F;\
}

bool InputManager::KeyPress(int key)
{
	AJUST_KEY(key);
	return keyState[key] && keyUpdate[key] == updateCounter;
}
bool InputManager::KeyRelease(int key)
{
	AJUST_KEY(key);
	return ((false==keyState[key]) && keyUpdate[key]+1 ==updateCounter);
}
bool InputManager::IsKeyDown(int key)
{
	AJUST_KEY(key);
	return keyState[key];
}
bool InputManager::MousePress(int button)
{
	return mouseState[button]&& mouseUpdate[button]== updateCounter;
}
bool InputManager::MouseRelease(int button)
{
	return ((false == mouseState[button]) && mouseUpdate[button]+1 == updateCounter);
}
bool InputManager::IsMouseDown(int button)
{
	return mouseState[button];
}
int InputManager::GetMouseX(void)
{
	return mouseX;
}
int InputManager::GetMouseY(void)
{
	return mouseY;
}
bool InputManager::QuitRequested(void)
{
	return quitRequested;
}


