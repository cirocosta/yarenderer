#ifndef YARENDERER__RENDERER_HH
#define YARENDERER__RENDERER_HH

namespace yarenderer
{
class Renderable2D;

class Renderer
{
public:
  Renderer() = default;
  virtual ~Renderer()
  {
  }

  virtual void begin()
  {
  }
  virtual void submit(const Renderable2D* renderable) = 0;
  virtual void flush() = 0;
  virtual void end()
  {
  }
};

}; // ns yarenderer

#endif
