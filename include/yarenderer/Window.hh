#ifndef YARENDERER__WINDOW_HH
#define YARENDERER__WINDOW_HH

#include "GLFW/glfw3.h"
#include "yarenderer/GL.hh"
#include <stdexcept>

namespace yarenderer
{

class Window
{
private:
  const char* m_title;
  GLFWwindow* m_window;

public:
  int width;
  int height;

public:
  Window(const char* name, int width, int height);
  ~Window();

  bool closed() const;
  void update();
  void clear() const;

private:
  void _init();

  friend void _framebuffer_size_callback(GLFWwindow* win, int w, int h);
  friend void _window_size_callback(GLFWwindow* win, int w, int h);
  friend void _error_callback(int, const char*);
};

}; // ! ns yarenderer

#endif
