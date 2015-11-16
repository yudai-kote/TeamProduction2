#include "../Chara/Chara.h"

Chara::Chara(){

}

void Chara::Setup(){

}

void Chara::Update(){

}


void Chara::Draw(){

}

Status Chara::WarriorStatus(Status warrior){
	warrior.hp = 100;
	warrior.power = 10;
	warrior.magic_power = 0;
	warrior.defense = 10;
	warrior.magic_defense = 0;

	return Status{
		warrior.hp,
		warrior.power,
		warrior.magic_power,
		warrior.defense,
		warrior.magic_defense,
	};
}

Status Chara::LancerStatus(Status lancer){
	lancer.hp = 70;
	lancer.power = 20;
	lancer.magic_power = 0;
	lancer.defense = 10;
	lancer.magic_defense = 0;

	return Status{
		lancer.hp,
		lancer.power,
		lancer.magic_power,
		lancer.defense,
		lancer.magic_defense,
	};
}

Status Chara::GetStatus(){
	return Status{
		status->hp,
		status->power,
		status->magic_power,
		status->defense,
		status->magic_defense,
	};
}

Unitlist Chara::GetNum(){
	return Unitlist{
		unitlist->num,
	};
}