#include "SDLApplication.hpp"

#include <SDL2/SDL.h>

#include "Result.hpp"

using namespace sdltest;

SDLApplication::SDLApplication() { this->isInitialized = false; }

Result<bool> SDLApplication::Initialize() {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    return Result<bool>(SDL_GetError());
  }
  this->isInitialized = true;
  return Result<bool>(true);
}

void SDLApplication::StartEventLoop() {
  SDL_Event e;
  bool quit = false;
  // loop until exit
  while (quit == false) {
    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT) {
        quit = true;
      }
    }
  }
}

SDLApplication::~SDLApplication() {
  if (this->isInitialized) {
    SDL_Quit();
  }
}

