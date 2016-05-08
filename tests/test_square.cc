#include "yarenderer/Rect.hh"
#include "yarenderer/TileLayer.hh"
#include "yarenderer/Window.hh"
#include "buffers/FrameBuffer.hh"
#include "buffers/RenderBuffer.hh"
#include "utils/debug.hh"
#include "utils/IO.hh"

#include <unistd.h>
#include <iostream>

using namespace yarenderer;

const static GLsizei HEIGHT = 300;
const static GLsizei WIDTH = 300;

int
main()
{
  Window window("yarenderer", WIDTH, HEIGHT);
  TileLayer layer;

  BYTE* pixels = new BYTE[WIDTH*HEIGHT*3];

  glClearColor(1.0, 1.0, 0.0, 1.0);
  layer.add(new Rect(0.0, 0.0, 5.0, 5.0));

  window.clear();
  layer.render();
  window.update();

  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  glReadBuffer(GL_FRONT);
  glReadPixels(0, 0, WIDTH, HEIGHT, GL_RGB, GL_UNSIGNED_BYTE, pixels);
  utils::IO::save_pixels_to_image(pixels, WIDTH, HEIGHT, "./tests/test_square.bmp");


  delete[] pixels;

  return EXIT_SUCCESS;
}
