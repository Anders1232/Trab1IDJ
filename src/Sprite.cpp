#include "Sprite.h"
#include "Game.h"
#include "Resources.h"
#include "Error.h"

#define SPRITE_OPEN_X (0)//alterar esses valores altera a parte da textura que será renderizada
#define SPRITE_OPEN_Y (0)

Sprite::Sprite(void): angle(0.0)
{
	texture= nullptr;
}

Sprite::Sprite(std::string file): angle(0.0)
{
	REPORT_I_WAS_HERE;
	texture=nullptr;
	REPORT_I_WAS_HERE;
	Open(file);
	REPORT_I_WAS_HERE;
}

Sprite::~Sprite()
{
}

void Sprite::Open(std::string file)
{
	texture= Resources::GetImage(file);
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

void Sprite::Render(int x, int y) const
{
	Game& game= Game::GetInstance();
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = clipRect.w;
	rect.h = clipRect.h;
/*	if(SDL_RenderCopy(game.GetRenderer(), texture, &clipRect, &rect) )//verifica se haverá erro
	{
		Error(SDL_GetError());
	}*/
	if(SDL_RenderCopyEx(game.GetRenderer(), texture, &clipRect, &rect, angle, NULL, SDL_FLIP_NONE) )//verifica se haverá erro
	{
		Error(SDL_GetError());
	}
}

int Sprite::GetHeight(void) const
{
	return height;
}

int Sprite::GetWidth(void) const
{
	return width;
}

bool Sprite::IsOpen(void) const
{
	return (nullptr != texture);
}

void Sprite::Rotate(double angle)
{
	this->angle= angle;
}

SDL_Texture *Sprite::GetTexture(void) const
{
	return texture;
}

