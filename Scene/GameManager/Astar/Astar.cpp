#include "Astar.h"

Astar::Astar(){
	map = std::vector<std::vector<AstarChip>>(WIDE, std::vector<AstarChip>(LENGTH));

	for (unsigned y = 0; y < map.size(); y++)
	{
		for (unsigned x = 0; x < map[y].size(); x++)
		{
			map[y][x].status = 0;
			map[y][x].search = NONE;
			map[y][x].parent = static_cast<int>(Direction::NONE);
			map[y][x].pos.x() = map[y][x].pos.x() + map[y][x].size.x() * x;
			map[y][x].pos.y() = map[y][x].pos.y() + map[y][x].size.y() * y;
		}
	}
}


void Astar::setup(Vec2f enemy_pos, Vec2f player_pos){

	_enemy_pos = Vec2i((float)enemy_pos.x(), (float)enemy_pos.y());
	_player_pos = Vec2i((float)player_pos.x(), (float)player_pos.y());

	map[_player_pos.y()][_player_pos.x()].search = OPEN;

	enemy_start_parent = 5;

}


int Astar::nowCost(Vec2i _player_pos){
	return std::abs(_enemy_pos.x() - _player_pos.x()) + std::abs(_enemy_pos.y() - _player_pos.y());
}

void Astar::algorithm(){

	int cost_min = 1000000;
	Vec2i once_pos = Vec2i::Zero();

	if (_enemy_pos == _player_pos)
	{
		return;
	}

	for (int y = 0; y < map.size(); y++)
	{
		for (int x = 0; x < map[y].size(); x++)
		{
			if (map[y][x].search == OPEN)
			{
				if (nowCost(Vec2i(x, y)) < cost_min)
				{
					if (map[y][x].status != BLOCK)
					{
						once_pos = Vec2i(x, y);
						cost_min = nowCost(once_pos);
					}
				}
			}

		}
	}

	map[once_pos.y()][once_pos.x()].search = CLOSE;

	for (int direction = 0; direction < static_cast<int>(Direction::NONE); direction++)
	{
		Vec2i search_pos = once_pos;

		switch (direction)
		{
		case static_cast<int>(Direction::NORTH) :
			search_pos.y() -= 1;
			break;
		case static_cast<int>(Direction::SOUTH) :
			search_pos.y() += 1;
			break;
		case static_cast<int>(Direction::WEST) :
			search_pos.x() -= 1;
			break;
		case static_cast<int>(Direction::EAST) :
			search_pos.x() += 1;
			break;
		}

		if (search_pos.x() >= 0 && search_pos.y() >= 0)
		{
			if (search_pos.x() < static_cast<int>(WIDE) && search_pos.y() < static_cast<int>(LENGTH))
			{
				if (map[search_pos.y()][search_pos.x()].search == NONE)
				{
					if (map[search_pos.y()][search_pos.x()].status != BLOCK){
						switch (direction)
						{
						case static_cast<int>(Direction::NORTH) :
							map[search_pos.y()][search_pos.x()].parent = static_cast<int>(Direction::SOUTH);
							break;
						case static_cast<int>(Direction::SOUTH) :
							map[search_pos.y()][search_pos.x()].parent = static_cast<int>(Direction::NORTH);
							break;
						case static_cast<int>(Direction::WEST) :
							map[search_pos.y()][search_pos.x()].parent = static_cast<int>(Direction::EAST);
							break;
						case static_cast<int>(Direction::EAST) :
							map[search_pos.y()][search_pos.x()].parent = static_cast<int>(Direction::WEST);
							break;
						}
						map[search_pos.y()][search_pos.x()].search = OPEN;
					}
				}
			}
		}

	}

	if (map[_enemy_pos.y()][_enemy_pos.x()].search != OPEN){
		algorithm();
	}
}

int Astar::parentUpdate(Vec2i _enemy_pos){
	if (_enemy_pos == _player_pos)
	{
		return enemy_start_parent;
	}

	switch (map[_enemy_pos.y()][_enemy_pos.x()].parent)
	{
	case static_cast<int>(Direction::NORTH) :
		enemy_start_parent = map[_enemy_pos.y()][_enemy_pos.x()].parent;
		font.draw("↑", Vec2f((float)map[_enemy_pos.y()][_enemy_pos.x()].pos.x(), (float)map[_enemy_pos.y()][_enemy_pos.x()].pos.y()), Color::cyan);
		parentUpdate(Vec2i(_enemy_pos.x(), _enemy_pos.y() - 1));
		break;
	case static_cast<int>(Direction::SOUTH) :
		enemy_start_parent = map[_enemy_pos.y()][_enemy_pos.x()].parent;
		font.draw("↓", Vec2f((float)map[_enemy_pos.y()][_enemy_pos.x()].pos.x(), (float)map[_enemy_pos.y()][_enemy_pos.x()].pos.y()), Color::cyan);
		parentUpdate(Vec2i(_enemy_pos.x(), _enemy_pos.y() + 1));
		break;
	case static_cast<int>(Direction::WEST) :
		enemy_start_parent = map[_enemy_pos.y()][_enemy_pos.x()].parent;
		font.draw("←", Vec2f((float)map[_enemy_pos.y()][_enemy_pos.x()].pos.x(), (float)map[_enemy_pos.y()][_enemy_pos.x()].pos.y()), Color::cyan);
		parentUpdate(Vec2i(_enemy_pos.x() - 1, _enemy_pos.y()));
		break;
	case static_cast<int>(Direction::EAST) :
		enemy_start_parent = map[_enemy_pos.y()][_enemy_pos.x()].parent;
		font.draw("→", Vec2f((float)map[_enemy_pos.y()][_enemy_pos.x()].pos.x(), (float)map[_enemy_pos.y()][_enemy_pos.x()].pos.y()), Color::cyan);
		parentUpdate(Vec2i(_enemy_pos.x() + 1, _enemy_pos.y()));
		break;
	}

}


void Astar::draw(){

}


void Astar::update(){

	for (int y = 0; y < map.size(); y++)
	{
		for (int x = 0; x < map[y].size(); x++)
		{
			map[y][x].search = NONE;
			map[y][x].parent = 5;
		}
	}

	map[_player_pos.y()][_player_pos.x()].search = OPEN;

	algorithm();
	parentUpdate(_enemy_pos);


}


int Astar::getParentPlayer(){
	if (_enemy_pos == _player_pos)
	{
		return enemy_start_parent;
	}

	switch (map[_enemy_pos.y()][_enemy_pos.x()].parent)
	{
	case static_cast<int>(Direction::NORTH) :
		return map[_enemy_pos.y()][_enemy_pos.x()].parent;
		break;
	case static_cast<int>(Direction::SOUTH) :
		return map[_enemy_pos.y()][_enemy_pos.x()].parent;
		break;
	case static_cast<int>(Direction::WEST) :
		return map[_enemy_pos.y()][_enemy_pos.x()].parent;
		break;
	case static_cast<int>(Direction::EAST) :
		return map[_enemy_pos.y()][_enemy_pos.x()].parent;
		break;
	}
	return 5;
}


void Astar::setEnemyPos(Vec2f enemy_pos){
	_enemy_pos = Vec2i((float)enemy_pos.x(), (float)enemy_pos.y());
	enemy_end_pos = Vec2i((float)enemy_pos.x(), (float)enemy_pos.y());
}

void Astar::setPlayerPos(Vec2f player_pos){
	_player_pos = Vec2i((float)player_pos.x(), (float)player_pos.y());
}

void Astar::setMap(std::vector<std::vector<int>>setmap){
	map = std::vector<std::vector<AstarChip>>(static_cast<int>(WIDE), std::vector<AstarChip>(static_cast<int>(LENGTH)));

	for (unsigned y = 0; y < map.size(); y++)
	{
		for (unsigned x = 0; x < map[y].size(); x++)
		{
			map[y][x].status = setmap[y][x];
		}
	}

}

///ゴールのマス
///目標のマス
///現在のマップ情報
///返り値はalgorithmを３０回してゴールが見たかった場合true
//違うときはfalse
bool Astar::HitGoll(Vec2f enemy_pos, Vec2f player_pos, std::vector<std::vector<int>>setmap){

	for (unsigned y = 0; y < map.size(); y++)
	{
		for (unsigned x = 0; x < setmap[y].size(); x++)
		{
			map[y][x].status = setmap[y][x];
		}
	}

	int count = 0;
	while (count<30)
	{
		count++;
		algorithm2();
	}
	return map[_enemy_pos.y()][_enemy_pos.x()].search != OPEN;

}

void Astar::algorithm2(){

	int cost_min = 1000000;
	Vec2i once_pos = Vec2i::Zero();

	if (_enemy_pos == _player_pos)
	{
		return;
	}

	for (int y = 0; y < map.size(); y++)
	{
		for (int x = 0; x < map[y].size(); x++)
		{
			if (map[y][x].search == OPEN)
			{
				if (nowCost(Vec2i(x, y)) < cost_min)
				{
					if (map[y][x].status != BLOCK)
					{
						once_pos = Vec2i(x, y);
						cost_min = nowCost(once_pos);
					}
				}
			}

		}
	}

	map[once_pos.y()][once_pos.x()].search = CLOSE;

	for (int direction = 0; direction < static_cast<int>(Direction::NONE); direction++)
	{
		Vec2i search_pos = once_pos;

		switch (direction)
		{
		case static_cast<int>(Direction::NORTH) :
			search_pos.y() -= 1;
			break;
		case static_cast<int>(Direction::SOUTH) :
			search_pos.y() += 1;
			break;
		case static_cast<int>(Direction::WEST) :
			search_pos.x() -= 1;
			break;
		case static_cast<int>(Direction::EAST) :
			search_pos.x() += 1;
			break;
		}

		if (search_pos.x() >= 0 && search_pos.y() >= 0)
		{
			if (search_pos.x() < static_cast<int>(WIDE) && search_pos.y() < static_cast<int>(LENGTH))
			{
				if (map[search_pos.y()][search_pos.x()].search == NONE)
				{
					if (map[search_pos.y()][search_pos.x()].status != BLOCK){
						switch (direction)
						{
						case static_cast<int>(Direction::NORTH) :
							map[search_pos.y()][search_pos.x()].parent = static_cast<int>(Direction::SOUTH);
							break;
						case static_cast<int>(Direction::SOUTH) :
							map[search_pos.y()][search_pos.x()].parent = static_cast<int>(Direction::NORTH);
							break;
						case static_cast<int>(Direction::WEST) :
							map[search_pos.y()][search_pos.x()].parent = static_cast<int>(Direction::EAST);
							break;
						case static_cast<int>(Direction::EAST) :
							map[search_pos.y()][search_pos.x()].parent = static_cast<int>(Direction::WEST);
							break;
						}
						map[search_pos.y()][search_pos.x()].search = OPEN;
					}
				}
			}
		}

	}


}