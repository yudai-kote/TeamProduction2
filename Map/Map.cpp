#include "Map.h"

Map::Map()
{

}

void Map::Setup()
{

}

void Map::Update()
{

}

void Map::Draw()

{
	for (unsigned int y = 0; y < chip_block.size(); y++)
	{
		for (unsigned int x = 0; x < chip_block[y].size(); x++)
		{
			switch (chip_block[y][x].Getmaptype())
			{
			case Maptype::LOAD:
				break;

			case Maptype::NONE:
				break;
			}
		}
	}
}