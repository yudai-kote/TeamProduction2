#include "Map.h"

Map::Map()
{
	Setup(Vec2i(5, 5));
}

const void Map::Setplayerlist(Unitlist player_list)
{
	this->player_list.push_back(player_list);
}
const void Map::Setenemylist(Unitlist enemy_list)
{
	this->enemy_list.push_back(enemy_list);
}

void Map::Setup(Vec2i map_num)
{
	chip_block = std::vector<std::vector<Block>>(map_num.y(), std::vector<Block>(map_num.x()));
	hit_range = 0;


	const char* map_txt = "res/map_file/test_map.txt";
	std::ifstream* map_file = new std::ifstream(map_txt);

	if (map_file->fail())
	{
		std::cerr << "err" << std::endl;

		exit(0);
	}

	int map_type;

	for (int y = 0; y < map_num.y(); y++)
	{
		for (int x = 0; x < map_num.x(); x++)
		{
			*map_file >> map_type;

			chip_block[y][x].Setmaptype(map_type);
		}
	}

	/*delete map_txt;
	delete map_file;*/
}

void Map::Update()
{

}

void Map::Draw()

{
	for (int y = 0; y < static_cast<int>(chip_block.size()); y++)
	{
		for (int x = 0; x < static_cast<int>(chip_block[y].size()); x++)
		{
			switch (chip_block[y][x].Getmaptype())
			{
			case Maptype::LOAD:
				drawFillBox(x*CHIPSIZE_X, -y* CHIPSIZE_Y, CHIPSIZE_X - 1, CHIPSIZE_Y - 1, Color::green);
				break;

			case Maptype::NONE:
				break;
			}
		}
	}
}