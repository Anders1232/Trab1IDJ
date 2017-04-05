#include "Resources.h"
#include "Error.h"
#include "Game.h"

std::unordered_map<string, std::shared_ptr<SDL_Texture>> Resources::imageTable;

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
//#define MODO1
#ifdef MODO1
	for(unsigned int count =0; count < imageTable.bucket_count(); count++)
	{
		SDL_DestroyTexture(imageTable.begin()+count);
	}
#else
	for(std::unordered_map<string, std::shared_ptr<SDL_Texture>>::iterator i= imageTable.begin(); i != imageTable.end(); i++)
//	for(int count=0; count < imageTable.size(); count++)
	{
		if((*i).second.unique())
//		if( (imageTable.begin()+count )->second.unique())
		{
//			imageTable.erase( (imageTable.begin()+count ));
			imageTable.erase(i);
//			SDL_DestroyTexture((*i).second);
		}
	}
#endif
	imageTable.clear();
}
