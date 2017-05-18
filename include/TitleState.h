#ifndef TITLESTATE_H
#define TITLESTATE_H

#include "State.h"
#include "Sprite.h"
#include "Text.h"
#include "Timer.h"

class TitleState: public State
{
	public:
		TitleState(void);
		void Update(float dt);
		void Render(void) const;
		void Pause(void);
		void Resume(void);
	private:
		Sprite bg;
		Text message;
		Timer textTimer;
		bool displayText;
};

#endif // TITLESTATE_H
