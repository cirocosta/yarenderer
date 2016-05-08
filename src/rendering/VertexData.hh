#ifndef YARENDERER__VERTEXDATA_HH
#define YARENDERER__VERTEXDATA_HH

#include "glm/gtc/type_ptr.hpp"

namespace yarenderer
{

/**
 * Vertex' data submitted to the buffer
 */
struct VertexData {
  glm::vec3 vertex;
  glm::vec2 uv;
  unsigned color;
};
}

#endif
