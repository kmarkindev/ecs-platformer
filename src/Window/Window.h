#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <memory>

class Window
{
public:
    explicit Window(std::string title, int width, int height, bool fullScreen);
    ~Window();
    void SwapBuffers();
    void PollEvents();
    bool HasCloseSignal();

private:
    bool _glfwInited = false;
    GLFWwindow* _window;
};


