#ifndef YARENDERER__BUFFER_HH
#define YARENDERER__BUFFER_HH

#include "yarenderer/GL.hh"

namespace yarenderer
{

class Buffer
{
public:
  virtual ~Buffer() = default;
  virtual void bind() const = 0;
  virtual void unbind() const = 0;
  virtual GLuint getBufferId() const = 0;
};

}; // ns yarenderer

#endif
