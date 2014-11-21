#ifndef SPRITE_H_
#define SPRITE_H_

#include <string>
#include <SDL2/SDL.h>

class Texture {
public:
  Texture(const std::string& file_path, SDL_Renderer* renderer);
  ~Texture();

  void render(SDL_Rect* src, SDL_Rect* dst);

private:
  SDL_Renderer* renderer_;
  SDL_Texture* texture_;
};

#endif // SPRITE_H_