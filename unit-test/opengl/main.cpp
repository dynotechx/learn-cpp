#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <iostream>

int main() {
    // Initialize EGL
    EGLDisplay display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
    if (display == EGL_NO_DISPLAY) {
        std::cerr << "Failed to get EGL display." << std::endl;
        return -1;
    }

    EGLBoolean initialized = eglInitialize(display, nullptr, nullptr);
    if (initialized == EGL_FALSE) {
        std::cerr << "Failed to initialize EGL." << std::endl;
        return -1;
    }

    // Print EGL version
    EGLint major, minor;
    eglInitialize(display, &major, &minor);
    std::cout << "EGL version: " << major << "." << minor << std::endl;

    // Choose an EGL configuration
    EGLConfig config;
    EGLint numConfigs;
    EGLint attribs[] = {
        EGL_RENDERABLE_TYPE, EGL_OPENGL_ES2_BIT,
        EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
        EGL_NONE
    };

    EGLBoolean configChosen = eglChooseConfig(display, attribs, &config, 1, &numConfigs);
    if (configChosen == EGL_FALSE || numConfigs == 0) {
        std::cerr << "Failed to choose EGL config." << std::endl;
        eglTerminate(display);
        return -1;
    }

    // Create an EGL context
    EGLContext context = eglCreateContext(display, config, EGL_NO_CONTEXT, nullptr);
    if (context == EGL_NO_CONTEXT) {
        std::cerr << "Failed to create EGL context." << std::endl;
        eglTerminate(display);
        return -1;
    }

    // Clean up
    eglDestroyContext(display, context);
    eglTerminate(display);

    std::cout << "EGL setup completed successfully." << std::endl;
    return 0;
}