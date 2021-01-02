#version 330 core


layout(location = 0)in vec4 pos;
layout(location = 1)in vec3 inVColor;
out vec3 outVColor;

void main(){
    outVColor = inVColor;
    gl_Position = vec4(pos.x, pos.y, pos.z, pos.w);
}
