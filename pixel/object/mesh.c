#include <stdio.h>
#include <stdlib.h>
#include "mesh.h"

void createMesh(Mesh* mesh) {
    // Load the mesh data from file
    FILE* fp = fopen(mesh->file, "r");
    if (!fp) {
        perror("loadMesh");
        fprintf(stderr, "Could not load mesh from file \"%s\"\n", mesh->file);
    }

    int vertexCount = 0;
    int indexCount = 0;
    
    char line[100];
    while (fgets(line, 100, fp) != NULL) {
        if (line[0] == 'v') vertexCount += 1;
        else if (line[0] == 'f') indexCount += 3;
    }
    fseek(fp, 0, SEEK_SET);

    GLfloat* vertexBuffer = malloc(6 * vertexCount * sizeof(GLfloat));
    GLuint* indexBuffer = malloc(indexCount * sizeof(GLuint));

    int curVertexBufferElement = 0;
    int curIndexBufferElement = 0;

    while (fgets(line, 100, fp) != NULL) {
        if (line[0] == 'v') {
            GLfloat x, y, z;
            sscanf(line, "v %f %f %f\n", &x, &y, &z);
            vertexBuffer[curVertexBufferElement + 0] = x;
            vertexBuffer[curVertexBufferElement + 1] = y;
            vertexBuffer[curVertexBufferElement + 2] = z;
            curVertexBufferElement += 6;
        } else if (line[0] == 'f') {
            GLuint x, y, z;
            sscanf(line, "f %u %u %u\n", &x, &y, &z);
            indexBuffer[curIndexBufferElement + 0] = x - 1;
            indexBuffer[curIndexBufferElement + 1] = y - 1;
            indexBuffer[curIndexBufferElement + 2] = z - 1;
            curIndexBufferElement += 3;
        }
    }
    fclose(fp);

    glGenVertexArrays(1, &mesh->vao);
    glBindVertexArray(mesh->vao);
    
    mesh->vertexBuffer = (VertexBuffer){
        .size = 6 * vertexCount * sizeof(GLfloat),
        .data = vertexBuffer,
        .usage = GL_STATIC_DRAW,
    };
    initVertexBuffer(&mesh->vertexBuffer);
    // It's not necessary to bind the vertex buffer

    mesh->indexBuffer = (IndexBuffer){
        .count = indexCount,
        .size = indexCount * sizeof(GLuint),
        .data = indexBuffer,
        .usage = GL_STATIC_DRAW,
    };
    initIndexBuffer(&mesh->indexBuffer);
    // Bind the index buffer becuase initIndexBuffer() unbinds it
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->indexBuffer.object);

    glBindVertexArray(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    free(vertexBuffer);
    free(indexBuffer);

    // Initialize the rest of the mesh
    mesh->instanceCount = 0;
    mesh->instanceAttribArray = malloc(mesh->instanceCapacity * sizeof(InstanceAttributes));

    printf("Mesh \"%s\" loaded from file and initialized with initial capacity %u\n", mesh->file, mesh->instanceCapacity);
}

InstanceAttributes* addInstance(Mesh* mesh) {
    if (mesh->instanceCount == mesh->instanceCapacity) {
        mesh->instanceCapacity *= 2;
        mesh->instanceAttribArray = realloc(mesh->instanceAttribArray, mesh->instanceCapacity * sizeof(InstanceAttributes));
    }
    mesh->instanceCount++;
    printf("Instance attribute added to mesh \"%s\"\n", mesh->file);
    return &(mesh->instanceAttribArray[mesh->instanceCount - 1]);
}

void renderMeshInstances(Mesh* mesh) {
    glBindVertexArray(mesh->vao);
    for (int i = 0; i < mesh->instanceCount; i++) {
        // The type of an index is GL_UNSIGNED_INT by default for now
        glDrawElements(GL_TRIANGLES, mesh->indexBuffer.count, GL_UNSIGNED_INT, 0);
    }
    glBindVertexArray(0);
}

void destroyMesh(Mesh* mesh) {
    free(mesh->instanceAttribArray);
    printf("All instance attributes of mesh \"%s\" destroyed\n", mesh->file);
}
