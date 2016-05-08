#ifndef YARENDERER__LAYER_HH
#define YARENDERER__LAYER_HH

#include "rendering/Renderer.hh"
#include "shaders/Shader.hh"
#include "yarenderer/Renderable2D.hh"

#include <vector>

namespace yarenderer
{

class Layer
{
  Renderer* m_renderer;
  std::vector<Renderable2D*> m_renderables;
  Shader* m_shader;
  glm::mat4 m_pr_matrix;

public:
  Layer(Renderer* renderer, Shader* shader, glm::mat4 projection);
  ~Layer();

  inline void add(Renderable2D* renderable)
  {
    m_renderables.push_back(renderable);
  }

  void render();
};

} // ns yarenderer

#endif
