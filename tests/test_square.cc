#include "yarenderer/Rect.hh"
#include "yarenderer/TileLayer.hh"
#include "yarenderer/Window.hh"
#include "buffers/FrameBuffer.hh"
#include "buffers/RenderBuffer.hh"
#include "utils/debug.hh"

#include <unistd.h>
#include <iostream>

using namespace yarenderer;

const static GLsizei HEIGHT = 50;
const static GLsizei WIDTH = 50;


int
main()
{
  Window window("yarenderer", WIDTH, HEIGHT);
  unsigned char* buff = new unsigned char[WIDTH*HEIGHT*3];
  FrameBuffer fbo;
  RenderBuffer rbo(WIDTH, HEIGHT);
  TileLayer layer;

  fbo.attachRBO(&rbo);
  layer.add(new Rect(0.0, 0.0, 5.0, 5.0));


  glClearColor(1.0, 1.0, 1.0, 1.0);
  window.clear();
  ASSERT(fbo.canRender(), "Can't render");
  layer.render();
  glReadBuffer(GL_BACK);
  glReadPixels(0, 0, WIDTH, HEIGHT, GL_RGB, GL_UNSIGNED_BYTE, buff);
  fbo.dettachRBO();
  window.update();

  sleep(1);

  return EXIT_SUCCESS;
}
