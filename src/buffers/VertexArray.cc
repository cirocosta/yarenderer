#include "VertexArray.hh"

namespace yarenderer
{

VertexArray::VertexArray() { glGenVertexArrays(1, &m_array_id); }

VertexArray::~VertexArray()
{
  for (const auto& buffer : m_buffers)
    delete buffer;

  glDeleteVertexArrays(1, &m_array_id);
}


void VertexArray::addBuffer(VertexBuffer* buffer, GLuint index)
{
  bind();
  buffer->bind();

  glEnableVertexAttribArray(index);
  glVertexAttribPointer(index, buffer->getComponentCount(), GL_FLOAT, GL_FALSE,
                        0, 0);

  buffer->unbind();
  unbind();
}

} // ns yarenderer
