#include "yarenderer/Window.hh"
#include "yarenderer/TileLayer.hh"
#include "yarenderer/Rect.hh"
#include <unistd.h>

#include <iostream>

using namespace yarenderer;

int main()
{
  Window window("yarenderer", 400, 400);
  glClearColor(1.0, 1.0, 1.0, 1.0);

  TileLayer layer;

  layer.add(new Rect(0.0, 0.0, 5.0, 5.0));

  window.clear();
  layer.render();
  window.update();

  sleep(1);

  return EXIT_SUCCESS;
}
