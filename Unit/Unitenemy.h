#pragma once
#include "../Share/Share.h"
#include "../Unit/Enemy/Enemy.h"
#include "../Scene/Gamemanager/Astar/Astar.h"


class Unitenemy : public Chara{
private:

	Astar astar;

	int move_cost = 10;
	bool is_move = false;
	

public:

	Unitenemy();

	void Setup();
	void Update();
	void Draw();


	void SetDirection(Direction direction);
	void SetUnitlistPos(Vec2i getpos);
	void SetDrawPos(Vec2i getpos);
	void SetAstarMap(std::vector<std::vector<int>> getmap);
	void SetAstarPlayerPos(Vec2i pos);
	void AstarSetup(Vec2i pos);
	void SetCost(int getcost);
	void SetIsMove(bool getis_move);

	Vec2i GetPos();
	int GetNum();
	Unitlist GetUnitlist();
	Status GetStatus();
	Direction GetDirection();
	int GetCost();
	bool GetIsMove();


};