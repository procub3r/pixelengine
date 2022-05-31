#ifndef PX_MESH_H
#define PX_MESH_H

#include "opengl/buffer.h"
#include "vecmat/vecmat.h"

// Object properties that vary
// between different instances
// of the same mesh
typedef struct InstanceAttributes {
    Mat4 projectionMat;
    // Add more properties here like
    // color, texture coords etc
} InstanceAttributes;

typedef struct Mesh {
    const char* file;
    GLuint vao;
    VertexBuffer vertexBuffer;
    IndexBuffer indexBuffer;
    unsigned int instanceCount;
    unsigned int instanceCapacity;
    InstanceAttributes* instanceAttribs;
} Mesh;

void createMesh(Mesh* mesh);
InstanceAttributes* addInstance(Mesh* mesh);
// TODO: Implement removeInstance()
void destroyMesh(Mesh* mesh);

#endif
