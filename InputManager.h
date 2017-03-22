#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#define LEFT_ARROW_KEY SDLK_LEFT
#define RIGHT_ARROW_KEY SDL_RIGHT
#define UP_ARROW_KEY SDLK_RIGHT
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
