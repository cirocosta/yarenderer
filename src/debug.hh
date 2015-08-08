#ifndef YARENDERER__DEBUG_HH
#define YARENDERER__DEBUG_HH

#include <iostream>
#include <memory>
#include <string>
#include <cstdio>

template <typename... Args>
static std::string str_fmt(const char* fmt, Args... args)
{
  size_t size = std::snprintf(nullptr, 0, fmt, args...) + 1;
  std::unique_ptr<char[]> buf(new char[size]);
  std::snprintf(buf.get(), size, fmt, args...);

  return std::string(buf.get(), buf.get() + size - 1);
}

static void CheckOpenGLError(const char* stmt, const char* fname, int line)
{
  GLenum err = glGetError();
  if (err != GL_NO_ERROR) {
    throw std::runtime_error(str_fmt("OpenGL error %08x, at %s:%i - for %s\n",
                                     err, fname, line, stmt));
  }
}

#define ASSERT(condition, message)                                             \
  do {                                                                         \
    if (!(condition)) {                                                        \
      std::cerr << "Assertion `" #condition "` failed in " << __FILE__         \
                << " line " << __LINE__ << ": " << message << std::endl;       \
      std::exit(EXIT_FAILURE);                                                 \
    }                                                                          \
  } while (0)

#define LOG(message)                                                           \
  do {                                                                         \
    std::cout << "LOG: " << message << std::endl;                              \
  } while (0)

#define LOGERR(message)                                                        \
  do {                                                                         \
    std::cerr << "LOG: " << message << std::endl;                              \
  } while (0)

#ifndef NDEBUG

#define DASSERT(condition, message) ASSERT(condition, message)
#define DLOG(message) LOG(message)
#define DLOGERR(message) LOGERR(message)
#define GL_CHECK(stmt) stmt

#else
#define DASSERT(condition, message)
#define DLOG(message)
#define DLOGERR(message)

#define GL_CHECK(stmt)                                                         \
  do {                                                                         \
    stmt;                                                                      \
    CheckOpenGLError(#stmt, __FILE__, __LINE__);                               \
  } while (0)
#endif // ! NDEBUG

#endif // ! YARENDERER__DEBUG_HH
