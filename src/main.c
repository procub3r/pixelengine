#include <GL/glew.h>
#include "pixel.h"

int main() {
    initPixel(960, 540, "pixel engine");

    Mesh cubeMesh = {
        .file = "./res/cubeMesh.obj",
        .instanceCapacity = 2,
    };
    createMesh(&cubeMesh);

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    while (updateWindow()) {
        glClear(GL_COLOR_BUFFER_BIT);
        glBindVertexArray(cubeMesh.vao);
        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
    }

    destroyMesh(&cubeMesh);
    closeWindow();
}
