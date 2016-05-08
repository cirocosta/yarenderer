#ifndef YARENDERER__STATICSPRITE_HH
#define YARENDERER__STATICSPRITE_HH

#include "buffers/IndexBuffer.hh"
#include "buffers/VertexArray.hh"
#include "shaders/Shader.hh"
#include "yarenderer/Renderable2D.hh"

namespace yarenderer
{

class StaticSprite : public Renderable2D
{
private:
  VertexArray* m_vertexArray;
  IndexBuffer* m_indexBuffer;
  Shader& m_shader;

public:
  StaticSprite(float x, float y, float width, float height, glm::vec4 color,
               Shader& shader);
  ~StaticSprite();
};
}

#endif
