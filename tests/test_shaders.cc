#include "yarenderer/Rect.hh"
#include "yarenderer/TileLayer.hh"

#include "OpenGL/gl3.h"
#include "OSContext.hh"

#include <iostream>

using namespace yarenderer;
using yarenderer::utils::OSContext;

int
main(int argc, char* argv[])
{
  OSContext ctx(400, 400);
  ctx.make_current();

  glClearColor(1.0, 1.0, 1.0, 1.0);

  TileLayer layer;
  layer.add(new Rect(0.0, 0.0, 5.0, 5.0));
  layer.render();

  return 0;
}
