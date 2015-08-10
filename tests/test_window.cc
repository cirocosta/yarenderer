#include "yarenderer/Window.hh"
#include "yarenderer/TileLayer.hh"
#include "yarenderer/Rect.hh"

#include <iostream>

using namespace yarenderer;

int main()
{
  Window window("yarenderer", 900, 600);
  glClearColor(0.0, 0.0, 0.1, 1.0);

  TileLayer layer;

  layer.add(new Rect(0.0, 0.0, 5.0, 5.0));

  while (!window.closed()) {
    window.clear();
    layer.render();
    window.update();
  }

  return EXIT_SUCCESS;
}
