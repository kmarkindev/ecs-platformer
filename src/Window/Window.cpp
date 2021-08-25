#include "Window.h"

Window::Window(const std::string& title, int width, int height, bool fullScreen)
{
    if(!_glfwInited)
    {
        glfwInit();
        _glfwInited = true;
    }
    const char* charTitle = title.c_str();

#if DEBUG_BUILD
    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
#endif

    glfwWindowHint(GLFW_SAMPLES, 4);
    _window = glfwCreateWindow(width, height, charTitle, fullScreen ? glfwGetPrimaryMonitor() : nullptr, nullptr);

    glfwMakeContextCurrent(_window);

    glfwSwapInterval(0);
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

glm::ivec2 Window::GetWindowSize()
{
    glm::ivec2 size;
    glfwGetWindowSize(_window, &size[0], &size[1]);
    return size;
}

void Window::SetWindowSize(glm::ivec2 newSize)
{
    glfwSetWindowSize(_window, newSize[0], newSize[1]);
}

const GLFWwindow* Window::GetGlfwWindowPointer()
{
    return _window;
}
