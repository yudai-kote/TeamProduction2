#include "UI.h"

Ui::Ui(){
	command_board_pos = Vec2f(-960, -540);
	command_board_size = Vec2f(400, 1080);
	status_board_pos = Vec2f(-560, -540);
	status_board_size = Vec2f(1560, 300);
}

void Ui::Update(){

}

void Ui::Draw(){
	drawFillBox(command_board_pos.x(), command_board_pos.y(),
		command_board_size.x(), command_board_size.y(),
		Color::red);
	drawFillBox(status_board_pos.x(), status_board_pos.y(),
		status_board_size.x(), status_board_size.y(),
		Color::blue);
}