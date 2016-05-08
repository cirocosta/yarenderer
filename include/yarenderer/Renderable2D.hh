#ifndef YARENDERER__RENDERABLE2D_HH
#define YARENDERER__RENDERABLE2D_HH

#include "glm/gtc/type_ptr.hpp"
#include "rendering/Renderer.hh"
#include <vector>

namespace yarenderer
{

class Renderable2D
{
protected:
  // a group (inherits from renderable) won't set color and other stuff
  Renderable2D()
  {
    _set_default_uvs();
  }
  const glm::vec3 m_position;
  const glm::vec2 m_size;
  const glm::vec4 m_color;
  std::vector<glm::vec2> m_uvs;

public:
  Renderable2D(glm::vec3 position, glm::vec2 size, glm::vec4 color)
    : m_position(position)
    , m_size(size)
    , m_color(color)
  {
    _set_default_uvs();
  }

  virtual ~Renderable2D()
  {
  }

  inline const glm::vec3& getPosition() const
  {
    return m_position;
  }
  inline const glm::vec2& getSize() const
  {
    return m_size;
  }
  inline const glm::vec4& getColor() const
  {
    return m_color;
  }
  inline const std::vector<glm::vec2>& getUVs() const
  {
    return m_uvs;
  }

  virtual void submit(Renderer* renderer) const
  {
    renderer->submit(this);
  }

private:
  // FIXME
  void _set_default_uvs()
  {
    m_uvs.push_back(glm::vec2(0, 0));
    m_uvs.push_back(glm::vec2(0, 1));
    m_uvs.push_back(glm::vec2(1, 1));
    m_uvs.push_back(glm::vec2(1, 0));
  }
};

}; // ns yarenderer

#endif
