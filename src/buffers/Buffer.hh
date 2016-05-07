#ifndef YARENDERER__BUFFER_HH
#define YARENDERER__BUFFER_HH

#ifdef __APPLE__
#include "OpenGL/gl3.h"
#else
#include "GL/glew.h"
#endif

namespace yarenderer
{

class Buffer
{
public:
  virtual ~Buffer() = default;
  virtual void bind() = 0;
  virtual void unbind() = 0;
  virtual GLuint getBufferId() = 0;
};

}; // ns yarenderer

#endif
