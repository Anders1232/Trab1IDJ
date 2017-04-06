#include "Resources.h"
#include "Error.h"
#include "Game.h"

std::unordered_map<string, SDL_Texture*> Resources::imageTable;

SDL_Texture* Resources::GetImage(string file)
{
	SDL_Texture* ret;
	if(imageTable.end() == imageTable.find(file))
	{
		ret=IMG_LoadTexture(Game::GetInstance().GetRenderer(), file.c_str());
		ASSERT(nullptr != ret);
		imageTable[file]= ret;
		return ret;
	}
	else
	{
		return imageTable[file];
	}
}
void Resources::ClearImages(void)
{
//#define MODO1
#ifdef MODO1
	for(unsigned int count =0; count < imageTable.bucket_count(); count++)
	{
		SDL_DestroyTexture(imageTable.begin()+count);
	}
#else
	for(std::unordered_map<string, SDL_Texture*>::iterator i= imageTable.begin(); i != imageTable.end(); i++)
	{
		SDL_DestroyTexture((*i).second);
	}
#endif
	imageTable.clear();
}
