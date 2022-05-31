#include <stdio.h>
#include <stdarg.h>
#include "shader.h"

GLuint compileShaderObject(GLenum shaderType, const char* shaderFile) {
    FILE* fp = fopen(shaderFile, "r");
    if (!fp) {
        perror("loadShaderObject");
        fprintf(stderr, "Could not load shader file \"%s\"\n", shaderFile);
    }

    fseek(fp, 0, SEEK_END);
    long fileSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    GLchar shaderString[fileSize + 1];
    fread(shaderString, 1, fileSize, fp);
    fclose(fp);
    shaderString[fileSize] = '\0';
    const GLchar* shaderStringPointer = shaderString;

    GLuint shader = glCreateShader(shaderType);
    glShaderSource(shader, 1, &shaderStringPointer, NULL);
    glCompileShader(shader);

    GLint compileStatus;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &compileStatus);
    if (compileStatus != GL_TRUE) {
        GLint infoLogLength;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLength);
        GLchar infoLog[infoLogLength];
        glGetShaderInfoLog(shader, infoLogLength, NULL, infoLog);
        fprintf(stderr, "%s\n", infoLog);
    }

    return shader;
}

GLuint linkShaderProgram(int shaderObjCount, ...) {
    GLuint shaderObjects[shaderObjCount];
    GLuint shaderProgram = glCreateProgram();

    va_list va_ptr;
    va_start(va_ptr, shaderObjCount);
    for (int i = 0; i < shaderObjCount; i++) {
        shaderObjects[i] = va_arg(va_ptr, GLuint);
        glAttachShader(shaderProgram, shaderObjects[i]);
    }
    va_end(va_ptr);

    glLinkProgram(shaderProgram);
    GLint linkStatus;
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &linkStatus);
    if (linkStatus != GL_TRUE) {
        GLint infoLogLength;
        glGetProgramiv(shaderProgram, GL_INFO_LOG_LENGTH, &infoLogLength);
        GLchar infoLog[infoLogLength];
        glGetProgramInfoLog(shaderProgram, infoLogLength, NULL, infoLog);
        fprintf(stderr, "%s\n", infoLog);
    }

    for (int i = 0; i < shaderObjCount; i++) {
        glDetachShader(shaderProgram, shaderObjects[i]);
        glDeleteShader(shaderObjects[i]);
    }

    return shaderProgram;
}
