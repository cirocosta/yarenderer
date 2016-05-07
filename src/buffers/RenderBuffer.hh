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
  inline RenderBuffer(GLsizei width, GLsizei height)
  {
    glGenFramebuffers(1, &m_buffer_id);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_RGB, width, height);
  }

  inline ~RenderBuffer()
  {
    glDeleteFramebuffers(1, &m_buffer_id);
  }

  inline void bind() const
  {
    glBindRenderbuffer(GL_RENDERBUFFER, m_buffer_id);
  }

  inline void unbind() const
  {
    glBindRenderbuffer(GL_RENDERBUFFER, 0);
  }

  inline GLuint getBufferId()
  {
    return this->m_buffer_id;
  }
};

}; // ns yarendrer

#endif
