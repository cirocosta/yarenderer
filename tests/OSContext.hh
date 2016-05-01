#ifndef YARENDERER__UTILS__OSCONTEXT_HH
#define YARENDERER__UTILS__OSCONTEXT_HH

#ifndef GLAPI
#define GLAPI extern
#endif

#ifndef GLAPIENTRY
#define GLAPIENTRY extern
#endif

#include "GL/osmesa.h"
#include "utils/debug.hh"

#include <iostream>
#include <vector>

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
