#include "Unitplayer.h"

Unitplayer::Unitplayer(){


}

void Unitplayer::Setup(){
	



}

void Unitplayer::Update(){
	if (is_move == false)
	{
	


	}
}

void Unitplayer::Draw(){


}

// 向きによって移動する処理
void Unitplayer::move(){
	switch (direction)
	{
	case Direction::NORTH:

		break;
	case Direction::SOUTH:

		break;
	case Direction::EAST:

		break;
	case Direction::WEST:

		break;
	}

	if (env.isPushKey(GLFW_KEY_UP))
	{
		direction = Direction::NORTH;
	}
	if (env.isPushKey(GLFW_KEY_DOWN))
	{
		direction = Direction::SOUTH;
	}
	if (env.isPushKey(GLFW_KEY_RIGHT))
	{
		direction = Direction::EAST;
	}
	if (env.isPushKey(GLFW_KEY_LEFT))
	{
		direction = Direction::WEST;
	}

}

//****************************************************************
// セッター
//****************************************************************
void Unitplayer::SetIsMove(bool is_move_){
	is_move = is_move_;
}