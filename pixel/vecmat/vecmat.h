#ifndef PX_VECMAT_H
#define PX_VECMAT_H

#include <stdio.h>

typedef union {
    float raw[3];
    struct { float x, y, z; };
} Vec3;

typedef union {
    float raw[4];
    struct { float x, y, z, w; };
} Vec4;

typedef union {
    float raw[4][4];
    struct { Vec4 x, y, z, w; };
} Mat4;

#define ID_MAT4 (Mat4){ .raw = { \
    { 1.0f, 0.0f, 0.0f, 0.0f },  \
    { 0.0f, 1.0f, 0.0f, 0.0f },  \
    { 0.0f, 0.0f, 1.0f, 0.0f },  \
    { 0.0f, 0.0f, 0.0f, 1.0f },  \
}}

#define SCALE_MAT(x, y, z) (Mat4){ .raw = { \
    {   x, 0.0f, 0.0f, 0.0f}, \
    {0.0f,    y, 0.0f, 0.0f}, \
    {0.0f, 0.0f,    z, 0.0f}, \
    {0.0f, 0.0f, 0.0f, 1.0f}, \
}}

#define TRANSLATION_MAT(x, y, z) (Mat4){ .raw = { \
    {1.0f, 0.0f, 0.0f,    x}, \
    {0.0f, 1.0f, 0.0f,    y}, \
    {0.0f, 0.0f, 1.0f,    z}, \
    {0.0f, 0.0f, 0.0f, 1.0f}, \
}}

void printMat4(float m[][4]);
Mat4 mulMat4(Mat4* m, Mat4* n);

#endif
