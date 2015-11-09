#pragma once
#include "../../Share/Share.h"
#include "../../Classbase.h"
#include "Attack\Attack.h"





class Chara : public Classbase{
private:
protected:
	Attack attack;

	enum class Job{
		WARRIOR,	//ím
		LANCER,		//ƒ‰ƒ“ƒT[
	};


	Vec2f pos;
	Vec2f size;
	Direction direction;
	bool is_move;

	

	Status WarriorStatus(Status warrior);
	Status LancerStatus(Status lancer);

public:
	Chara();




	void Setup();
	void Update();
	void Draw();

	Status GetStatus();

};

