#include "Window.h"

Window::Window(std::string title, int width, int height, bool fullScreen)
{
    if(!_glfwInited)
    {
        glfwInit();
        _glfwInited = true;
    }
    const char* charTitle = title.c_str();
    _window = glfwCreateWindow(width, height, charTitle, fullScreen ? glfwGetPrimaryMonitor() : nullptr, nullptr);

    glfwMakeContextCurrent(_window);
}

Window::~Window()
{
    glfwDestroyWindow(_window);
    glfwTerminate();
}

void Window::SwapBuffers()
{
    glfwSwapBuffers(_window);
}

void Window::PollEvents()
{
    glfwPollEvents();
}

bool Window::HasCloseSignal()
{
    return glfwWindowShouldClose(_window);
}

void Window::RaiseCloseSignal()
{
    glfwSetWindowShouldClose(_window, GLFW_TRUE);
}
