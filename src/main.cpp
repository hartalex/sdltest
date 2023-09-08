#include <SDL2/SDL.h>
#include <stdio.h>

#include <cstdlib>

#include "Result.hpp"
#include "SDLApplication.hpp"
#include "SDLWindow.hpp"
#include "config.hpp"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

using namespace sdltest;

int main(int argc, char* argv[]) {
  // Ignore lint warnings on unused parameters
  (void)argc;
  (void)argv;
  SDLApplication app;

  Result<bool> result = app.Initialize();
  if (!result.IsOk()) {
    printf("SDL could not be initialized. Error: %s\n", result.GetMessage());
    return EXIT_FAILURE;
  }

  SDLWindow window("SDL Test", SCREEN_HEIGHT, SCREEN_WIDTH);
  Result<bool> windowResult = window.Initialize();
  if (!windowResult.IsOk()) {
    printf("Window could not be created: %s\n", windowResult.GetMessage());
    return EXIT_FAILURE;
  }

  window.Paint();

  app.StartEventLoop();

  return EXIT_SUCCESS;
}

