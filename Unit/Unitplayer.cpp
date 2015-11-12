#include "Unitplayer.h"

Unitplayer::Unitplayer(Unitlist player_unit){
	unitlist = player_unit;

}

void Unitplayer::Setup(){




}

void Unitplayer::Update(){
	if (can_move == false)
	{



	}
}

void Unitplayer::Draw(){


}

//****************************************************************
// セッター
//****************************************************************
void Unitplayer::SetCanMove(bool can_move_){
	can_move = can_move_;
}
void Unitplayer::SetIsAttack(bool is_attack_){
	is_attack = is_attack_;
}

void Unitplayer::SetDirection(Direction ui_direction){
	if (can_move == true)
		Move(ui_direction);
	direction = ui_direction;

}


// 向きによって移動する処理
void Unitplayer::Move(Direction ui_direction){
	int speed = 10;

	switch (direction)
	{
	case Direction::NORTH:
		switch (ui_direction)
		{
		case Direction::NORTH:
			pos.y() += speed;
			break;
		case Direction::SOUTH:
			direction = Direction::SOUTH;
			break;
		case Direction::EAST:
			direction = Direction::EAST;
			break;
		case Direction::WEST:
			direction = Direction::WEST;
			break;
		}
		break;
	case Direction::SOUTH:
		switch (ui_direction)
		{
		case Direction::NORTH:
			direction = Direction::NORTH;
			break;
		case Direction::SOUTH:
			pos.y() -= speed;
			break;
		case Direction::EAST:
			direction = Direction::EAST;
			break;
		case Direction::WEST:
			direction = Direction::WEST;
			break;
		}
		break;
	case Direction::EAST:
		switch (ui_direction)
		{
		case Direction::NORTH:
			direction = Direction::NORTH;
			break;
		case Direction::SOUTH:
			direction = Direction::SOUTH;
			break;
		case Direction::EAST:
			pos.x() += speed;
			break;
		case Direction::WEST:
			direction = Direction::WEST;
			break;
		}
		break;
	case Direction::WEST:
		switch (ui_direction)
		{
		case Direction::NORTH:
			direction = Direction::NORTH;
			break;
		case Direction::SOUTH:
			direction = Direction::SOUTH;
			break;
		case Direction::EAST:
			direction = Direction::EAST;
			break;
		case Direction::WEST:
			pos.x() -= speed;
			break;
		}
		break;
	}

	//if (env.isPushKey(GLFW_KEY_UP))
	//{
	//	direction = Direction::NORTH;
	//}
	//if (env.isPushKey(GLFW_KEY_DOWN))
	//{
	//	direction = Direction::SOUTH;
	//}
	//if (env.isPushKey(GLFW_KEY_RIGHT))
	//{
	//	direction = Direction::EAST;
	//}
	//if (env.isPushKey(GLFW_KEY_LEFT))
	//{
	//	direction = Direction::WEST;
	//}

}

void Unitplayer::Animation(){

	switch (charatype)
	{
	case Animationtype::NORMAL:
		//CharacterAnimation(pos, size, offset_size, chara_normal, 4, 20, 0);
		break;
	case Animationtype::MOVE:
		//CharacterAnimation(pos, size, offset_size, chara_normal, 4, 20, 0);
		break;
	case Animationtype::ATTACK:
		//CharacterAnimation(pos, size, offset_size, chara_normal, 4, 20, 0);
		break;

	}
}


//アニメーション
// Vec2f pos, Vec2f size				ポス, サイズ
// Vec2f offset_size, Texture tx,		画像切り取り幅, 画像
// int count							使う枚数
// int frame							何フレームか
// int num								何番目からか
//
static void CharacterAnimation(Vec2f pos,Vec2f size,Vec2f offset_size,Texture tx,
					  int count,int frame,int num){
	int animation_time1;
	int animation_time2;
	Vec2f offset_pos;
	animation_time1 = (animation_time2++ / frame) % count + num;

	offset_pos.x() = (animation_time1 % 4) * offset_size.x();
	offset_pos.y() = (animation_time1 / 4) * offset_size.y();

	drawTextureBox(pos.x(), pos.y(), size.x(), size.y(),
				   offset_pos.x(), offset_pos.y(), offset_size.x(), offset_size.y(),
				   tx, Color::white);

}