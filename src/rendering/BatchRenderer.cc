#include "BatchRenderer.hh"

namespace yarenderer
{
BatchRenderer::BatchRenderer()
{
  _init();
}

BatchRenderer::~BatchRenderer()
{
  delete m_ibo;
  glDeleteBuffers(1, &m_vbo);
  glDeleteBuffers(1, &m_vao);
}

void
BatchRenderer::_init()
{
  // generate buffers
  glGenVertexArrays(1, &m_vao);
  glGenBuffers(1, &m_vbo);

  // allocate internal memory and retrieve the mapping
  glBindVertexArray(m_vao);
  glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
  glBufferData(GL_ARRAY_BUFFER, RENDERER_BUFFER_SIZE, NULL, GL_DYNAMIC_DRAW);

  // prepare shader attributes
  glEnableVertexAttribArray(SHADER_VERTEX_INDEX);
  glEnableVertexAttribArray(SHADER_UV_INDEX);
  glEnableVertexAttribArray(SHADER_COLOR_INDEX);

  glVertexAttribPointer(SHADER_VERTEX_INDEX, 3, GL_FLOAT, GL_FALSE,
                        RENDERER_VERTEX_SIZE, (const GLvoid*)0);
  glVertexAttribPointer(SHADER_UV_INDEX, 2, GL_FLOAT, GL_FALSE,
                        RENDERER_VERTEX_SIZE,
                        (const GLvoid*)(offsetof(VertexData, uv)));
  glVertexAttribPointer(SHADER_COLOR_INDEX, 4, GL_UNSIGNED_BYTE, GL_TRUE,
                        RENDERER_VERTEX_SIZE,
                        (const GLvoid*)(offsetof(VertexData, color)));

  glBindBuffer(GL_ARRAY_BUFFER, 0);

  // prepare indexbuffer
  GLuint* indices = new GLuint[RENDERER_INDICES_SIZE];
  unsigned offset = 0;

  for (unsigned i = 0; i < RENDERER_INDICES_SIZE; i += 6) {
    indices[i] = offset;
    indices[i + 1] = offset + 1;
    indices[i + 2] = offset + 2;

    indices[i + 3] = offset + 2;
    indices[i + 4] = offset + 3;
    indices[i + 5] = offset + 0;

    offset += 4;
  }

  m_ibo = new IndexBuffer(indices, RENDERER_INDICES_SIZE);
  glBindVertexArray(0);

  delete[] indices;
}

void
BatchRenderer::begin()
{
  glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
  m_buffer_map = (VertexData*)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
}

void
BatchRenderer::submit(const Renderable2D* renderable)
{
  glm::vec3 position = renderable->getPosition();
  glm::vec2 size = renderable->getSize();
  glm::vec4 color = renderable->getColor();
  std::vector<glm::vec2> uv = renderable->getUVs();

  int r = color.x * 255.0f;
  int g = color.y * 255.0f;
  int b = color.z * 255.0f;
  int a = color.w * 255.0f;

  unsigned int c = a << 24 | b << 16 | g << 8 | r;

  // TODO improve this. Lot's of conversions
  //      going on

  // origin
  m_buffer_map->vertex = glm::vec3(glm::vec4(position, 1.0));
  m_buffer_map->uv = uv[0];
  m_buffer_map->color = c;
  m_buffer_map++;

  // upper left
  m_buffer_map->vertex =
    glm::vec3(glm::vec4(position.x, position.y + size.y, position.z, 1.0));
  m_buffer_map->uv = uv[1];
  m_buffer_map->color = c;
  m_buffer_map++;

  // upper right
  m_buffer_map->vertex = glm::vec3(

    glm::vec4(position.x + size.x, position.y + size.y, position.z, 1.0));
  m_buffer_map->uv = uv[2];
  m_buffer_map->color = c;
  m_buffer_map++;

  // bottom right
  m_buffer_map->vertex =
    glm::vec3(glm::vec4(position.x + size.x, position.y, position.z, 1.0));
  m_buffer_map->uv = uv[3];
  m_buffer_map->color = c;
  m_buffer_map++;

  // tell that we have one more renderable2d to
  // be rendered.
  m_index_count += 6;
}

void
BatchRenderer::end()
{
  glUnmapBuffer(GL_ARRAY_BUFFER);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void
BatchRenderer::flush()
{
  glBindVertexArray(m_vao);
  m_ibo->bind();
  glDrawElements(GL_TRIANGLES, m_index_count, GL_UNSIGNED_INT, 0);
  m_ibo->unbind();
  glBindVertexArray(0);
}

} // ns yarenderer
