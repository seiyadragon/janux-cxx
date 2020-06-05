#version 330 core

in vec2 out_uv;

out vec4 frag_color;

uniform vec4 color = vec4(1, 1, 1, 1);
uniform sampler2D tex;

void main()
{
    frag_color = texture(tex, out_uv) * color;
}