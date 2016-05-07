#ifndef YARENDERER__RENDERBUFFER_HH
#define YARENDERER__RENDERBUFFER_HH

#include "Buffer.hh"

namespace yarenderer
{

class RenderBuffer : public Buffer
{
private:
  GLuint m_buffer_id;

public:
  RenderBuffer(GLsizei width, GLsizei height)
  {
    glGenFramebuffers(1, &m_buffer_id);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_RGB, width, height);
  }

  ~RenderBuffer()
  {
    glDeleteFramebuffers(1, &m_buffer_id);
  }

  void bind() const override
  {
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
