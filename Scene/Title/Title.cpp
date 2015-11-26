#include "Title.h"

Title::Title(){

	title = Texture("res/Texture/title.png");
	press_enter = Texture("res/Texture/press_start.png");

}


void Title::Setup(){




}

void Title::Update(){



}

void Title::Draw(){

	drawFillBox(
		-Windowsize::WIDTH / 2,
		-Windowsize::HEIGHT / 2,
		Windowsize::WIDTH,
		Windowsize::HEIGHT,
		Color::white);

	drawTextureBox(
		-Windowsize::WIDTH / 4,
		200,
		Windowsize::WIDTH / 2,
		256,
		0,
		0,
		512,
		128,
		title);

	drawTextureBox(
		-288,
		-300,
		576,
		192,
		0,
		0,
		256,
		64,
		press_enter);
}


Scenename Title::Shift(){

	if (env.isPushKey(GLFW_KEY_ENTER)){
		return Scenename::GAMEMANAGER;

	}

	return Scenename::TITLE;
}