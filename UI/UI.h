#include "../Share/Share.h"
class Ui{
private:
	Vec2f command_board_pos;
	Vec2f command_board_size;
	Vec2f status_board_pos;
	Vec2f status_board_size;
public:
	Ui();
	void Update();
	void Draw();

};