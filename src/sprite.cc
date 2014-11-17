#include "sprite.h"

#include "graphics.h"
#include <SDL2/SDL.h>


Sprite::Sprite(const std::string& file_path,
       int source_x, int source_y,
       int width, int height) {

  sprite_sheet_ = SDL_LoadBMP(file_path.c_str());
  source_rect_.x = source_x;
  source_rect_.y = source_y;
  source_rect_.w = width;
  source_rect_.h = height;
}

Sprite::~Sprite() {
  SDL_FreeSurface(sprite_sheet_);
}

void Sprite::draw(Graphics& graphics, int x, int y) {
  SDL_Rect destination_rect;
  destination_rect.x = x;
  destination_rect.y = y;
  graphics.blitSurface(sprite_sheet_, &source_rect_, &destination_rect);
}