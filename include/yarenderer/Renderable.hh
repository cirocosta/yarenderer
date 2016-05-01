#ifndef YARENDERER__RENDERABLE_HH
#define YARENDERER__RENDERABLE_HH

#include "glm/gtc/type_ptr.hpp"
#include "rendering/Renderer.hh"
#include <vector>

namespace yarenderer
{

struct VertexData {
  glm::vec3 vertex;
  glm::vec2 uv;
  unsigned color;
};

class Renderable
{
protected:
  // a group (inherits from renderable) won't set color and other stuff
  Renderable() { set_default_uvs(); }
  const glm::vec3 m_position;
  const glm::vec2 m_size;
  const glm::vec4 m_color;
  std::vector<glm::vec2> m_uvs;

public:
  Renderable(glm::vec3 p, glm::vec2 s, glm::vec4 c)
    : m_position(p)
    , m_size(s)
    , m_color(c)
  {
    set_default_uvs();
  }

  virtual ~Renderable() {}

  inline const glm::vec3& getPosition() const { return m_position; }
  inline const glm::vec2& getSize() const { return m_size; }
  inline const glm::vec4& getColor() const { return m_color; }
  inline const std::vector<glm::vec2>& getUVs() const { return m_uvs; }

  virtual void submit(Renderer* renderer) const { renderer->submit(this); }

private:
  // FIXME
  void set_default_uvs()
  {
    m_uvs.push_back(glm::vec2(0, 0));
    m_uvs.push_back(glm::vec2(0, 1));
    m_uvs.push_back(glm::vec2(1, 1));
    m_uvs.push_back(glm::vec2(1, 0));
  }
};

}; // ns yarenderer

#endif
