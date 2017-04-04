#ifndef STAGE_STATE_H
#define STAGE_STATE_H

#include <vector>
#include <memory>
#include "Sprite.h"
#include "Gameobject.h"
#include "Tileset.h"
#include "TileMap.h"
#include "InputManager.h"

//#define BG_POINTER

class StageState
{
	public:
		StageState(void);
		~StageState(void);
		bool QuitRequested(void);
		void Update(void);
		void Render(void);
		void AddObject(GameObject *ptr);
//		void Input(void);
	private:
		Sprite bg;
		TileMap *tileMap;
		TileSet tileSet;
		bool quitRequested;
		std::vector<std::unique_ptr<GameObject>> objectArray;
		InputManager &inputManager;
};

#endif // STAGE_STATE_H
