#include "Window.hh"

namespace yarenderer
{

void _framebuffer_size_callback(GLFWwindow* win, int w, int h);
void _window_size_callback(GLFWwindow* win, int w, int h);
void _error_callback(int, const char*);

Window::Window(const char* title, int w, int h)
    : m_title(title), width(w), height(h)
{
  try {
    _init();
  } catch (const std::exception& err) {
    LOGERR("GLFW Error: " << err.what() << "\n");
    glfwTerminate();
    exit(EXIT_FAILURE);
  }
}

void Window::_init()
{
  if (!glfwInit())
    throw std::runtime_error("Failed to initialize GLFW");

  glfwSetErrorCallback(_error_callback);

  std::cout << width << ":" << height << " " << m_title << std::endl;
  m_window = glfwCreateWindow(width, height, m_title, NULL, NULL);

  if (!m_window)
    throw std::runtime_error("Failed to create window!");

  glfwMakeContextCurrent(m_window);
  glfwSetWindowUserPointer(m_window, this);
  glfwSetFramebufferSizeCallback(m_window, _framebuffer_size_callback);
  glfwSetWindowSizeCallback(m_window, _window_size_callback);

  glfwSwapInterval(1);

  if (::glewInit() != GLEW_OK)
    throw std::runtime_error("Couldn't initialize glew properly");
}

Window::~Window() { glfwTerminate(); }

bool Window::closed() const { return ::glfwWindowShouldClose(m_window); }

void Window::update()
{
  GL_CHECK();
  glfwPollEvents();
  glfwSwapBuffers(m_window);
}
void Window::clear() const
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void _window_size_callback(GLFWwindow* window, int w, int h)
{
  Window* win = (Window*)::glfwGetWindowUserPointer(window);

  win->width = w;
  win->height = h;
}

void _error_callback(int err, const char* msg)
{
  LOGERR("GLFW Error " << err << ": " << msg << "\n");
  glfwTerminate();
  exit(EXIT_FAILURE);
}

void _framebuffer_size_callback(GLFWwindow* win, int w, int h)
{
  ::glViewport(0, 0, w, h);
}
};
