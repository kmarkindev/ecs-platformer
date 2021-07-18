#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <memory>
#include <glm/glm.hpp>

class Window
{
public:
    explicit Window(std::string title, int width, int height, bool fullScreen);
    ~Window();
    void SwapBuffers();
    void PollEvents();
    bool HasCloseSignal();
    void RaiseCloseSignal();

    glm::ivec2 GetWindowSize();
    void SetWindowSize(glm::ivec2 newSize);

    const GLFWwindow* GetGlfwWindowPointer();

private:
    bool _glfwInited = false;
    GLFWwindow* _window;
};


