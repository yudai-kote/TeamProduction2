#pragma once
#include "../../Share/Share.h"
#include "../../Classbase.h"
#include "Attack\Attack.h"





class Chara : public Classbase{
private:

protected:
	Attack attack;


	enum class Animationtype
	{
		NORMAL,
		MOVE,
		ATTACK,
	};

	Vec2f pos = Vec2f::Zero();
	Vec2f size = Vec2f(50.0f, 100.0f);
	Vec2f offset_pos = Vec2f::Zero();
	Vec2f offset_size = Vec2f::Zero();
	Direction direction;
	bool can_move;
	bool is_attack;
	Vec2f move_limit = Vec2f(CHIPSIZE_X, CHIPSIZE_Y);
	
	//int num;

	Animationtype chara_type;

	Color color;
	Unitlist* unitlist;
	Status* status;

	struct Unitvalue{

	};


	Status WarriorStatus(Status warrior);
	Status LancerStatus(Status lancer);

public:
	Chara();

	void Setup();
	void Update();
	void Draw();


};

