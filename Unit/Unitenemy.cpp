#include "Unitenemy.h"

void Unitenemy::update(){
	astar.setEnemyPos(pos);
	astar.update();
}

void Unitenemy::draw(){
	drawFillBox(pos.x() * 50, pos.y() * 50, size.x(), size.y(), Color::red);
	astar.draw();
}

Vec2f Unitenemy::getPos(){
	return pos;
}

void Unitenemy::setDirection(int direction){

	if (env.isPushKey(GLFW_KEY_SPACE)){
#if(1)
		switch (direction)
		{
		case static_cast<int>(Direction::NORTH):
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

void Unitenemy::setPos(Vec2f getpos){
	pos = getpos;
}


void Unitenemy::setAstarMap(std::vector<std::vector<int>> getmap){
	astar.setMap(getmap);
}

void Unitenemy::setAstarPlayerPos(Vec2f player_pos){
	if (player_pos != pos){
		setDirection(astar.getParentPlayer());
	}
	astar.setPlayerPos(player_pos);
	//std::cout << "Ž~‚Ü‚Á‚Ä@" <<  pos << std::endl;
}

void Unitenemy::astarSetup(Vec2f player_pos){
	astar.setup(pos, player_pos);
}
