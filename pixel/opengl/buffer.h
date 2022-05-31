#ifndef PX_BUFFER_H
#define PX_BUFFER_H

#include <GL/glew.h>

typedef struct VertexBuffer {
    GLuint object;
    GLsizeiptr size;
    GLvoid* data;
    GLenum usage;
} VertexBuffer;

typedef struct IndexBuffer {
    GLuint object;
    // GLenum type; // Defaults to GL_UNSIGNED_INT for now
    unsigned int count;
    GLsizeiptr size;
    GLvoid* data;
    GLenum usage;
} IndexBuffer;

void initVertexBuffer(VertexBuffer* buf);
void initIndexBuffer(IndexBuffer* buf);

#endif
