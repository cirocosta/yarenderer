#ifndef YARENDERER__UTILS__FILEINPUT_HH
#define YARENDERER__UTILS__FILEINPUT_HH

#include <iostream>
#include <cerrno>
#include <cstdio>
#include <cstring>
#include <string>
#include "yarenderer/debug.hh"

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
    delete[] data;

    return std::string(data);
  }
};
}
};

#endif
