#ifndef YARENDERER__FRAMEBUFFEROBJECT_HH
#define YARENDERER__FRAMEBUFFEROBJECT_HH

#include "Buffer.hh"
#include "RenderBuffer.hh"

namespace yarenderer
{

static const GLuint RENDERER_WINDOW_FB = 0;

class FrameBufferObject : public Buffer
{
private:
  GLuint m_buffer_id;

public:
  inline FrameBufferObject() { glGenFramebuffers(1, &m_buffer_id); }

  inline ~FrameBufferObject() { glDeleteFramebuffers(1, &m_buffer_id); }

  inline void attachRBO(RenderBuffer* rbo)
  {
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,
                              GL_RENDERBUFFER, rbo->getBufferId());
  }

  inline void dettachRBO()
  {
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,
                              GL_RENDERBUFFER, 0);
  }

  inline void bind() const { glBindFramebuffer(GL_FRAMEBUFFER, m_buffer_id); }

  inline void unbind() const
  {
    glBindFramebuffer(GL_FRAMEBUFFER, RENDERER_WINDOW_FB);
  }

  inline bool canRender() {
    return glCheckFramebufferStatus(GL_FRAMEBUFFER) == GL_FRAMEBUFFER_COMPLETE;
  }

  inline GLuint getBufferId() { return this->m_buffer_id; }

  static bool isSupported () {
    return false;
  }
};

}; // ns yarendrer

#endif
