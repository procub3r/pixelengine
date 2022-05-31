#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include "window.h"

static GLFWwindow* window;
static int width, height;

static void onResize(GLFWwindow* window, int width_, int height_) {
    glViewport(0, 0, width_, height_);
    width = width_;
    height = height_;
}

void createWindow(int width_, int height_, const char* title) {
    if (!glfwInit()) {
        fprintf(stderr, "could not initialize GLFW\n");
        return;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(width_, height_, title, NULL, NULL);
    if (!window) {
        fprintf(stderr, "could not create window\n");
        glfwTerminate();
        return;
    }

    glfwSetWindowSizeCallback(window, onResize);

    // load OpenGL functions
    glfwMakeContextCurrent(window);
    GLenum glewError = glewInit();
    if (glewError != GLEW_OK) {
        fprintf(stderr, "could not initialize GLEW\n");
        fprintf(stderr, "%s\n", glewGetErrorString(glewError));
        closeWindow();
    }

    width = width_;
    height = height_;
}

char updateWindow() {
    glfwPollEvents();
    glfwSwapBuffers(window);
    return !glfwWindowShouldClose(window);
}

void closeWindow() {
    glfwDestroyWindow(window);
    glfwTerminate();
}
