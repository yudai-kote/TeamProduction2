#include "Unitenemy.h"

Unitenemy::Unitenemy(){
	pos = Vec2f(0, 0);
	size = Vec2f(100, 200);
	direction = Direction::NONE;
	can_move = false;
	is_attack = false;
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

void Unitenemy::Move(){
	Vec2i speed = Vec2i(CHIPSIZE_X, CHIPSIZE_Y);
	if (env.isPushKey(GLFW_KEY_SPACE))
	{
		move_cost--;
		switch (direction)
		{
		case Direction::NORTH:
			unitlist->pos.y() += 1;
			pos.y() += speed.y();
			break;
		case Direction::SOUTH:
			unitlist->pos.y() -= 1;
			pos.y() -= speed.y();
			break;
		case Direction::WEST:
			unitlist->pos.x() += 1;
			pos.x() -= speed.x();
			break;
		case Direction::EAST:
			unitlist->pos.x() -= 1;
			pos.x() += speed.x();
			break;
		}

		if (move_cost <= 0)
		{
			is_move = true;
		}


	}
}

//****************************************************************
// セッター
//****************************************************************
void Unitenemy::SetDirection(Direction getdirection){
	direction = getdirection;
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
		SetDirection(static_cast<Direction>(astar.getParentPlayer()));
	}
	astar.setPlayerPos(player_pos);
}

void Unitenemy::AstarSetup(Vec2i player_pos){
	astar.setup(unitlist->pos, player_pos);
}

void Unitenemy::SetCost(int getcost){
	move_cost = getcost;
}

void Unitenemy::SetIsMove(bool getis_move){
	is_move = getis_move;
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


Direction Unitenemy::GetDirection(){
	return direction;
}

int Unitenemy::GetCost(){
	return move_cost;
}
bool Unitenemy::GetIsMove(){
	return is_move;
}