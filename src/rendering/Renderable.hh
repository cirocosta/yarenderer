#ifndef YARENDERER__RENDERABLE_HH
#define YARENDERER__RENDERABLE_HH

#include "glm/glm.hpp"
#include "Renderer.hh"
#include <vector>

namespace yarenderer
{

struct VertexData {
  glm::vec3 vertex;
  unsigned color;
};

class Renderable
{
protected:
  Renderable() { set_default_uvs(); }

public:
  const glm::vec3 position;
  const glm::vec2 size;
  const glm::vec4 color;
  std::vector<glm::vec2> m_uvs;

public:
  Renderable(glm::vec3 p, glm::vec2 s, glm::vec4 c)
      : position(p), size(s), color(c)
  {
    set_default_uvs();
  }

  virtual ~Renderable();

  virtual void submit(Renderer* renderer) const { renderer->submit(this); }

private:
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
