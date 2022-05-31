#include "vecmat.h"

void printMat4(float m[][4]) {
    for (int i = 0; i < 4; i++) {
        printf("%f, %f, %f, %f\n", m[i][0], m[i][1], m[i][2], m[i][3]);
    }
    printf("\n");
}

Mat4 mulMat4(Mat4* m, Mat4* n) {
    Mat4 result = {0};
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                result.raw[i][j] += m->raw[i][k] * n->raw[k][j];
            }
        }
    }
    return result;
}
