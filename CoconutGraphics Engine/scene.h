#pragma once
#include "shapes.h"
#include "camera.h"
#include "window.h"
#include <vector>

namespace CoconutGraphics {
	struct scene_data {
		// storing all the objects in our scene
		std::vector<mesh> objects;

		camera camera;
		vector3 light_dir;
		double CLOSE_UP;

		scene_data(std::vector<mesh> objs = {}) : objects(objs) {}

		int render(int width, int height) {
			return 0;
		}
	};

	// more of a game lol
	class scene {
		bool running = false;
		scene_data MyScene;
		void onFrame(double time, double dt);
		void handleEvents();

	public:
		void run(int fps, int width, int height, const char* title) {
			running = true;

			Window window = Window(100, 100, title);

			double delta_time = 1 / (double)fps;
			double time = 0;


			// game loop
			window.start();
			while (running) {

				SDL_Event event;
				SDL_PollEvent(&event);


				if (event.type == SDL_QUIT) {
					running = false;
				}
				handleEvents();

				onFrame(time, delta_time);

				SDL_Delay((int)(delta_time * 1000));
				time += delta_time;
			}
			window.end();
		}
	};
}