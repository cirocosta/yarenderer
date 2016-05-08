

#include "StaticSprite.hh"

namespace yarenderer {
StaticSprite::StaticSprite(float x, float y, float width, float height,
    glm::vec4 color, Shader& shader) : Renderable2D(glm::vec3(x,y,0), glm::vec2(width, height),
      color), m_shader(shader)
{
  // TODO
}


StaticSprite::~StaticSprite()
{
}
}
