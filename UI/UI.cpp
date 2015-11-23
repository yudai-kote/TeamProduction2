#include "UI.h"

Ui::Ui(){
	font.size(font_size);
	animation = 0;
	angle = 0;
	instruction = 0;
	action = false;
	command_board.pos = Vec2f(-960, -540);
	command_board.size = Vec2f(400, 1080);

	status_board.pos = Vec2f(-560, -540);
	status_board.size = Vec2f(1560, 300);

	command.pos = Vec2f(-920, 440);
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
	font.draw("体力　　　　" + std::to_string(status.hp),
		Vec2f(-WIDTH / 3, 200 - font_size), Color::white);

	font.draw("攻撃力　　　" + std::to_string(status.power),
		Vec2f(-WIDTH / 3, 200 - font_size * 2), Color::white);

	font.draw("魔法攻撃力　" + std::to_string(status.magic_power),
		Vec2f(-WIDTH / 3, 200 - font_size * 3), Color::white);

	font.draw("防御力　　　" + std::to_string(status.defense),
		Vec2f(-WIDTH / 3, 200 - font_size * 4), Color::white);

	font.draw("魔法防御力　" + std::to_string(status.magic_defense),
		Vec2f(-WIDTH / 3, 200 - font_size * 5), Color::white);

}

void Ui::OperatePlayer(){
	if (env.isPushKey('W')){
		direction = Direction::NORTH;
	}
	if (env.isPushKey('A')){
		direction = Direction::WEST;
	}
	if (env.isPushKey('S')){
		direction = Direction::SOUTH;
	}
	if (env.isPushKey('D')){
		direction = Direction::EAST;
	}
	if (env.isPushKey(GLFW_KEY_BACKSPACE)){
		action = false;
		direction = Direction::NONE;
	}
}

void Ui::OperateCursor(){
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

void Ui::Select(){
	if (env.isPushKey(GLFW_KEY_ENTER)){
		switch (instruction)
		{
		case 0:
			action = true;
			OperatePlayer();
			break;
		case 1:
			action = true;


		}
	}
}

void Ui::Move(){
	if (action == true){
		OperatePlayer();
	}
	else{
		OperateCursor();
	}
	Select();

}

void Ui::AttakPlayer(int end){
	if (end == true){
		action = false;
		attack = false;
	}
	else {
		attack = true;
	}
}

void Ui::Animation(){
	animation = std::sin(angle) * 25;
	angle += 0.09;
	if (animation < 0){
		angle = 0;
	}
}

Direction Ui::GetDir(){
	return direction;
}

int Ui::GetUnitNum(){
	return number;
}

bool Ui::IsAttacked(){
	return attack;
}

void Ui::SetDir(Direction set){
	direction = set;
}

void Ui::SetUnitNum(int set){
	number = set;
}

