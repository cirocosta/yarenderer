#ifndef YARENDERER__VERTEXARRAY_HH
#define YARENDERER__VERTEXARRAY_HH

#ifdef __APPLE__
#include "OpenGL/gl3.h"
#else
#include "GL/glew.h"
#endif
#include "VertexBuffer.hh"

#include <vector>

namespace yarenderer
{
class VertexArray
{
private:
  GLuint m_array_id;
  std::vector<VertexBuffer*> m_buffers;

public:
  VertexArray();
  ~VertexArray();

  void addBuffer(VertexBuffer* buffer, GLuint index);
  inline void bind() const { glBindVertexArray(m_array_id); }
  inline void unbind() const { glBindVertexArray(0); }
};

} // ns yarenderer

#endif
