#ifndef YARENDERER__DEBUG_HH
#define YARENDERER__DEBUG_HH

#include <iostream>
#include <memory>
#include <string>
#include <cstdio>

namespace yarenderer
{
namespace utils
{

template <typename... Args>
static std::string str_fmt(const char* fmt, Args... args)
{
  size_t size = std::snprintf(nullptr, 0, fmt, args...) + 1;
  std::unique_ptr<char[]> buf(new char[size]);
  std::snprintf(buf.get(), size, fmt, args...);

  return std::string(buf.get(), buf.get() + size - 1);
}

} // ns yarenderer
} // ns utils

#define ASSERT(condition, message)                                             \
  do {                                                                         \
    if (!(condition)) {                                                        \
      std::cerr << "\n\x1b[31;1mAssertion `" #condition "` failed.\x1b[0m\n"   \
                << "File:\t\x1b[30;1m" << __FILE__                             \
                << "\x1b[0m line \x1b[30;1m" << __LINE__                       \
                << "\x1b[0m: \nMsg:\t" << message << std::endl;                \
      std::exit(EXIT_FAILURE);                                                 \
    }                                                                          \
  } while (0)

#define LOG(message)                                                           \
  do {                                                                         \
    std::cout << "\x1b[30;1m(LOG):\x1b[0m " << message << std::endl;           \
  } while (0)

#define LOGERR(message)                                                        \
  do {                                                                         \
    std::cerr << "\x1b[31;1m(LOG_ERR):\x1b[0m " << message << std::endl;       \
  } while (0)

#ifndef NDEBUG

#define DASSERT(condition, message) ASSERT(condition, message)
#define DLOG(message) LOG(message)
#define DLOGERR(message) LOGERR(message)

#else
#define DASSERT(condition, message)
#define DLOG(message)
#define DLOGERR(message)

#endif // ! NDEBUG

#endif // ! YARENDERER__DEBUG_HH
