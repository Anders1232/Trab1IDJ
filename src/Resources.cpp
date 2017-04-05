#include "Resources.h"
#include "Error.h"
#include "Game.h"

std::unordered_map<string, std::shared_ptr<SDL_Texture>> Resources::imageTable;
std::unordered_map<string, std::shared_ptr<Mix_Music>> Resources::musicTable;

std::shared_ptr<SDL_Texture> Resources::GetImage(string file)
{
	SDL_Texture* ret;
	if(imageTable.end() == imageTable.find(file))
	{
		ret=IMG_LoadTexture(Game::GetInstance().GetRenderer(), file.c_str());
		if(nullptr == ret)
		{
//			std::cout << WHERE <<  << file << endl;
			Error("Could not load "<<file);
		}
//		ASSERT(nullptr != ret);
		imageTable[file]= std::shared_ptr<SDL_Texture>
				(
					ret,
					[](SDL_Texture *texture)//meu primeiro uso de função labda em C++
					{
						SDL_DestroyTexture(texture);
					}
				);
	}
	return imageTable[file];
}
void Resources::ClearImages(void)
{
	std::unordered_map<string, std::shared_ptr<SDL_Texture>>::iterator i= imageTable.begin();
	while(i != imageTable.end())
	{
		if((*i).second.unique())
		{
			i= imageTable.erase(i);
		}
		else
		{
			i++;
		}
	}
}

std::shared_ptr<Mix_Music> Resources::GetMusic(string file)
{
	Mix_Music* ret;
	if(musicTable.end() == musicTable.find(file))
	{
		ret=Mix_LoadMUS(file.c_str());
		if(nullptr == ret)
		{
//			std::cout << WHERE <<  << file << endl;
			Error("Could not load "<<file);
		}
//		ASSERT(nullptr != ret);
		musicTable[file]= std::shared_ptr<Mix_Music>
				(
					ret,
					[](Mix_Music *music)//meu segundo uso de função labda em C++
					{
						Mix_FreeMusic(music);
					}
				);
	}
	return musicTable[file];
}
void Resources::ClearResources(void)
{
	ClearImages();
	ClearMusic();
}
void Resources::ClearMusic(void)
{
	std::unordered_map<string, std::shared_ptr<Mix_Music>>::iterator i= musicTable.begin();
	while(i != musicTable.end())
	{
		if((*i).second.unique())
		{
			i= musicTable.erase(i);
		}
		else
		{
			i++;
		}
	}
}
