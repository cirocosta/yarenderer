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

#include <FreeImage.h>

#include "debug.hh"
#include "yarenderer/GL.hh"

namespace yarenderer
{
namespace utils
{

class IO
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


  static BYTE* read_image(const char* filename, GLsizei* width, GLsizei* height)
  {
    FREE_IMAGE_FORMAT format = FIF_UNKNOWN;
    FIBITMAP* image_bitmap = nullptr;

    format = FreeImage_GetFileType(filename, 0);
    if (format == FIF_UNKNOWN) {
      format = FreeImage_GetFIFFromFilename(filename);
      if (format == FIF_UNKNOWN)
        return nullptr;
    }

    if (FreeImage_FIFSupportsReading(format))
      image_bitmap = FreeImage_Load(format, filename);
    if (!image_bitmap)
      return nullptr;

    BYTE* image = FreeImage_GetBits(image_bitmap);
    *width = FreeImage_GetWidth(image_bitmap);
    *height = FreeImage_GetHeight(image_bitmap);

    return image;
  }

  static void save_pixels_to_image(BYTE* pixels, const GLsizei width,
                                   const GLsizei height, const char* fname)
  {
    FIBITMAP* image = FreeImage_ConvertFromRawBits(
      pixels, width, height, 3 * width, 24, 0xFF0000, 0x00FF00, 0x0000BB, true);
    FreeImage_Save(FIF_BMP, image, fname);
    FreeImage_Unload(image);
  }
};
}
};

#endif
