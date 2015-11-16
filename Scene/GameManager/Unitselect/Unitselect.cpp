#include "Unitselect.h"

Unitselect::Unitselect(std::list<Unitplayer*>& p_list) :
p_list_(p_list)
{
	select_job = 0;
	font.size(font_size);


}


void Unitselect::Setup(){




}

void Unitselect::Update(){
	SelectJob();
	ShiftJob();


}

void Unitselect::Draw(){

	for (auto itr = p_list_.begin(); itr != p_list_.end(); ++itr)
	{
		(*itr)->Draw();
	}


	JobDraw();
	StatusDraw();

}

Scenename Unitselect::Shift(){
	if (env.isPushKey('A')){
		return Scenename::GAMEMAIN;
	}
	return Scenename::UNITSELECT;
	env.flushInput();
}


void Unitselect::SelectJob(){

	if (count <= 5)
	switch (select_job)
	{
	case static_cast<int> (Job::WARRIOR) :
		if (env.isPushKey(GLFW_KEY_ENTER))
		{
			p_list_.push_back(new Warrior(count));
			count++;
			for (auto itr = p_list_.begin(); itr != --p_list_.end(); ++itr)
			{
				(*itr)->SetSelectPos(Vec2f(200, 0));
				num = (*itr)->GetNum();
			}
		}
										 break;
	case static_cast<int> (Job::LANCER) :
		if (env.isPushKey(GLFW_KEY_ENTER))
		{
			p_list_.push_back(new Lancer(count));
			count++;
			for (auto itr = p_list_.begin(); itr != --p_list_.end(); ++itr)
			{
				(*itr)->SetSelectPos(Vec2f(200, 0));
				num = (*itr)->GetNum();

			}
		}
										break;
	}
}


void Unitselect::ShiftJob(){
	if (env.isPushKey(GLFW_KEY_LEFT))
	{
		if (select_job < static_cast<int>(Job::JOB_MAX) - 1)
		{
			select_job++;
		}
	}
	if (env.isPushKey(GLFW_KEY_RIGHT))
	{
		if (select_job > 0)
		{
			select_job--;
		}
	}
}


void Unitselect::JobDraw(){

	/*for (int i = 0; i < static_cast<int>(Job::JOB_MAX); i++){
		selectjob_color[i] = Color::white;
	}*/
	Vec2f warrior_draw_pos = Vec2f((WIDTH / 2 - 250) - 300 * static_cast<int>(Job::WARRIOR),
								  HEIGHT / 4);
	Vec2f lancer_draw_pos = Vec2f((WIDTH / 2 - 250) - 300 * static_cast<int>(Job::LANCER),
						  HEIGHT / 4);

	selectjob_color[static_cast<int>(Job::WARRIOR)] = warrior.GetColor();
	selectjob_color[static_cast<int>(Job::LANCER)] = lancer.GetColor();

	if (select_job == static_cast<int>(Job::WARRIOR)){
		drawTriangle(warrior_draw_pos.x(), warrior_draw_pos.y() + 250,
					 warrior_draw_pos.x() + 50, warrior_draw_pos.y() + 250,
					 warrior_draw_pos.x() + 25, warrior_draw_pos.y() + 220,
					 10,
					 Color::white);
	}
	if (select_job == static_cast<int>(Job::LANCER)){
		drawTriangle(lancer_draw_pos.x(), lancer_draw_pos.y() + 250,
					 lancer_draw_pos.x() + 50, lancer_draw_pos.y() + 250,
					 lancer_draw_pos.x() + 25, lancer_draw_pos.y() + 220,
					 10,
					 Color::white);
	}

	drawFillBox((WIDTH / 2 - 250) - 300 * static_cast<int>(Job::WARRIOR), HEIGHT / 4, 100, 200,
				selectjob_color[static_cast<int>(Job::WARRIOR)]);
	font.draw("ウォーリアー", Vec2f(warrior_draw_pos.x() - 50, warrior_draw_pos.y() - 100),
			  Color::white);

	drawFillBox((WIDTH / 2 - 250) - 300 * static_cast<int>(Job::LANCER), HEIGHT / 4, 100, 200,
				selectjob_color[static_cast<int>(Job::LANCER)]);
	font.draw("ランサー", Vec2f(lancer_draw_pos.x() - 50, lancer_draw_pos.y() - 100),
			  Color::white);

}

void Unitselect::StatusDraw(){
	Status status;

	if (select_job == static_cast<int>(Job::WARRIOR)){
		status.hp = warrior.GetWarriorStatus().hp;
		status.power = warrior.GetWarriorStatus().power;
		status.magic_power = warrior.GetWarriorStatus().magic_power;
		status.defense = warrior.GetWarriorStatus().defense;
		status.magic_defense = warrior.GetWarriorStatus().magic_defense;
	}
	if (select_job == static_cast<int>(Job::LANCER)){
		
		status.hp = lancer.GetLancerStatus().hp;
		status.power = lancer.GetLancerStatus().power;
		status.magic_power = lancer.GetLancerStatus().magic_power;
		status.defense = lancer.GetLancerStatus().defense;
		status.magic_defense = lancer.GetLancerStatus().magic_defense;
	}

		font.draw("体力　　　　" + std::to_string(status.hp),
				  Vec2f(-WIDTH/3, 200 -font_size),Color::white);
		
		font.draw("攻撃力　　　" + std::to_string(status.power), 
				  Vec2f(-WIDTH / 3, 200 - font_size * 2), Color::white);
		
		font.draw("魔法攻撃力　" + std::to_string(status.magic_power), 
				  Vec2f(-WIDTH / 3, 200 - font_size * 3), Color::white);
		
		font.draw("防御力　　　" + std::to_string(status.defense), 
				  Vec2f(-WIDTH / 3, 200 - font_size * 4), Color::white);
		
		font.draw("魔法防御力　" + std::to_string(status.magic_defense),
				  Vec2f(-WIDTH / 3, 200 - font_size * 5), Color::white);
}