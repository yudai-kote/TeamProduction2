#pragma once
#include "../lib/framework.hpp"
#include <iostream>
#include <string>
#include <vector>

#define env App::Get()
#define pose Gamecount::GameCount()


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
	TITLE,			//タイトル
	GAMEMANAGER,	//ゲームマネージャー
	UNITSELECT,		//ユニットセレクト
	GAMEMAIN,		//ゲームメイン
	RESULT,			//リザルト
};

enum class Ismove{
	STOP,	//止まっている
	MOVE,	//動いている
};

enum class Direction{
	UP,			//前
	DOWN,		//後ろ
	RIGHT,		//右
	LEFT,		//左
};

class Gamecount{
public:

	//エスケープ押したらカウントを止める関数（全体の処理を止めるのに使う）
	static int GameCount(bool is_count = true){
		static int count = 0;
		static bool is_stop = false;
		if (is_count == true)
		{
			return count;
		}
		else
		{
			if (is_stop == false)
			{
				count++;
			}
			if (count == 0)
			{
				if (env.isPushKey(GLFW_KEY_ESCAPE))
				{
					is_stop = false;
				}
			}
			if (count > 0)
			{
				if (env.isPushKey(GLFW_KEY_ESCAPE))
				{
					is_stop = true;
					count = 0;
				}
			}

			
			return 0;
		}
	}
};

