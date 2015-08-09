#ifndef YARENDERER__SHADER_HH
#define YARENDERER__SHADER_HH

#include "GL/glew.h"
#include "glm/gtc/type_ptr.hpp"
#include "utils/FileInput.hh"
#include "yarenderer/debug.hh"

#include <string>
#include <vector>

namespace yarenderer
{

class Shader
{
  const char* m_vertex_path;
  const char* m_fragment_path;

  GLuint m_shader_id;

public:
  Shader(const char* vp, const char* fp);
  ~Shader();

  inline void enable() const { glUseProgram(m_shader_id); }

  inline void disable() const { glUseProgram(0); }

  inline void setUniformMat4(const GLchar* name, const glm::mat4& matrix)
  {
    glUniformMatrix4fv(_getUniformLocation(name), 1, GL_FALSE,
                       glm::value_ptr(matrix));
  }

  inline void setUniform4f(const GLchar* name, const glm::vec4& vec)
  {
    glUniform4fv(_getUniformLocation(name), 1, glm::value_ptr(vec));
  }

  inline void setUniform2f(const GLchar* name, const glm::vec2& vec)
  {
    glUniform2fv(_getUniformLocation(name), 1, glm::value_ptr(vec));
  }

  inline void setUniform1i(const GLchar* name, const int value)
  {
    glUniform1i(_getUniformLocation(name), value);
  }

private:
  GLuint _load();
  // FIXME create a hash table
  inline GLint _getUniformLocation(const GLchar* name)
  {
    return glGetUniformLocation(m_shader_id, name);
  }
};
}; // ns yarenderer

#endif
