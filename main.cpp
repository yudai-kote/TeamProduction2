
#include "Scene/Scenemanager.h"


int main() {
	env;

	Scenemanager Scenemanager_;

	Scenemanager_.Setup();

	while (env.isOpen()) {
		
		Scenemanager_.Shift();
		Scenemanager_.Update();
		env.begin();

		Scenemanager_.Draw();


		env.end();
  }
}
