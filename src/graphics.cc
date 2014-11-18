#include "graphics.h"

#include <SDL2/SDL.h>

Graphics::Graphics() {
  window_ = SDL_CreateWindow("Pac-Man",
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    0, 0,
    SDL_WINDOW_FULLSCREEN_DESKTOP
  );
  renderer_ = SDL_CreateRenderer(window_, -1, 0);
}

Graphics::~Graphics() {
  SDL_DestroyRenderer(renderer_);
  SDL_DestroyWindow(window_);
}

void Graphics::blitSurface(
  SDL_Surface* source,
  SDL_Rect* source_rect,
  SDL_Rect* destination_rect) {

  /* workaround from SDL1 to SDL2 */
  SDL_Surface* screen = SDL_GetWindowSurface(window_);

  SDL_BlitSurface(source, source_rect, screen, destination_rect);
}

void Graphics::flip() {
  SDL_RenderPresent(renderer_);
}