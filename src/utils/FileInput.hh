#ifndef YARENDERER__UTILS__FILEINPUT_HH
#define YARENDERER__UTILS__FILEINPUT_HH

#include <cerrno>
#include <climits>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <libgen.h>
#include <string>
#include <unistd.h>

#include "debug.hh"

namespace yarenderer
{
namespace utils
{

class FileInput
{
public:
  static std::string read_file(const char* fname)
  {
    unsigned long length;
    char* data;
    FILE* file = fopen(fname, "r");

    ASSERT(file, "Error reading file: " << strerror(errno));

    fseek(file, 0, SEEK_END);
    length = ftell(file);
    data = new char[length + 1];
    memset(data, 0, length + 1);
    fseek(file, 0, SEEK_SET);
    fread(data, 1, length, file);
    fclose(file);
    std::string result(data);
    delete[] data;
    data = nullptr;

    return result;
  }

  inline static std::string get_selfdir()
  {
    char buff[PATH_MAX];
    ssize_t len = readlink("/proc/self/exe", buff, sizeof(buff) - 1);

    ASSERT(len != -1, "get_selfdir couldn't execute readlink properly.");

    buff[len] = '\0';
    dirname(buff);

    return std::string(buff);
  }
};
}
};

#endif
