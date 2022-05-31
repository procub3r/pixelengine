#include <GL/glew.h>
#include "pixel.h"

int main() {
    initPixel(960, 540, "pixel engine");

    Mesh cubeMesh = {
        .file = "./res/cubeMesh.obj",
        .instanceCapacity = 2,
    };
    createMesh(&cubeMesh);

    Object cubeObject = {
        .mesh = &cubeMesh,
        .scale = ID_MAT4,
        .rotation = ID_MAT4,
        .translation = TRANSLATION_MAT(-0.1f, 0.0f, 3.0f),
    };
    createObject(&cubeObject);

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    while (updateWindow()) {
        glClear(GL_COLOR_BUFFER_BIT);
        updateObject(&cubeObject);
        renderMeshInstances(&cubeMesh);
    }

    destroyMesh(&cubeMesh);
    closeWindow();
}
