#ifndef YARENDERER__GL_HH
#define YARENDERER__GL_HH

#define GLFW_INCLUDE_GLCOREARB

#ifdef __APPLE__
#include "OpenGL/gl3.h"
#else
#include "GL/glew.h"
#endif

#include "utils/debug.hh"

namespace yarenderer {

  namespace gl {


static void
CheckOpenGLError(const char* stmt, const char* fname, int line)
{
  GLenum err = glGetError();
  if (err != GL_NO_ERROR) {
    throw std::runtime_error(yarenderer::utils::str_fmt(
      "OpenGL error %08x, at %s:%i - for %s\n", err, fname, line, stmt));
  }
}

}
}

#ifndef NDEBUG
#define GL_CHECK(stmt) stmt
#else
#define GL_CHECK(stmt)                                                         \
  do {                                                                         \
    stmt;                                                                      \
    yarenderer::gl::CheckOpenGLError(#stmt, __FILE__, __LINE__);            \
  } while (0)
#endif // ! NDEBUG

#endif

