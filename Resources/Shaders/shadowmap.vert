#version 150 core
in vec3 vertex;
uniform mat4 mvp;

void main(void)
{
    gl_Position = mvp * vertex;
}
