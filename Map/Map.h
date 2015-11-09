#pragma once
#include "Block/Block.h"



class Map : public Classbase
{
private:

	std::vector<std::vector<Block>> chip_block;

public:

	Map();

	void Setup();
	void Update();
	void Draw();

};