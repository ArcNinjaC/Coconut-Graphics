#include <iostream>
#include "coconut_graphics.h"
#include "SDL.h"

using namespace CoconutGraphics;


class game : public scene {
	scene_data MyScene = scene_data();
	void onFrame() {
		std::cout << "frame";
	}
	void handleEvents() {}
};

int main() {
	std::cout << "Hello World!";
	game myGame = game();
	myGame.run(10,100,100,"shut");

	return 0;
}