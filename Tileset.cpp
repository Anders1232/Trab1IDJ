#include "Tileset.h"
#include "Error.h"

TileSet::TileSet(int tileWidth, int tileHeight, string file): tileSet(file), tileWidth(tileWidth), tileHeight(tileHeight)
{
	rows= tileSet.GetHeight()/tileHeight;
	columns= tileSet.GetWidth()/tileWidth;
}

void TileSet::Render(unsigned int index, float x, float y)
{
	ASSERT(index < (unsigned int)rows*columns);
	unsigned int desiredLine, desiredColumn;
	desiredLine= index/columns;
	desiredColumn= index%columns;
	SDL_Rect wantedSubSprite;
	wantedSubSprite.x= desiredColumn*tileWidth;
	wantedSubSprite.y= desiredLine*tileHeight;
	wantedSubSprite.w= tileWidth;
	wantedSubSprite.h= tileHeight;
	SDL_Rect destinyPosition;
	destinyPosition.x=x;
	destinyPosition.y=y;
	destinyPosition.w= tileWidth;
	destinyPosition.h= tileHeight;
}

int TileSet::GetTileHeight(void)
{
	return tileWidth;
}

int TileSet::GetTileWidth(void)
{
	return tileHeight;
}
