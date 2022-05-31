#include <GL/glew.h>
#include "shader/shader.h"
#include "pixel.h"

GLuint shaderProgram;

void initPixel(int windowWidth, int windowHeight, const char* windowTitle) {
    createWindow(windowWidth, windowHeight, windowTitle);

    GLuint vertexShader = compileShaderObject(GL_VERTEX_SHADER, "pixel/shader/vertex.glsl");
    GLuint fragmentShader = compileShaderObject(GL_FRAGMENT_SHADER, "pixel/shader/fragment.glsl");
    shaderProgram = linkShaderProgram(2, vertexShader, fragmentShader);
    glUseProgram(shaderProgram);
}
