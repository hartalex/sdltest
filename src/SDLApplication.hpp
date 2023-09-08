#pragma once
#include "Result.hpp"

namespace sdltest {

class SDLApplication final {
 public:
  SDLApplication();
  ~SDLApplication();
  Result<bool> Initialize();
  void StartEventLoop();

 private:
  bool isInitialized;
};

}  // namespace sdltest

