#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

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

#define LEFT_ARROW_KEY SDLK_LEFT
#define RIGHT_ARROW_KEY SDLK_RIGHT
#define UP_ARROW_KEY SDLK_UP
#define DOWN_ARROW_KEY SDLK_DOWN
#define ESCAPE_KEY SDLK_ESCAPE
#define LEFT_ALT_KEY SDLK_LALT
#define LEFT_CTRL_KEY SDLK_LCTRL
#define LEFT_SHIFT_KEY SDLK_LSHIFT
#define ESPACE_KEY SDLK_SPACE
#define LEFT_MOUSE_BUTTON SDL_BUTTON_LEFT
#define RIGHT_MOUSE_BUTTON SDL_BUTTON_RIGHT
#define MIDDLE_MOUSE_BUTTON SDL_BUTTON_MIDDLE


class InputManager
{
	public:
		void Update(void);
		bool KeyPress(int key);
		bool KeyRelease(int key);
		bool IsKeyDown(int key);
		bool MousePress(int button);
		bool MouseRelease(int button);
		bool IsMouseDown(int button);
		int GetMouseX(void);
		int GetMouseY(void);
		bool QuitRequested(void);
		static InputManager& GetInstance(void);
	private:
		InputManager();
		~InputManager();
		bool mouseState[6];
		int mouseUpdate[6];
		bool quitRequested;
		int updateCounter;
		int mouseX;
		int mouseY;
		bool keyState[416];
		int keyUpdate[416];
};

#endif // INPUTMANAGER_H