#include "VertexBuffer.hh"

namespace yarenderer
{

VertexBuffer::VertexBuffer(GLfloat* data, GLsizei count, GLuint compCount)
    : m_component_count(compCount)
{
  glGenBuffers(1, &m_buffer_id);
  glBindBuffer(GL_ARRAY_BUFFER, m_buffer_id);
  glBufferData(GL_ARRAY_BUFFER, count * sizeof(GLfloat), data, GL_STATIC_DRAW);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
}

VertexBuffer::~VertexBuffer ()
{
  ::glDeleteBuffers(1, &m_buffer_id);
}

}; // ns yarenderer
