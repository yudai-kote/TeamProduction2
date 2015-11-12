#include "Map.h"

void Map::MapDelete()
{
	chip_block.clear();
}

Map::Map()
{
	Setup(1, Vec2i(5, 5));
}

const void Map::Setplayerlist(Unitlist player_list)
{
	this->player_list.push_back(player_list);
}
const void Map::Setenemylist(Unitlist enemy_list)
{
	this->enemy_list.push_back(enemy_list);
}
const void Map::Sethitrange(int hit_range)
{
	this->hit_range = hit_range;
}

bool Map::Isunitmoving(int unit_num, Direction direction)
{
	//player_unit�̈ړ�����
	if (unit_num < static_cast<int>(player_list.size()))
	{
		for (auto player : player_list)
		{
			if (player.num == unit_num)
			{
				if (player.pos.x() < 0 ||
					player.pos.x() > static_cast<int>(chip_block.size()) ||
					player.pos.y() < 0 ||
					player.pos.y() > static_cast<int>(chip_block[0].size()))
					return false;


				switch (direction)
				{
				case Direction::NORTH:
					if (chip_block[player.pos.y() - 1][player.pos.x()].Getmaptype() == Maptype::LOAD)
						return true;
					else
						return false;
					break;

				case Direction::SOUTH:
					if (chip_block[player.pos.y() + 1][player.pos.x()].Getmaptype() == Maptype::LOAD)
						return true;
					else
						return false;
					break;

				case Direction::WEST:
					if (chip_block[player.pos.y()][player.pos.x() - 1].Getmaptype() == Maptype::LOAD)
						return true;
					else
						return false;
					break;

				case Direction::EAST:
					if (chip_block[player.pos.y()][player.pos.x() + 1].Getmaptype() == Maptype::LOAD)
						return true;
					else
						return false;
					break;
				}
			}
		}
	}

	//enemy_unit�̈ړ�����
	if (unit_num < static_cast<int>(enemy_list.size()))
	{
		for (auto enemy : enemy_list)
		{
			if (enemy.num == unit_num)
			{
				if (enemy.pos.x() < 0 ||
					enemy.pos.x() > static_cast<int>(chip_block.size()) ||
					enemy.pos.y() < 0 ||
					enemy.pos.y() > static_cast<int>(chip_block[0].size()))
					return false;


				switch (direction)
				{
				case Direction::NORTH:
					if (chip_block[enemy.pos.y() - 1][enemy.pos.x()].Getmaptype() == Maptype::LOAD)
						return true;
					else
						return false;
					break;

				case Direction::SOUTH:
					if (chip_block[enemy.pos.y() + 1][enemy.pos.x()].Getmaptype() == Maptype::LOAD)
						return true;
					else
						return false;
					break;

				case Direction::WEST:
					if (chip_block[enemy.pos.y()][enemy.pos.x() - 1].Getmaptype() == Maptype::LOAD)
						return true;
					else
						return false;
					break;

				case Direction::EAST:
					if (chip_block[enemy.pos.y()][enemy.pos.x() + 1].Getmaptype() == Maptype::LOAD)
						return true;
					else
						return false;
					break;
				}
			}
		}
	}

	return false;
}

bool Map::Isattackhit(int unit_num, Direction direction)
{
	//player_unit�̍U������
	if (unit_num < static_cast<int>(player_list.size()))
	{
		for (auto player : player_list)
		{
			if (player.num == unit_num)
			{
				if (player.pos.x() < 0 ||
					player.pos.x() > static_cast<int>(chip_block.size()) ||
					player.pos.y() < 0 ||
					player.pos.y() > static_cast<int>(chip_block[0].size()))
					return false;

				for (auto enemy : enemy_list)
				{
					switch (direction)
					{
					case Direction::NORTH:
						if (player.pos.x() == enemy.pos.x() &&
							player.pos.y() - 1 == enemy.pos.y())
							return true;
						break;

					case Direction::SOUTH:
						if (player.pos.x() == enemy.pos.x() &&
							player.pos.y() + 1 == enemy.pos.y())
							return true;
						break;

					case Direction::WEST:
						if (player.pos.x() - 1 == enemy.pos.x() &&
							player.pos.y() == enemy.pos.y())
							return true;
						break;

					case Direction::EAST:
						if (player.pos.x() + 1 == enemy.pos.x() &&
							player.pos.y() == enemy.pos.y())
							return true;
						break;
					}
				}
			}
		}

		return false;
	}

	//enemy_unit�̍U������
	if (unit_num < static_cast<int>(enemy_list.size()))
	{
		for (auto enemy : enemy_list)
		{
			if (enemy.num == unit_num)
			{
				if (enemy.pos.x() < 0 ||
					enemy.pos.x() > static_cast<int>(chip_block.size()) ||
					enemy.pos.y() < 0 ||
					enemy.pos.y() > static_cast<int>(chip_block[0].size()))
					return false;

				for (auto player : player_list)
				{
					switch (direction)
					{
					case Direction::NORTH:
						if (enemy.pos.x() == player.pos.x() &&
							enemy.pos.y() - 1 == player.pos.y())
							return true;
						break;

					case Direction::SOUTH:
						if (enemy.pos.x() == player.pos.x() &&
							enemy.pos.y() + 1 == player.pos.y())
							return true;
						break;

					case Direction::WEST:
						if (enemy.pos.x() - 1 == player.pos.x() &&
							enemy.pos.y() == player.pos.y())
							return true;
						break;

					case Direction::EAST:
						if (enemy.pos.x() + 1 == player.pos.x() &&
							enemy.pos.y() == player.pos.y())
							return true;
						break;
					}
				}

				return false;
			}
		}
	}

	return false;
}

void Map::Setup(int stage, Vec2i map_num)
{
	chip_block = std::vector<std::vector<Block>>(map_num.y(), std::vector<Block>(map_num.x()));
	hit_range = 0;

	std::string file_name = "res/map_file/stage(" + std::to_string(stage) + ").txt";
	std::ifstream* map_file = new std::ifstream(file_name);

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

	delete map_file;
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