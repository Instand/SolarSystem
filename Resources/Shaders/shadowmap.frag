#version 150 core

precision mediump float;

out float fragmentDepth;

void main(void)
{
    fragmentDepth = gl_FragCoord.z;
}
