#ifndef YARENDERER__FRAMEBUFFER_HH
#define YARENDERER__FRAMEBUFFER_HH

#include "Buffer.hh"
#include "RenderBuffer.hh"

namespace yarenderer
{

static const GLuint RENDERER_WINDOW_FB = 0;

class FrameBuffer : public Buffer
{
private:
  GLuint m_buffer_id;

public:
  FrameBuffer()
  {
    glGenFramebuffers(1, &m_buffer_id);
  }

  ~FrameBuffer()
  {
    glDeleteFramebuffers(1, &m_buffer_id);
  }

  void attachRBO(RenderBuffer* rbo)
  {
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,
                              GL_RENDERBUFFER, rbo->getBufferId());
  }

  void dettachRBO()
  {
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,
                              GL_RENDERBUFFER, 0);
  }

  void bind() const override
  {
    glBindFramebuffer(GL_FRAMEBUFFER, m_buffer_id);
  }

  void unbind() const override
  {
    glBindFramebuffer(GL_FRAMEBUFFER, RENDERER_WINDOW_FB);
  }

  GLuint getBufferId() const override
  {
    return this->m_buffer_id;
  }

  bool canRender()
  {
    return glCheckFramebufferStatus(GL_FRAMEBUFFER) == GL_FRAMEBUFFER_COMPLETE;
  }

  static bool isSupported()
  {
    return false;
  }
};

}; // ns yarendrer

#endif
