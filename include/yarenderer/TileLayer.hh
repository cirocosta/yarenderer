#ifndef YARENDERER__TILELAYER_HH
#define YARENDERER__TILELAYER_HH

#include "yarenderer__config.hh"
#include "yarenderer/Layer.hh"
#include "rendering/BatchRenderer.hh"
#include "glm/gtx/transform.hpp"

#define BASIC_VSHADER YARENDERER__SHADER_SOURCES_DIR "/basic.vert"
#define BASIC_FSHADER YARENDERER__SHADER_SOURCES_DIR "/basic.frag"

namespace yarenderer
{
class TileLayer : public Layer
{
public:
  inline TileLayer()
      : Layer(new BatchRenderer(), new Shader(BASIC_VSHADER, BASIC_FSHADER),
              glm::ortho(-10.0, 10.0, -10.0, 10.0, -1.0, 1.0))
  {
  }

  inline ~TileLayer() {}
};

} // ns yarenderer

#endif
