#ifndef YARENDERER__SIMPLE2DRENDERER_HH
#define YARENDERER__SIMPLE2DRENDERER_HH

#include "Renderer.hh"
#include <deque>

namespace yarenderer
{

class Simple2DRenderer : public Renderer
{
private:
  std::deque<const Renderable2D*> m_renderables;

public:
  void submit(const Renderable2D* renderable) override;
  void flush() override;
};
}

#endif
