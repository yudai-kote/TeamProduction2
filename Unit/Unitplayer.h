#pragma once
#include "../Share/Share.h"
#include "../Unit/Player/Player.h"

class Unitplayer : public Chara{
private:

	
	void Animation();

	Font font = Font("res/meiryo.ttc");


	//番号から座標を割り出す関数
	void SetDrawPos(Vec2i getpos);

public:


	Unitplayer();

	void Setup(Status status);
	void Update();
	void Draw();
	//セレクトに使う関数
	void SetSelectPos(Vec2f select_pos);
	void SetSelectNum(int selectnumber);
	//セレクトに使う関数
	Vec2f GetSelectPos();

	void Move(Direction ui_direction);
	//マップからcanmoveをもらうセッター
	void SetCanMove(bool can_move_);
	//マップからisattackをもらうセッター
	void SetIsAttack(bool is_attack_);
	//UIからdirectionをもらってその方向に動く関数
	void SetDirection(Direction ui_direction);
	//マップチップ番号をもらうセッター
	void SetUnitlistPos(Vec2i getpos);

	//マップのUnitllistに渡す関数 
	Unitlist GetUnitlist();
	//チップ番号を返す関数
	Vec2i GetPos();
	//UIにステータスを返す関数
	Status GetStatus();
	//ナンバーを返す関数
	int GetNum();
	//ジョブを返す関数（使ってない）
	Job GetJob();
	Direction GetDirection();

};

