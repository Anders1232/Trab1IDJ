#ifndef STATE_H
#define STATE_H

#include "Sprite.h"

class State
{
	public:
		State(void);
		bool QuitRequested(void);
		void Update(void);
		void Render(void);
	private:
		Sprite bg;
		bool quitRequested;
};

#endif // STATE_H
