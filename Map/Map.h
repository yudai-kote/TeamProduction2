#pragma once
#include "Block/Block.h"


class Map
{
private:

	std::vector<std::vector<Block>> chip_block;

	std::list<Unitlist> player_list;
	std::list<Unitlist> enemy_list;
	int hit_range;

	void MapDelete();

public:

	Map();

	const void Setplayerlist(Unitlist);
	const void Setenemylist(Unitlist);
	const void Sethitrange(int);

	bool Isunitmoving(int, Direction);
	bool Isattackhit(int, Direction);

	//（マップの数）
	void Setup(int, Vec2i);
	void Update();
	void Draw();

};