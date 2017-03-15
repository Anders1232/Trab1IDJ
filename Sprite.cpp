#include "Sprite.h"
#include "Game.h"
#include "Error.h"

#define SPRITE_OPEN_X (0)//alterar esses valores altera a parte da textura que será renderizada
#define SPRITE_OPEN_Y (0)

Sprite::Sprite(void)
{
	texture= nullptr;
}

Sprite::Sprite(std::string file)
{
	texture=nullptr;
	Open(file);
}

Sprite::~Sprite()
{
	if(nullptr != texture)
	{
		SDL_DestroyTexture(texture);
	}
}

void Sprite::Open(std::string file)
{
	if(nullptr != texture)//poderia trocar esse if por uma chamada explícita do destrutor?
	{
		SDL_DestroyTexture(texture);
		texture=nullptr;
	}
	texture= IMG_LoadTexture(Game::GetInstance().GetRenderer(), file.c_str());
	if(nullptr == texture)
	{
		Error(SDL_GetError());
	}
	if(SDL_QueryTexture(texture, nullptr, nullptr, &width, &height))//verificar se houve erro na chamada
	{
		Error(SDL_GetError());
	}
	SetClip(SPRITE_OPEN_X, SPRITE_OPEN_Y, width, height);
//	std::cout << __FILE__<<" | "<<__func__<<":"<<__LINE__<<"\t\t"<< "width=" << width << "\t height = " << height << std::endl;
}

void Sprite::SetClip(int x, int y, int w, int h)
{
	clipRect.x = x;
	clipRect.y = y;
	clipRect.w = w;
	clipRect.h = h;
}

void Sprite::Render(int x, int y)
{
	Game& game= Game::GetInstance();
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = clipRect.w;
	rect.h = clipRect.h;
	if(SDL_RenderCopy(game.GetRenderer(), texture, &clipRect, &rect) )//verifica se haverá erro
	{
		Error(SDL_GetError());
	}
}

int Sprite::GetHeight(void)
{
	return height;
}

int Sprite::GetWidth(void)
{
	return width;
}

bool Sprite::IsOpen(void)
{
	return (nullptr != texture);
}
