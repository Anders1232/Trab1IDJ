#ifndef RESOURCES_H
#define RESOURCES_H

#ifdef _WIN32
	#include <SDL.h>
	#include <SDL_image.h>
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
#include <memory>

using std::string;

class Resources
{
	public:
		static std::shared_ptr<SDL_Texture> GetImage(string file);
		static void ClearImages(void);
	private:
		Resources();
		static std::unordered_map<string, std::shared_ptr<SDL_Texture>> imageTable;
};

#endif // RESOURCES_H
