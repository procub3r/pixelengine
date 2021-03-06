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
    InstanceAttribBuffer instanceAttribBuffer;
    unsigned int instanceCount;
    unsigned int instanceCapacity;
    InstanceAttributes* instanceAttribArray;
} Mesh;

void createMesh(Mesh* mesh);
unsigned int addInstance(Mesh* mesh);
// TODO: Implement removeInstance()
void renderMeshInstances(Mesh* mesh);
void destroyMesh(Mesh* mesh);

#endif
