#include "SDLWindow.hpp"

#include <SDL2/SDL.h>

#include <string>

using namespace sdltest;

SDLWindow::SDLWindow(const string title, int height, int width) {
  this->title = title;
  this->height = height;
  this->width = width;
  this->isInitialized = false;
}

SDLWindow::~SDLWindow() {
  if (this->isInitialized) {
    SDL_DestroyWindow(this->window);
  }
}

Result<bool> SDLWindow::Initialize() {
  this->window = SDL_CreateWindow(this->title.c_str(), SDL_WINDOWPOS_UNDEFINED,
                                  SDL_WINDOWPOS_UNDEFINED, this->width,
                                  this->height, SDL_WINDOW_SHOWN);
  if (this->window == NULL) {
    return Result<bool>(SDL_GetError());
  }
  this->screenSurface = SDL_GetWindowSurface(this->window);
  this->isInitialized = true;
  return Result<bool>(true);
}

void SDLWindow::Paint() {
  if (this->isInitialized) {
    SDL_FillRect(this->screenSurface, NULL,
                 SDL_MapRGB(this->screenSurface->format, 0xFF, 0xFF, 0xFF));

    SDL_UpdateWindowSurface(this->window);
  }
}

