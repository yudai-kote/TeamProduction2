#pragma once
#include "../lib/framework.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <list>

#define env App::Get()
#define pose Gamecount::GameCount()
#define CHIPSIZE_X (128)
#define CHIPSIZE_Y (64)

enum Maptype
{
	LOAD,
	NONE
};

enum Windowsize{
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


enum class Scenename
{
	TITLE,			//タイトル
	GAMEMANAGER,	//ゲームマネージャー
	UNITSELECT,		//ユニットセレクト
	GAMEMAIN,		//ゲームメイン
	RESULT,			//リザルト
};

enum class Ismove
{
	STOP,	//止まっている
	MOVE,	//動いている
};

enum class Direction
{
	NORTH,		//北
	SOUTH,		//南
	EAST,		//東
	WEST,		//西
};


enum class Job
{
	WARRIOR,	//戦士
	LANCER,		//ランサー　

	JOB_MAX,
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

struct Unitlist
{
	int num;
	Vec2i pos;
};

struct Status{
	int hp;
	float power;
	float magic_power;
	float defense;
	float magic_defense;

	int num;

	Status(int hp,
		   float power,
		   float magic_power,
		   float defense,
		   float magic_defense):
		   hp(hp),
		   power(power),
		   magic_power(magic_power),
		   defense(defense),
		   magic_defense(magic_defense)
	{}
};


//四角と四角の当たり判定
static bool boxCollision(Vec2f box_pos, Vec2f box_size, Vec2f box1_pos, Vec2f box1_size) {
	return (
		box_pos.x() < box1_pos.x() + box1_size.x() &&
		box_pos.x() + box_size.x() > box1_pos.x() &&
		box_pos.y() < box1_pos.y() + box1_size.y() &&
		box_pos.y() + box_size.y() > box1_pos.y());
}
