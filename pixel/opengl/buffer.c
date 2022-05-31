#include "vecmat/vecmat.h"
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

void initInstanceAttribBuffer(InstanceAttribBuffer* buf) {
    glGenBuffers(1, &buf->object);
    glBindBuffer(GL_ARRAY_BUFFER, buf->object);
    glBufferData(GL_ARRAY_BUFFER, buf->size, NULL, GL_DYNAMIC_DRAW);

    glEnableVertexAttribArray(2); // Projection matrix row 1
    glEnableVertexAttribArray(3); // Projection matrix row 2
    glEnableVertexAttribArray(4); // Projection matrix row 3
    glEnableVertexAttribArray(5); // Projection matrix row 4

    size_t sizeOfVec4 = sizeof(Vec4);
    glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, 4 * sizeOfVec4, (void*)(0 * sizeOfVec4));
    glVertexAttribPointer(3, 4, GL_FLOAT, GL_FALSE, 4 * sizeOfVec4, (void*)(1 * sizeOfVec4));
    glVertexAttribPointer(4, 4, GL_FLOAT, GL_FALSE, 4 * sizeOfVec4, (void*)(2 * sizeOfVec4));
    glVertexAttribPointer(5, 4, GL_FLOAT, GL_FALSE, 4 * sizeOfVec4, (void*)(3 * sizeOfVec4));

    glVertexAttribDivisor(2, 1);
    glVertexAttribDivisor(3, 1);
    glVertexAttribDivisor(4, 1);
    glVertexAttribDivisor(5, 1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
