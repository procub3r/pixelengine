#include <GL/glew.h>
#include "pixel.h"

int main() {
    initPixel(960, 540, "pixel engine");

    Mesh cubeMesh = {
        .file = "./res/cubeMesh.obj",
        .instanceCapacity = 1,
    };
    createMesh(&cubeMesh);

    Object cubeObject = {
        .mesh = &cubeMesh,
        .scale = SCALE_MAT(0.5f, 0.5f, 0.5f),
        .rotation = ID_MAT4,
        .translation = TRANSLATION_MAT(-0.3f, -0.3f, 0.1f),
    };
    createObject(&cubeObject);

    Object cubeObject2 = {
        .mesh = &cubeMesh,
        .scale = SCALE_MAT(0.5f, 0.75f, 0.5f),
        .rotation = ID_MAT4,
        .translation = TRANSLATION_MAT(0.3f, 0.3f, 0.1f),
    };
    createObject(&cubeObject2);

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    while (updateWindow()) {
        glClear(GL_COLOR_BUFFER_BIT);
        updateObject(&cubeObject);
        updateObject(&cubeObject2);
        renderMeshInstances(&cubeMesh);
    }

    destroyMesh(&cubeMesh);
    closeWindow();
}
