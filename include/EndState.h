#ifndef ENDDTATE_H
#define ENDDTATE_H

#include "Gameobject.h"
#include "Sprite.h"
#include "Music.h"
#include "Text.h"
#include "StateData.h"
#include "Timer.h"

#define END_STATE_FONT_SIZE (40)

class EndState: public State
{
	public:
		EndState(StateData stateData);
		void Update(float dt);
		void Render() const;
		void Pause();
		void Resume();
	private:
		Sprite bg;
		Music music;
		Text instruction;
		Timer textTimer;
		bool displayText;
};

#include "InputManager.h"
#include "StageState.h"

#endif // ENDDTATE_H
