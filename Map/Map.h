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

	//for文で回してpush_back()してください
	void Setplayerlist(Unitlist);
	void Setenemylist(Unitlist);

	void Sethitrange(int);

	//(行動するユニットの番号, 行動する向き)
	bool Isunitmoving(int, Direction);
	bool Isattackhit(int, Direction);

	//（マップのナンバー, マップの数）
	void Setup(int, Vec2i);
	void Update();
	void Draw();
	//カーソルのマップチップでの座標を渡せば
	//今指している場所を光らせる
	void Drawcursolpos(Vec2i);

};