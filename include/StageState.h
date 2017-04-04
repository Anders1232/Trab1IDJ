#ifndef STAGE_STATE_H
#define STAGE_STATE_H

#include <vector>
#include <memory>
#include "Sprite.h"
#include "Gameobject.h"
#include "Tileset.h"
#include "TileMap.h"
#include "InputManager.h"
#include "State.h"

//#define BG_POINTER

class StageState: State
{
	public:
		StageState(void);
		~StageState(void);
		void Update(void);
		void Render(void);
		void Pause(void);
		void Resume(void);
	private:
		Sprite bg;
		TileMap *tileMap;
		TileSet tileSet;
		InputManager &inputManager;
};

#endif // STAGE_STATE_H
