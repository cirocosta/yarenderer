#ifndef YARENDERER__BATCHRENDERER_HH
#define YARENDERER__BATCHRENDERER_HH

#include "Renderer.hh"
#include "VertexData.hh"
#include "buffers/IndexBuffer.hh"
#include "glm/gtc/type_ptr.hpp"
#include "yarenderer/Renderable2D.hh"

namespace yarenderer
{

static const GLuint RENDERER_MAX_SPRITES = 1000;
static const GLuint RENDERER_VERTEX_SIZE = sizeof(VertexData);
static const GLuint RENDERER_SPRITE_SIZE = RENDERER_VERTEX_SIZE * 4;
static const GLuint RENDERER_BUFFER_SIZE =
  RENDERER_SPRITE_SIZE * RENDERER_MAX_SPRITES;
static const GLuint RENDERER_INDICES_SIZE = RENDERER_MAX_SPRITES * 6;

static const GLubyte SHADER_VERTEX_INDEX = 0;
static const GLubyte SHADER_UV_INDEX = 1;
static const GLubyte SHADER_COLOR_INDEX = 2;

class BatchRenderer : public Renderer
{
private:
  GLuint m_vao;
  GLuint m_vbo;
  IndexBuffer* m_ibo; // no default constructor
  VertexData* m_buffer_map;

  GLsizei m_index_count;

public:
  BatchRenderer();
  virtual ~BatchRenderer();

  void begin() override;
  void submit(const Renderable2D* renderable) override;
  void end() override;
  void flush() override;

private:
  void _init();
};

} // ns yarenderer

#endif
