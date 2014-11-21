#include "game.h"
#include "graphics.h"
#include "texture.h"

#include <SDL2/SDL.h>

namespace {
	const int kFps = 60;
}

Game::Game() {
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_ShowCursor(SDL_DISABLE);
  eventLoop();
}

Game::~Game() {
	SDL_Quit();
}

void Game::eventLoop() {
	Graphics graphics;
	SDL_Event event;

	bool running = true;
	while (running) {
		const int start_time_ms = SDL_GetTicks();
		
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
				case SDL_QUIT:
					running = false;
					break;
				default:
					break;
			}
		}

		update();
		draw(graphics);

		const int ms_per_frame = 1000 / kFps;
		const int elapsed_time_ms = SDL_GetTicks() - start_time_ms;

		/* delay if we are faster than FPS */		
		if (elapsed_time_ms < ms_per_frame) {
			SDL_Delay(ms_per_frame - elapsed_time_ms);
		}

	}
}

void Game::update() {
}

void Game::draw(Graphics& graphics) {
	graphics.render();
}
