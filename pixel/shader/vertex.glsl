#version 330

layout (location = 0) in vec4 position;
layout (location = 2) in mat4 projectionMat;

void main() {
    gl_Position = transpose(projectionMat) * position;
}
