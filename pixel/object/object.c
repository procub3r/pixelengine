#include "object.h"
#include "vecmat/vecmat.h"

// What happens when this function is
// called on the same object many times?
void createObject(Object* object) {
    object->instanceID = addInstance(object->mesh);
}

void updateObject(Object* object) {
    Mat4 tmp = mulMat4(&object->translation, &object->rotation);
    object->modelMatrix = mulMat4(&tmp, &object->scale);
    // Multiply this with the projection matrix and store
    // that in the instance attrib array
    // Also maybe create a function to do this easily
    object->mesh->instanceAttribArray[object->instanceID] = (InstanceAttributes){
        .projectionMat = object->modelMatrix,
    };
}
