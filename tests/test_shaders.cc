#include "yarenderer/Rect.hh"
#include "yarenderer/TileLayer.hh"

#include "OpenGL/gl3.h"

#include <iostream>

using namespace yarenderer;

int
main(int argc, char* argv[])
{
  //  todo fix
  glClearColor(1.0, 1.0, 1.0, 1.0);

  TileLayer layer;
  layer.add(new Rect(0.0, 0.0, 5.0, 5.0));
  layer.render();

  return 0;
}
