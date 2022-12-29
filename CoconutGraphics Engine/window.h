#pragma once
#include <iostream>
#include <SDL.h>

namespace CoconutGraphics {

	class Window {
		const int width, height;
		const char* title_caption;

		bool RUNNING = false;

		SDL_Window* window = nullptr;
		SDL_Renderer* renderer = nullptr;

	public :
		Window(int w_width = 100, int w_height = 100, const char* caption = "SDL WINDOW") :
			width(w_width),
			height(w_height),
			title_caption(caption)
		{}

		bool get_current_state() {
			return RUNNING;
		}

		void start() {
			if (SDL_Init(SDL_INIT_VIDEO) < 0) {
				std::cout << "SDL could not be initialized: " << SDL_GetError() << '\n';
			}
			else {
				std::cout << "SDL HAS SUCCESSFULLY INITIALIZED" << '\n';
			}

			window = SDL_CreateWindow(title_caption, 0, 0, width, height, SDL_WINDOW_SHOWN);

			if (window) {
				std::cout << "Window successfully created" << '\n';
				SDL_SetWindowMinimumSize(window, 100, 100);
			}

			renderer = SDL_CreateRenderer(window, -1, 0);
			if (renderer) {
				std::cout << "Renderer successfully created" << '\n';
				RUNNING = true;
			}

		}
		void end() {

			RUNNING = false;

			SDL_DestroyWindow(window);
			SDL_DestroyRenderer(renderer);
			SDL_Quit();
		}
	};
}