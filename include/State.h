#ifndef STATE_H
#define STATE_H

#include <vector>
#include <memory>
#include "Sprite.h"
#include "Gameobject.h"
#include "Tileset.h"
#include "TileMap.h"

//#define BG_POINTER

class State
{
	public:
		State(void);
		~State(void);
		bool QuitRequested(void);
		void Update(void);
		void Render(void);
		void Input(void);
		void AddObject(float mouseX, float mouseY);
	private:
		Sprite bg;
		TileMap *tileMap;
		TileSet tileSet;
		bool quitRequested;
		std::vector<std::unique_ptr<GameObject>> objectArray;
};

#endif // STATE_H
