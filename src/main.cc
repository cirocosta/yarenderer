#include "Window.hh"
#include <iostream>

using namespace yarenderer;

int main()
{
  Window window("yarenderer!", 900, 600);
  glClearColor(0.0, 0.0, 0.1, 1.0);

  while (!window.closed()) {
    window.clear();
    window.update();
  }

  return EXIT_SUCCESS;
}
