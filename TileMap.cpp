#include "TileMap.h"
#include "Error.h"
#include <cstdio>

#define GAMBIARRA

TileMap::TileMap(string file, TileSet *tileSet): tileSet(tileSet)
{
	Load(file);
}
void TileMap::Load(string file)
{
	FILE *arq= fopen(file.c_str(), "r");
	ASSERT(NULL != arq);
	fscanf(arq, "%d,%d,%d,", &mapWidth, &mapHeight, &mapDepth);
	int numbersToRead= mapWidth*mapHeight*mapDepth;
	tileMatrix.resize(numbersToRead);//assim ele não desperdiça memória nem muda de tamanho no for abaixo
	int aux;
	for(int count=0; count < numbersToRead; count++)
	{
		fscanf(arq, " %d,", &aux);
		tileMatrix[count]= aux-1;
	}
}
void TileMap::SetTileSet(TileSet *tileSet)
{
	ASSERT(this->tileSet->GetTileHeight() <= tileSet->GetTileHeight());
	ASSERT(this->tileSet->GetTileWidth() <= tileSet->GetTileWidth());
	this->tileSet=tileSet;
}
int& TileMap::At(int x, int y, int z) const
{
//	int* vec= (int*)tileMatrix.data();
//	return (vec[z*mapWidth*mapHeight + y*mapWidth + x]);
	return ((int&)tileMatrix.at(z*mapWidth*mapHeight + y*mapWidth + x) );
}
void TileMap::Render(int cameraX, int cameraY) const
{
	for(int count =0; count < mapDepth; count++)
	{
		RenderLayer(count, cameraX, cameraY);
	}
}
void TileMap::RenderLayer(int layer, int cameraX, int cameraY) const
{
	for(int z=0; z < mapDepth; z++)
	{
		for(int x=0; x < mapWidth; x++)
		{
			for(int y=0; y < mapHeight; y++)
			{
				int index= At(x, y, z);
				if(0 <= index)
				{
#ifdef GAMBIARRA
					tileSet->Render(At(x, y, z)%12, x*tileSet->GetTileWidth(), y*tileSet->GetTileHeight());
#else
					tileSet->Render(At(x, y, z), x*tileSet->GetTileWidth(), y*tileSet->GetTileHeight());
#endif
				}
			}
		}
	}
}
int TileMap::GetWidth(void) const
{
	return mapWidth;
}
int TileMap::GetHeight(void) const
{
	return mapHeight;
}
int TileMap::GetDepth(void) const
{
	return mapDepth;
}
