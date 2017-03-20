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
	if()
	{

	}
}

