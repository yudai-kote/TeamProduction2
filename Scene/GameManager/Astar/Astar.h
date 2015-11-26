#pragma once
#include "../../../lib/framework.hpp"
#include "../../../Share/Share.h"

class Astar
{
private:

	Font font = Font("res/kokubanB.ttf");
	class AstarChip
	{
	public:
		int status = 0;
		int search = 0;
		int cost = 0;
		int parent = 0;
		Vec2i pos = Vec2i(0, 0);
		Vec2i size = Vec2i(CHIPSIZE_X, CHIPSIZE_Y);
	};

	enum Block{
		AIR_BLOCK,
		BLOCK,
	};
	enum Search{
		NONE,	//’²‚×‚Ä‚¢‚È‚¢ó‘Ô
		OPEN,	//’²‚×‚Ä‚¢‚éó‘Ô
		CLOSE,	//’²‚×I‚í‚Á‚½ó‘Ô
	};

	int nowCost(Vec2i _player_pos);
	void algorithm();

	int parentUpdate(Vec2i enemy_pos);

	Vec2i _player_pos;

	Vec2i _enemy_pos;
	int enemy_start_parent;
	Vec2i enemy_end_pos;


	Vec2i now_pos = Vec2i::Zero();

	std::vector<std::vector<AstarChip>> map;
	void algorithm2();

public:

	Astar();

	void setup(Vec2f enemy_pos, Vec2f player_pos);
	void update();

	void draw();

	int getParentPlayer();

	void setEnemyPos(Vec2f enemy_pos);
	void setPlayerPos(Vec2f player_pos);
	void setMap(std::vector<std::vector<int>>setmap);

	bool HitGoll(Vec2f enemy_pos, Vec2f player_pos, std::vector<std::vector<int>>setmap);
};

