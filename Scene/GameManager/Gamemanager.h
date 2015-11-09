#pragma once
#include "../../Share/Share.h"
#include "Unitselect/Unitselect.h"
#include "../../Classbase.h"

class Gamemanager : public Classbase{

private:

	Unitselect unitselect_;
	Scenename gamechange;

public:
	Gamemanager();

	void Setup();
	void Update();
	void Draw();
	void Shift();
	Scenename Titleshift();


};