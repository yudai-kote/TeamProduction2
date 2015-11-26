#include "Unitenemy.h"

Unitenemy::Unitenemy(){
	direction = Direction::NONE;
	is_attack = false;
	can_move = false;
	chara_type = Animationtype::NORMAL;
}

void Unitenemy::Setup(){


}
void Unitenemy::Update(){
	astar.setEnemyPos(unitlist->pos);
	astar.update();
}

void Unitenemy::Draw(){
	drawFillBox(pos.x(), pos.y(), size.x(), size.y(), color);
	astar.draw();
}
//****************************************************************
// セッター
//****************************************************************
void Unitenemy::SetDirection(int direction){

	if (env.isPushKey(GLFW_KEY_SPACE)){
#if(1)
		switch (direction)
		{
		case static_cast<int>(Direction::NORTH) :
			pos.y() += 1;
			break;
		case static_cast<int>(Direction::SOUTH) :
			pos.y() -= 1;
			break;
		case static_cast<int>(Direction::WEST) :
			pos.x() -= 1;
			break;
		case static_cast<int>(Direction::EAST) :
			pos.x() += 1;
			break;
		}

#else if
		if (env.isPushKey('W')){ pos.y() -= 1; }
		if (env.isPushKey('S')){ pos.y() += 1; }
		if (env.isPushKey('A')){ pos.x() -= 1; }
		if (env.isPushKey('D')){ pos.x() += 1; }
#endif

	}
}

void Unitenemy::SetUnitlistPos(Vec2i getpos){
	unitlist->pos = getpos;
	SetDrawPos(getpos);
}

void Unitenemy::SetDrawPos(Vec2i getpos){
	pos.x() = getpos.x() * CHIPSIZE_X;
	pos.y() = getpos.y() * CHIPSIZE_Y;
}

void Unitenemy::SetAstarMap(std::vector<std::vector<int>> getmap){
	astar.setMap(getmap);
}

void Unitenemy::SetAstarPlayerPos(Vec2i player_pos){
	if (player_pos != unitlist->pos){
		SetDirection(astar.getParentPlayer());
	}
	astar.setPlayerPos(player_pos);
}

void Unitenemy::AstarSetup(Vec2i player_pos){
	astar.setup(unitlist->pos, player_pos);
}

//****************************************************************
// ゲッター
//****************************************************************

Vec2i Unitenemy::GetPos(){
	return unitlist->pos;
}

int Unitenemy::GetNum(){
	return unitlist->num;
}
Unitlist Unitenemy::GetUnitlist(){
	return Unitlist{
		unitlist->num,
		unitlist->pos,
	};
}
Status Unitenemy::GetStatus(){
	return Status{
		status->hp,
		status->power,
		status->magic_power,
		status->defense,
		status->magic_defense,
	};
}

