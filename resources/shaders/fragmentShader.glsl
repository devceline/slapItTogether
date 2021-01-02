#version 330 core

in vec3 outVColor;
out vec4 color;

void main(){
    color = vec4(outVColor.r, outVColor.g, outVColor.b, 1.0);
}
