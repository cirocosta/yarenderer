#version 150 

in vec4 position;
in vec2 uv;
in vec4 color;

uniform mat4 pr_matrix;

void main()
{
  gl_Position = pr_matrix * position;
}
