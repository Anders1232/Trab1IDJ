#ifndef STATE_H
#define STATE_H

#include "Sprite.h"

//#define BG_POINTER

class State
{
	public:
		State(void);
		bool QuitRequested(void);
		void Update(void);
		void Render(void);
	private:
#ifndef BG_POINTER
		Sprite bg;
#else
		Sprite *bg;
#endif
		bool quitRequested;
};

#endif // STATE_H
