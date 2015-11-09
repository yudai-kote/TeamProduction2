#pragma once
#include "Block/Block.h"





class Map
{
private:

	std::vector<std::vector<Block>> chip_block;

	std::list<Unitlist> player_list;
	std::list<Unitlist> enemy_list;
	int hit_range;

public:

	Map();

	const void Setplayerlist(Unitlist);
	const void Setenemylist(Unitlist);

	//（マップのサイズ）
	void Setup(Vec2i);
	void Update();
	void Draw();

};