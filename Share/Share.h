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
		static AppEnv singleton_env(WIDTH, HEIGHT);
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
	NONE		//静止
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

	Unitlist(int num,
			 Vec2i pos) :
			 num(num),
			 pos(pos)
	{}
};

struct Status{
	int hp;
	int power;
	int magic_power;
	int defense;
	int magic_defense;


	Status(int hp = 0,
		   int power = 0,
		   int magic_power = 0,
		   int defense = 0,
		   int magic_defense = 0) :
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

// セレクト画面の三角形描画関数
static void SelectTriangle(Vec2f pos)
{
	drawTriangle(pos.x() - 25, pos.y() + 30,
				 pos.x(), pos.y(),
				 pos.x() + 25, pos.y() + 30,
				 10,
				 Color::white);
}

//切り取り位置だけずらすアニメーション関数
//Vec2f size	切り取り幅
//int count     使う枚数
//int frame     何フレームでアニメーションするか
//int num		何番目からアニメーションするか
//Texture tex	テクスチャ
static Vec2f offsetAnimation(Vec2f size,int count, int change_frame, int num,Texture tex){
	int time;
	int time2;
	Vec2f offset_pos;
	
	time = (time2++ / change_frame) % count + num;

	offset_pos.x() = (time % 4) * size.x();
	offset_pos.y() = (time / 4) * size.y();

	if (time2 > count * change_frame)
	{
		time2 = 0;
	}

	return offset_pos;
}

// 描画もしちゃうアニメーション関数
// Vec2f pos, Vec2f size				ポス, サイズ
// Vec2f offset_pos,Vec2f offset_size	切り取り変数,切り取り幅
// Texture tex							画像
// int count							使う枚数
// int frame							何フレームでアニメーションするか
// int num								何番目からアニメーションするか
// int increment_time					インクリメントする変数
static void drawAnimation(Vec2f pos, Vec2f size,Vec2f& offset_pos, Vec2f offset_size, Texture tx,
							   int count, int frame, int num,int& increment_time){
	int animation_time;
	animation_time = (increment_time++ / frame) % count + num;

	offset_pos.x() = (animation_time % 4) * offset_size.x();
	offset_pos.y() = (animation_time / 4) * offset_size.y();

	drawTextureBox(pos.x(), pos.y(), size.x(), size.y(),
				   offset_pos.x(), offset_pos.y(), offset_size.x(), offset_size.y(),
				   tx, Color::white);

}