#ifndef YARENDERER__INDEXBUFFER_HH
#define YARENDERER__INDEXBUFFER_HH

#ifdef __APPLE__
#include "OpenGL/gl3.h"
#else
#include "GL/glew.h"
#endif

namespace yarenderer
{

/**
 * Holds reference to memory location of a
 * buffer on the GPU that's specialized for
 * indices
 */
class IndexBuffer
{
private:
  GLuint m_buffer_id;
  GLuint m_count;

public:
  IndexBuffer(GLushort* data, GLsizei count);
  IndexBuffer(GLuint* data, GLsizei count);
  ~IndexBuffer();

  inline void bind() const
  {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_buffer_id);
  }
  inline void unbind() const { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); }

  inline GLuint getCount() const { return m_count; }
};

} // ns yarenderer

#endif
