#ifndef YARENDERER__UTILS__OSCONTEXT_HH
#define YARENDERER__UTILS__OSCONTEXT_HH

#include "GL/osmesa.h"

#include <vector>
#include <iostream>

#define ASSERT(condition, message)                                             \
  do {                                                                         \
    if (!(condition)) {                                                        \
      std::cerr << "Assertion `" #condition "` failed in " << __FILE__         \
                << " line " << __LINE__ << ": " << message << std::endl;       \
      std::exit(EXIT_FAILURE);                                                 \
    }                                                                          \
  } while (0)

namespace yarenderer
{
namespace utils
{

struct OSContext {
  OSMesaContext context;
  GLsizei width;
  GLsizei height;
  std::vector<GLubyte> buffer;

  OSContext(GLsizei width, GLsizei height);
  ~OSContext();
  void make_current();
};
}

} // ns yarenderer

#endif
