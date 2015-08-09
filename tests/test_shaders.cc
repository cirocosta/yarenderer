#include "yarenderer/gl_debug.hh"
#include "GL/glew.h"

#ifndef GLAPIENTRY
#define GLAPIENTRY
#endif

#ifndef GLAPI
#define GLAPI
#endif

#include "GL/osmesa.h"

#include <stdio.h>
#include <stdlib.h>

#define WIDTH 400
#define HEIGHT 400

void render() {}

int main(int argc, char *argv[])
{
  GLushort *buffer;

  OSMesaContext ctx = OSMesaCreateContextExt(GL_RGBA, 16, 0, 0, NULL);

  ASSERT(ctx, "OSMesaCreateContext failed!\n");

  /* Allocate the image buffer */
  buffer = (GLushort *)malloc(WIDTH * HEIGHT * 4 * sizeof(GLushort));

  ASSERT(buffer, "Failed to allocate image buffer");

  /* Bind the buffer to the context and make it current */
  ASSERT(OSMesaMakeCurrent(ctx, buffer, GL_UNSIGNED_SHORT, WIDTH, HEIGHT),
         "OSMesaMakeCurrent failed!");

  render();

  /* free the image buffer */
  free(buffer);

  /* destroy the context */
  OSMesaDestroyContext(ctx);

  return EXIT_SUCCESS;
}
