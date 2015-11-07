#pragma once
#include "../lib/framework.hpp"
#include "../Share/Share.h"
#include "Title/Title.h"
#include "GameManager/Gamemanager.h"
#include "../Classbase.h"

class Scenemanager : public Classbase{
private:

	Title title_;

	Gamemanager gamemanager_;
	
	Scenename scenechange;

	
public:
	Scenemanager();

	void Setup();
	void Update();
	void Draw();
	void Shift();

};