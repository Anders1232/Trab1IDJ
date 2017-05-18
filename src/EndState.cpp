#include "EndState.h"

#define TEMPO_PISCA_TEXTO (1.)

EndState::EndState(StateData stateData):
	bg((stateData.playerVictory)?"img/win.jpg":"img/lose.jpg"),
	music((stateData.playerVictory)?"audio/endStateWin.ogg": "audio/endStateLose.ogg"),
	instruction
	(
		"font/Call me maybe.ttf",
		END_STATE_FONT_SIZE,
		BLENDED,
		{255, 255, 255, 255}
	),
	displayText(true)
{
	music.Play(0);
	instruction.SetText("Press Esc to go to menu or Space to play again!");

	bg.Render(0, 0);
	Vec2 pos= Game::GetInstance().GetWindowDimensions();
	if(stateData.playerVictory)
	{
		instruction.SetPos(0, pos.y*0.005, true);
	}
	else
	{
		instruction.SetPos(0, pos.y-instruction.GetSize().y, true);
	}
}

void EndState::Update(float dt)
{
	InputManager &inputManager= InputManager::GetInstance();
	if(inputManager.QuitRequested())
	{
		quitRequested= true;
	}
	if(inputManager.KeyPress(ESCAPE_KEY))
	{
		popRequested=true;
	}
	if(inputManager.KeyPress(ESPACE_KEY))
	{
		popRequested= true;
		Game::GetInstance().Push(new StageState());
	}
	textTimer.Update(dt);
	if(TEMPO_PISCA_TEXTO < textTimer.Get())
	{
		displayText= !displayText;
		textTimer.Restart();
	}
}
void EndState::Render() const
{
	bg.Render(0, 0);
	if(displayText)
	{
		instruction.Render();
	}
}
void EndState::Pause()
{}
void EndState::Resume()
{}

