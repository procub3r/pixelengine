#ifndef PX_OBJECT_H
#define PX_OBJECT_H

#include "mesh.h"
#include "vecmat/vecmat.h"

typedef struct Object {
    Mesh* mesh;
    Mat4 scale, rotation, translation;
    Mat4 modelMatrix;
    unsigned int instanceID;
} Object;

void createObject(Object* object);
void updateObject(Object* object);
// TODO: Implement destroyObject()

#endif
