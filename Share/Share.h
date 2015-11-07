#pragma once
#include "../lib/framework.hpp"
#include <iostream>
#include <string>
#include <vector>

#define env App::Get()


enum WindowSize{
	WIDTH = 1920,
	HEIGHT = 1080,
};

class App{
public:
	static AppEnv& Get(){
		static AppEnv singleton_env(WIDTH, HEIGHT, false, true);
		return singleton_env;
	}
};


enum class Scenename{
	TITLE,
	GAMEMANAGER,
	UNITSELECT,
	GAMEMAIN,
	RESULT,
};

enum class Ismove{
	STOP,
	MOVE,
};

