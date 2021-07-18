#include "InputManager.h"

bool InputManager::KeyPressed(KeyCode code)
{
    return GetGlfwKeyState(code) == GLFW_PRESS;
}

bool InputManager::KeyReleased(KeyCode code)
{
    return GetGlfwKeyState(code) == GLFW_RELEASE;
}

InputManager::InputManager(std::shared_ptr<Window> window)
    : _window(std::move(window))
{

}

int InputManager::GetGlfwKeyState(KeyCode code)
{
    auto ptr = const_cast<GLFWwindow*>(_window->GetGlfwWindowPointer());
    return glfwGetKey(ptr, KeyCodeToGlfwKeyCode(code));
}

int InputManager::KeyCodeToGlfwKeyCode(KeyCode code)
{
    switch(code) //bruh
    {
        case KeyCode::KEY_W:
            return GLFW_KEY_W;
        case KeyCode::KEY_A:
            return GLFW_KEY_A;
        case KeyCode::KEY_S:
            return GLFW_KEY_S;
        case KeyCode::KEY_D:
            return GLFW_KEY_D;
        case KeyCode::KEY_SPACE:
            return GLFW_KEY_SPACE;
    }

    throw std::invalid_argument("Cannot convert given key code to glfw key code");
}