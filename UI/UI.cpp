#include "UI.h"

Ui::Ui(){
	font.size(font_size);
	animation = 0;
	angle = 0;
	instruction = 0;
	action = false;
	attack = false;
	skill = false;
	dir = false;
	command_board.pos = Vec2f(-960, -540);
	command_board.size = Vec2f(300, 1080);

	status_board.pos = Vec2f(-660, -540);
	status_board.size = Vec2f(1660, 300);

	command.pos = Vec2f(-950, 440);
	command.size = Vec2f(70, 50);
}

void Ui::Update(){


	Animation();
}

void Ui::Draw(Status status){
	drawFillBox(command_board.pos.x(), command_board.pos.y(),
		command_board.size.x(), command_board.size.y(),
		Color::red);
	drawFillBox(status_board.pos.x(), status_board.pos.y(),
		status_board.size.x(), status_board.size.y(),
		Color::blue);
	drawFillBox(command.pos.x() + animation, command.pos.y(),
		command.size.x(), command.size.y(),
		Color::white);
	font.draw("ActiveNo." + std::to_string(number),
		Vec2f(-WIDTH / 3, -250 - font_size), Color::white);
	font.draw("体力　　　　" + std::to_string(status.hp),
		Vec2f(-WIDTH / 3, -350 - font_size), Color::white);

	font.draw("攻撃力　　　" + std::to_string(status.power),
		Vec2f(-WIDTH / 20, -250 - font_size * 2), Color::white);

	font.draw("魔法攻撃力　" + std::to_string(status.magic_power),
		Vec2f(-WIDTH / 20, -300 - font_size * 3), Color::white);

	font.draw("防御力　　　" + std::to_string(status.defense),
		Vec2f(350, -150 - font_size * 4), Color::white);

	font.draw("魔法防御力　" + std::to_string(status.magic_defense),
		Vec2f(350, -200 - font_size * 5), Color::white);

	font.draw("移動", Vec2f(-830, 445), Color::white);
	font.draw("攻撃", Vec2f(-830, 445 - 150), Color::white);
	font.draw("スキル", Vec2f(-830, 445 - 300), Color::white);
	font.draw("STATUS", Vec2f(-830, 445 - 450), Color::white);
	font.draw("行動P" + std::to_string((int)cost), Vec2f(-830, 445 - 600), Color::white);
}




void Ui::OperatePlayer(){
	if (action == true){
		if (env.isPushKey('W')){
			direction = Direction::NORTH;
			if (s_direction == direction){
				cost--;
				p_direction = Direction::NORTH;
				dir = false;
				goto End;
			}
			else{
				cost--;
				direction = Direction::NORTH;
				dir = true;
				goto End;
			}

		}
		if (env.isPushKey('A')){
			direction = Direction::WEST;
			if (s_direction == direction){
				cost--;
				p_direction = Direction::WEST;
				dir = false;
				goto End;
			}
			else{
				cost--;
				direction = Direction::WEST;
				dir = true;
				goto End;
			}

		}
		if (env.isPushKey('S')){
			direction = Direction::SOUTH;
			if (s_direction == direction){
				cost--;
				p_direction = Direction::SOUTH;
				dir = false;
				goto End;
			}
			else{
				cost--;
				direction = Direction::SOUTH;
				dir = true;
				goto End;
			}
		}
		if (env.isPushKey('D')){
			direction = Direction::EAST;
			if (s_direction == direction){
				cost--;
				p_direction = Direction::EAST;
				dir = false;
				goto End;
			}
			else{
				cost--;
				direction = Direction::EAST;
				dir = true;
				goto End;
			}

		}
		if (env.isPushKey(GLFW_KEY_BACKSPACE)){
			action = false;

		}
		direction = Direction::NONE;
		p_direction = Direction::NONE;
		
	}
	direction = Direction::NONE;
	p_direction = Direction::NONE;
End:;
}




void Ui::OperateCursor(){
	if (action == false){
		if (instruction > 0){
			if (env.isPushKey('W')){
				instruction--;
				command.pos.y() += 150;
			}
		}
		if (instruction < 5){
			if (env.isPushKey('S')){
				instruction++;
				command.pos.y() -= 150;
			}
		}
		if (number > 1){
			if (env.isPushKey('A')){
				number--;
			}
		}
		if (env.isPushKey('D')){
			number++;
		}
	}
}

void Ui::Select(){
	if (env.isPushKey(GLFW_KEY_ENTER)){
		switch (instruction)
		{
		case 0:
			action = true;

			break;
		case 1:
			AttakPlayer();
			action = true;
			break;
		case 2:
			SkillPlayer();
			action = true;
			break;
		}
	}
}

void Ui::Move(){

	OperateCursor();

	Select();



}

void Ui::False(){

}

void Ui::AttakPlayer(){//int end){
	//if (end == true){
	action = false;
	attack = false;
	//}
	//	else {
	//		attack = true;
	//	}
}

void Ui::SkillPlayer(){

}

void Ui::Animation(){
	animation = std::sin(angle) * 25;
	angle += 0.09;
	if (animation < 0){
		angle = 0;
	}
}




int Ui::GetUnitNum(){
	return number;
}

bool Ui::IsAttacked(){
	return attack;
}

bool Ui::IsSkilled(){
	return skill;
}

Vec2i Ui::GetUnitPos(){
	return player_pos;
}

int Ui::GetPlayerCost(){
	return (int)cost;
}
Direction Ui::GetDir(){
	return direction;
}
Direction Ui::GetPDir(){
	return p_direction;
}
bool Ui::GetDirection(){
	return dir;
}

void Ui::SetUnitNum(int set){
	number = set;
}

void Ui::SetUnitPos(Vec2i pos){
	player_pos = pos;
}
void Ui::SetPlayerCost(int cost){
	this->cost = cost;
}
void Ui::SetDir(Direction set){
	direction = set;
}
void Ui::SetPDir(Direction set){
	s_direction = set;
}