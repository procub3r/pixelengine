#include <GL/glew.h>
#include "pixel.h"

int main() {
    initPixel(960, 540, "pixel engine");

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    while (updateWindow()) {
        glClear(GL_COLOR_BUFFER_BIT);
    }

    closeWindow();
}
