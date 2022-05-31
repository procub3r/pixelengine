#include "buffer.h"

void initVertexBuffer(VertexBuffer* buf) {
    glGenBuffers(1, &buf->object);
    glBindBuffer(GL_ARRAY_BUFFER, buf->object);
    glBufferData(GL_ARRAY_BUFFER, buf->size, buf->data, buf->usage);
    glEnableVertexAttribArray(0); // Vertex positions
    glEnableVertexAttribArray(1); // Vertex normals
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), 0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void initIndexBuffer(IndexBuffer* buf) {
    glGenBuffers(1, &buf->object);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buf->object);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, buf->size, buf->data, buf->usage);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
