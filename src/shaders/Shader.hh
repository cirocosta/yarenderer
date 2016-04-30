#ifndef YARENDERER__SHADER_HH
#define YARENDERER__SHADER_HH

#include "OpenGL/gl3.h"
#include "glm/gtc/type_ptr.hpp"
#include "utils/FileInput.hh"
#include "utils/debug.hh"

#include <map>
#include <string>
#include <vector>

namespace yarenderer
{

class Shader
{
  const char* m_vertex_path;
  const char* m_fragment_path;
  std::map<std::string, GLint> locations;

  GLuint m_shader_id;

public:
  Shader(const char* vp, const char* fp,
         const std::vector<std::string>& uniform_locations);
  ~Shader();

  inline void enable() const { glUseProgram(m_shader_id); }

  inline void disable() const { glUseProgram(0); }

  inline GLint getLocation(const std::string& loc) const
  {
    return locations.at(loc);
  }

  inline void setUniformMat4(const GLchar* name, const glm::mat4& matrix)
  {
    glUniformMatrix4fv(locations.at(name), 1, GL_FALSE, glm::value_ptr(matrix));
  }

  inline void setUniform4f(const GLchar* name, const glm::vec4& vec)
  {
    glUniform4fv(locations.at(name), 1, glm::value_ptr(vec));
  }

  inline void setUniform2f(const GLchar* name, const glm::vec2& vec)
  {
    glUniform2fv(locations.at(name), 1, glm::value_ptr(vec));
  }

  inline void setUniform1i(const GLchar* name, const int value)
  {
    glUniform1i(locations.at(name), value);
  }

private:
  GLuint _load(const std::vector<std::string>& ulocs);
};
}; // ns yarenderer

#endif
