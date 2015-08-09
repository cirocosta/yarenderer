#version 330 core

layout(location = 0) out vec4 color;

in DATA
{
  vec4 position;
  vec2 uv;
  vec4 color;
}
fs_in;

uniform vec4 colour;
uniform vec2 light_pos;
uniform sampler2D tex;

void main()
{
  color = fs_in.color * intensity;
}
