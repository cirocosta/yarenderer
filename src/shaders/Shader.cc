#include "Shader.hh"

namespace yarenderer
{

Shader::Shader(const char* vpath, const char* fpath)
    : m_vertex_path(vpath), m_fragment_path(fpath)
{
  m_shader_id = _load();
  ASSERT(m_shader_id, vpath << " and/org " << fpath
                            << " have a compilation error.");
}

Shader::~Shader() { glDeleteProgram(m_shader_id); }

GLuint Shader::_load()
{
  GLuint program = glCreateProgram();
  GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
  GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);
  GLint result;

  std::string vertSourceStr = utils::FileInput::read_file(m_vertex_path);
  std::string fragSourceStr = utils::FileInput::read_file(m_fragment_path);

  const char* vertSource = vertSourceStr.c_str();
  const char* fragSource = fragSourceStr.c_str();

  glShaderSource(vertex, 1, &vertSource, NULL);
  glCompileShader(vertex);

  glGetShaderiv(vertex, GL_COMPILE_STATUS, &result);

  // in case the shader failed
  if (result == GL_FALSE) {
    GLint length;
    glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length);
    std::vector<char> error(length);
    glGetShaderInfoLog(vertex, length, &length, &error[0]);
    LOGERR("Failed to compile vshader:\n" << &error[0] << "\n");
    glDeleteShader(vertex);

    return 0;
  }

  glShaderSource(fragment, 1, &fragSource, NULL);
  glCompileShader(fragment);

  glGetShaderiv(fragment, GL_COMPILE_STATUS, &result);

  // in case the shader failed
  if (result == GL_FALSE) {
    GLint length;
    glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &length);
    std::vector<char> error(length);
    glGetShaderInfoLog(fragment, length, &length, &error[0]);
    LOGERR("Failed to compile fshader:\n" << &error[0] << "\n");
    glDeleteShader(vertex);
    glDeleteShader(fragment);

    return 0;
  }

  glAttachShader(program, vertex);
  glAttachShader(program, fragment);

  glLinkProgram(program);
  glValidateProgram(program);

  glDeleteShader(vertex);
  glDeleteShader(fragment);

  return program;
}

};
