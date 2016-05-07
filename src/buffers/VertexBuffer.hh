#ifndef YARENDERER__VERTEXBUFFER_HH
#define YARENDERER__VERTEXBUFFER_HH

#include "Buffer.hh"

namespace yarenderer
{

class VertexBuffer : public Buffer
{
private:
  GLuint m_buffer_id;
  GLuint m_component_count;

public:
  VertexBuffer(GLfloat* data, GLsizei count, GLuint component_count);
  ~VertexBuffer();

  inline void bind() const
  {
    glBindBuffer(GL_ARRAY_BUFFER, m_buffer_id);
  }

  inline void unbind() const
  {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
  }

  inline GLuint getComponentCount() const
  {
    return m_component_count;
  }

  inline GLuint getBufferId()
  {
    return this->m_buffer_id;
  }
};

}; // ns yarenderer

#endif
