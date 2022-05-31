#ifndef PX_PIXEL_H
#define PX_PIXEL_H

#include <GL/glew.h>
#include "window/window.h"
#include "opengl/buffer.h"
#include "object/mesh.h"
#include "object/object.h"

extern GLuint shaderProgram;

void initPixel(int windowWidth, int windowHeight, const char* windowTitle);

#endif
