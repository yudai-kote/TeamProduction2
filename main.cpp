
#include "Scene/Scenemanager.h"


int main() {
	env;

	Scenemanager Scenemanager_;

	Scenemanager_.Setup();

	while (env.isOpen()) {

		Gamecount::GameCount(0); // ここで増やす処理を書く

		Scenemanager_.Shift();
		Scenemanager_.Update();
		env.begin();

		Scenemanager_.Draw();





		//std::cout << Gamecount::GameCount() << std::endl;
		env.end();
	}
}
