#pragma once
#include "../../Share/Share.h"
#include "../../Classbase.h"
#include "Attack\Attack.h"





class Chara : public Classbase{
private:
protected:
	Attack attack;

	enum class Job
	{
		WARRIOR,	//êÌém
		LANCER,		//ÉâÉìÉTÅ[
	};
	enum class Animationtype
	{
		NORMAL,
		MOVE,
		ATTACK,
	};

	Vec2f pos;
	Vec2f size;
	Vec2f offset_size = Vec2f::Zero();
	Direction direction;
	bool can_move;
	bool is_attack;
	Animationtype charatype;
	Unitlist unitlist;

	Status WarriorStatus(Status warrior);
	Status LancerStatus(Status lancer);

public:
	Chara();




	void Setup();
	void Update();
	void Draw();

	Status GetStatus();

};

