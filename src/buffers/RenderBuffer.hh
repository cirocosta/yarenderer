#ifndef YARENDERER__RENDERBUFFER_HH
#define YARENDERER__RENDERBUFFER_HH

#include "Buffer.hh"

namespace yarenderer
{

class RenderBuffer : public Buffer
{
private:
  GLuint m_buffer_id;
  GLsizei m_width;
  GLsizei m_height;

public:
  RenderBuffer(GLsizei width, GLsizei height) : m_width(width), m_height(height)
  {
    glGenFramebuffers(1, &m_buffer_id);
  }

  ~RenderBuffer()
  {
    glDeleteFramebuffers(1, &m_buffer_id);
  }

  void bind() const override
  {
    glRenderbufferStorage(GL_RENDERBUFFER, GL_BGR, m_width, m_height);
    glBindRenderbuffer(GL_RENDERBUFFER, m_buffer_id);
  }

  void unbind() const override
  {
    glBindRenderbuffer(GL_RENDERBUFFER, 0);
  }

  GLuint getBufferId() const override
  {
    return this->m_buffer_id;
  }
};

}; // ns yarendrer

#endif
