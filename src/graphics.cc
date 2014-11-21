#include "graphics.h"
#include "texture.h"

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

namespace {
  const int kRendererLogicalWidth = 640;
  const int kRendererLogicalHeight = 480;
}

Graphics::Graphics() {
  window_ = SDL_CreateWindow("Pac-Man", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
  if (window_ == NULL) {
    SDL_ShowSimpleMessageBox(0, "Window init error", SDL_GetError(), window_);
  }

  renderer_ = SDL_CreateRenderer(window_, -1, 0);
  if (renderer_ == NULL) {
    SDL_ShowSimpleMessageBox(0, "Renderer init error", SDL_GetError(), window_); 
  }

  SDL_RenderSetLogicalSize(renderer_, kRendererLogicalWidth, kRendererLogicalHeight);
  SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
}

Graphics::~Graphics() {
  SDL_DestroyRenderer(renderer_);
  SDL_DestroyWindow(window_);
}

void Graphics::render() {

  Texture* texture = new Texture("content/allsprites.bmp", renderer_);

  if (texture == NULL) {
    printf("Could not load texture.\n");
  }

  SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 255);
  SDL_RenderClear(renderer_);

  SDL_Rect src;
  src.x = 4;
  src.y = 268;
  src.h = 22;
  src.w = 22;

  SDL_Rect dst;
  dst.x = 320;
  dst.y = 240;
  dst.h = 22;
  dst.w = 22;

  texture->render(&src, &dst);
  
  SDL_RenderPresent(renderer_);

  delete texture;
}
