#include "yarenderer/Layer.hh"

namespace yarenderer
{

Layer::Layer(Renderer* renderer, Shader* shader, glm::mat4 projection)
  : m_renderer(renderer)
  , m_shader(shader)
  , m_pr_matrix(projection)
{
  m_shader->enable();
  m_shader->setUniformMat4("pr_matrix", m_pr_matrix);
  m_shader->disable();
}

Layer::~Layer()
{
  delete m_shader;
  delete m_renderer;

  for (Renderable* renderable : m_renderables)
    delete renderable;
}

void
Layer::render()
{
  // FIXME do we really need to keep submiting stuff all the time?
  m_shader->enable();
  m_renderer->begin();
  for (const Renderable* renderable : m_renderables)
    renderable->submit(m_renderer);
  m_renderer->end();
  m_renderer->flush();
}

} // ns yarenderer
