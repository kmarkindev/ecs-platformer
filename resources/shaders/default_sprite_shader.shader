@@BEGIN@VERTEX_SHADER@@
#version 330 core

layout (location = 0) in vec2 in_verticle;
layout (location = 1) in vec2 in_textureCoord;

out vec2 oi_texturePos;

uniform mat4 u_transform;

void main()
{
    gl_Position = u_transform * vec4(in_verticle.x, in_verticle.y, 0, 1);
    oi_texturePos = in_textureCoord;
}
@@END@VERTEX_SHADER@@
@@BEGIN@FRAGMENT_SHADER@@
#version 330 core

in vec2 oi_texturePos;

out vec4 out_color;

uniform sampler2D u_texture;

void main()
{
    out_color = texture(u_texture, oi_texturePos);
}
@@END@FRAGMENT_SHADER@@