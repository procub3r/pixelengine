#ifndef PX_SHADER_H
#define PX_SHADER_H

#include <GL/glew.h>

GLuint compileShaderObject(GLenum shaderType, const char* shaderFile);
GLuint linkShaderProgram(int shaderObjCount, ...);

#endif
