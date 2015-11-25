#pragma once
#include "../Share/Share.h"
#include "../Unit/Enemy/Enemy.h"
#include "../Scene/Gamemanager/Astar/Astar.h"


class Unitenemy : public Chara{
private:

	Astar astar;

public:


	void Setup();
	void Update();
	void Draw();

	Unitenemy(Vec2f itrpos){
		pos = itrpos;
	};

	void draw();
	void update();

	Vec2f getPos();
	void setDirection(int direction);
	void setPos(Vec2f getpos);


	void setAstarMap(std::vector<std::vector<int>> getmap);
	void setAstarPlayerPos(Vec2f pos);
	void astarSetup(Vec2f pos);

};