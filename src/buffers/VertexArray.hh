#ifndef YARENDERER__VERTEXARRAY_HH
#define YARENDERER__VERTEXARRAY_HH

#include "Buffer.hh"
#include "VertexBuffer.hh"

#include <vector>

namespace yarenderer
{
class VertexArray : public Buffer
{
private:
  GLuint m_array_id;
  std::vector<VertexBuffer*> m_buffers;

public:
  VertexArray();
  ~VertexArray();

  void addBuffer(VertexBuffer* buffer, GLuint index);
  inline void bind() const
  {
    glBindVertexArray(m_array_id);
  }
  inline void unbind() const
  {
    glBindVertexArray(0);
  }
  inline GLuint getBufferId()
  {
    return this->m_array_id;
  }
};

} // ns yarenderer

#endif
