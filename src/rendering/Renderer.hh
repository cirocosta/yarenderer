#ifndef YARENDERER__RENDERER_HH
#define YARENDERER__RENDERER_HH

namespace yarenderer
{
class Renderable;

class Renderer
{
public:
  Renderer() = default;
  virtual ~Renderer();

  virtual void begin();
  virtual void submit(const Renderable* renderable) = 0;
  virtual void flush() = 0;
  virtual void end();
};

}; // ns yarenderer

#endif
