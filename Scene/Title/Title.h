#pragma once
#include "../../lib/framework.hpp"
#include "../../Share/Share.h"
#include "../../Classbase.h"

class Title : public Classbase{

private:

	Texture title;
	Texture press_enter;

public:

	Title();

	void Setup();
	void Update();
	void Draw();
	Scenename Shift();



};