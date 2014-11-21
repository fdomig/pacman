#ifndef GRAPHICS_H_
#define GRAPHICS_H_

struct SDL_Window;
struct SDL_Renderer;
struct SDL_Texture;
struct SDL_Rect;

class Graphics {
public:
  Graphics();
  ~Graphics();

  void render();

private:
  SDL_Window* window_;
  SDL_Renderer* renderer_;
};

#endif // GRAPHICS_H_