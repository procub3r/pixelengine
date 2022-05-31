#include <GL/glew.h>
#include "pixel.h"

int main() {
    initPixel(960, 540, "pixel engine");

    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    float vertexData[] = {
        -0.75f,  0.75f, 0.0f, 0.0f, 0.0f, 0.0f,
        -0.75f, -0.75f, 0.0f, 0.0f, 0.0f, 0.0f,
         0.75f, -0.75f, 0.0f, 0.0f, 0.0f, 0.0f,
    };

    VertexBuffer vertexBuffer = {
        .data = vertexData,
        .size = sizeof(vertexData),
        .usage = GL_STATIC_DRAW,
    };
    initVertexBuffer(&vertexBuffer);

    unsigned int indexData[] = {
        0, 1, 2,
    };

    IndexBuffer indexBuffer = {
        .data = indexData,
        .size = sizeof(indexData),
        .usage = GL_STATIC_DRAW,
        .count = 3,
    };
    initIndexBuffer(&indexBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer.object);

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    while (updateWindow()) {
        glClear(GL_COLOR_BUFFER_BIT);
        glDrawElements(GL_TRIANGLES, indexBuffer.count, GL_UNSIGNED_INT, 0);
    }

    closeWindow();
}
