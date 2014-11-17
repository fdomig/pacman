#ifndef GRAPHICS_H_
#define GRAPHICS_H_

class SDL_Window;
class SDL_Renderer;
class SDL_Surface;
class SDL_Rect;

class Graphics {
public:
  Graphics();
  ~Graphics();

  void blitSurface(
    SDL_Surface* source,
    SDL_Rect* source_rect,
    SDL_Rect* destination_rect);

  void flip();

private:
  SDL_Window* window_;
  SDL_Renderer* renderer_;
};

#endif // GRAPHICS_H_