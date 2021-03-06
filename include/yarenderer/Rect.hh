#ifndef YARENDERER__RECT_HH
#define YARENDERER__RECT_HH

#include "glm/gtc/type_ptr.hpp"
#include "yarenderer/Renderable.hh"

namespace yarenderer
{

class Rect : public Renderable
{
public:
  Rect(float x, float y, float width, float height, float z = 0)
    : Renderable(glm::vec3(x, y, z), glm::vec2(width, height), glm::vec4())
  {
  }
  virtual ~Rect()
  {
  }
};

} // ns yarenderer

#endif
