#ifndef YARENDERER__RECT_HH
#define YARENDERER__RECT_HH

#include "glm/gtc/type_ptr.hpp"
#include "yarenderer/Renderable2D.hh"

namespace yarenderer
{

class Rect : public Renderable2D
{
public:
  Rect(float x, float y, float width, float height, float z = 0)
    : Renderable2D(glm::vec3(x, y, z), glm::vec2(width, height), glm::vec4())
  {
  }
  virtual ~Rect()
  {
  }
};

} // ns yarenderer

#endif
