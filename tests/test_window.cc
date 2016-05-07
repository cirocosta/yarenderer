#include "yarenderer/Rect.hh"
#include "yarenderer/TileLayer.hh"
#include "yarenderer/Window.hh"
#include <unistd.h>

#include <iostream>

using namespace yarenderer;

int
main()
{
  Window window("yarenderer", 400, 400);
  glClearColor(1.0, 1.0, 1.0, 1.0);

  window.update();

  sleep(1);

  return EXIT_SUCCESS;
}
