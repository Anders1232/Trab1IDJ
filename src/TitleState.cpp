#include "TitleState.h"
#include "InputManager.h"
#include "Game.h"
#include "StageState.h"

#define TILE_STATE_FONT_SIZE (40)
#define DURACAO_DO_PISCAR (1.0)

TitleState::TitleState():State(),
	bg("img/title.jpg"),
	message(
		"font/Call me maybe.ttf",
		TILE_STATE_FONT_SIZE,
		SHARED,
		{255, 255, 255, 255}
	),
	displayText(false)
{
	message.SetText("Press space to start game");
	Vec2 pos= Game::GetInstance().GetWindowDimensions();
	message.SetPos(0, pos.y-message.GetSize().y, true);
}
void TitleState::Update(float dt)
{
	InputManager &inputManager= InputManager::GetInstance();
	if(inputManager.KeyPress(ESPACE_KEY))
	{
		Game::GetInstance().Push(new StageState());
	}
	else if(inputManager.QuitRequested())
	{
		quitRequested= true;
	}
	else if( inputManager.KeyPress(ESCAPE_KEY))
	{
		popRequested= true;
	}
	textTimer.Update(dt);
	if(DURACAO_DO_PISCAR < textTimer.Get())
	{
		displayText= !displayText;
		textTimer.Restart();
	}
}
void TitleState::Render(void) const
{
	bg.Render(0, 0);
	if(displayText)
	{
		message.Render();
	}
}
void TitleState::Pause(void)
{}
void TitleState::Resume(void)
{}
