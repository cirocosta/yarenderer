#ifndef YARENDERER__UTILS__OSCONTEXT_HH
#define YARENDERER__UTILS__OSCONTEXT_HH

#include <vector>
#include "GL/osmesa.h"
#include "yarenderer/debug.hh"


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
