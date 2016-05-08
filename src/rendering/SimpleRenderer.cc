#include "SimpleRenderer.hh"

namespace yarenderer {

  void Simple2DRenderer::flush() {
    while (!m_renderables.empty()) {
     //todo
    }
  }

  void Simple2DRenderer::submit(const Renderable2D* renderable) {
    m_renderables.push_back(renderable);
  }
}
