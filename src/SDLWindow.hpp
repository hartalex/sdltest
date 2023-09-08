#pragma once
#include <SDL2/SDL.h>

#include "Result.hpp"

namespace sdltest {

class SDLWindow final {
 public:
  SDLWindow(char const* const title, int height, int width);
  ~SDLWindow();
  Result<bool> Initialize();
  void Paint();

 private:
  bool isInitialized;
  SDL_Window* window;
  SDL_Surface* screenSurface;
  int height;
  int width;
  char const* title;
};

}  // namespace sdltest
