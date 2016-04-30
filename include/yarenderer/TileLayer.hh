#ifndef YARENDERER__TILELAYER_HH
#define YARENDERER__TILELAYER_HH

#include "glm/gtx/transform.hpp"
#include "rendering/BatchRenderer.hh"
#include "yarenderer/Layer.hh"
#include "yarenderer__config.hh"

#include <string>
#include <vector>

#define BASIC_VSHADER YARENDERER__SHADER_SOURCES_DIR "/basic.vert"
#define BASIC_FSHADER YARENDERER__SHADER_SOURCES_DIR "/basic.frag"

namespace yarenderer
{
class TileLayer : public Layer
{
public:
  inline TileLayer()
    : Layer(new BatchRenderer(),
            new Shader(BASIC_VSHADER, BASIC_FSHADER,
                       std::vector<std::string>{ "pr_matrix" }),
            glm::ortho(-10.0, 10.0, -10.0, 10.0, -1.0, 1.0))
  {
  }

  inline ~TileLayer() {}
};

} // ns yarenderer

#endif
