#include "texture.h"

#include "graphics.h"
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>


Texture::Texture(const std::string& file_path, SDL_Renderer* renderer) : renderer_(renderer) {

  texture_ = IMG_LoadTexture(renderer, file_path.c_str());

  if (texture_ == NULL) {
    SDL_ShowSimpleMessageBox(0, "Image loading error.", SDL_GetError(), 0);
  }
}

Texture::~Texture() {
  SDL_DestroyTexture(texture_);
}

void Texture::render(SDL_Rect* src, SDL_Rect* dst) {
  SDL_RenderCopy(renderer_, texture_, src, dst);
}