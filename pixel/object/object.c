#include "object.h"
#include "vecmat/vecmat.h"

// What happens when this function is
// called on the same object many times?
void createObject(Object* object) {
    object->instanceAttribs = addInstance(object->mesh);
}

void updateObject(Object* object) {
    Mat4 tmp = mulMat4(&object->translation, &object->rotation);
    object->modelMatrix = mulMat4(&tmp, &object->scale);
    // Multiply this with the projection matrix and store
    // that in the instance attrib array
    (*object->instanceAttribs) = (InstanceAttributes){
        .projectionMat = object->modelMatrix,
    };
}
