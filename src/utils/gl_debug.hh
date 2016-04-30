
#ifndef YARENDERER__GL_DEBUG_HH
#define YARENDERER__GL_DEBUG_HH

#include "GL/glew.h"
#include "debug.hh"

namespace yarenderer
{
namespace utils
{

static void
CheckOpenGLError(const char* stmt, const char* fname, int line)
{
  GLenum err = glGetError();
  if (err != GL_NO_ERROR) {
    throw std::runtime_error(yarenderer::utils::str_fmt(
      "OpenGL error %08x, at %s:%i - for %s\n", err, fname, line, stmt));
  }
}
} // ns yarenderer
} // ns utils

#ifndef NDEBUG
#define GL_CHECK(stmt) stmt
#else
#define GL_CHECK(stmt)                                                         \
  do {                                                                         \
    stmt;                                                                      \
    yarenderer::utils::CheckOpenGLError(#stmt, __FILE__, __LINE__);            \
  } while (0)
#endif // ! NDEBUG

#endif // ! YARENDERER__GL_DEBUG_HH
