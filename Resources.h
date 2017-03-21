#ifndef RESOURCES_H
#define RESOURCES_H

#ifdef _WIN32
	//windows
#elif __APPLE__
	#include "TargetConditionals.h"
	//mac
#elif __linux__
	#include <SDL2/SDL.h>
	#include<SDL2/SDL_image.h>
#else
	#error "Unknown compiler"
#endif

#include <string>
#include <unordered_map>

using std::string;

class Resources
{
	public:
		static SDL_Texture* GetImage(string file);
		static void ClearImages(void);
	private:
		Resources();
		static std::unordered_map<string, SDL_Texture*> imageTable;
};

#endif // RESOURCES_H