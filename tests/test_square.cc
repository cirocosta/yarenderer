#include "yarenderer/Rect.hh"
#include "yarenderer/TileLayer.hh"
#include "yarenderer/Window.hh"
#include "buffers/FrameBuffer.hh"
#include "buffers/RenderBuffer.hh"

#include <unistd.h>
#include <iostream>

using namespace yarenderer;

const static GLsizei HEIGHT = 400;
const static GLsizei WIDTH = 400;

int
main()
{
  Window window("yarenderer", WIDTH, HEIGHT);
  glClearColor(1.0, 1.0, 1.0, 1.0);

  FrameBuffer fbo;
  RenderBuffer rbo(WIDTH, HEIGHT);

  TileLayer layer;
  layer.add(new Rect(0.0, 0.0, 5.0, 5.0));

  window.clear();

  fbo.attachRBO(&rbo);
  layer.render();
  fbo.dettachRBO();

  window.update();

  sleep(1);

  return EXIT_SUCCESS;
}
