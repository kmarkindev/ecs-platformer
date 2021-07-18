#pragma once

#include "Window/Window.h"
#include "KeyCode.h"

class InputManager
{
public:
    InputManager(std::shared_ptr<Window> window);

    bool KeyPressed(KeyCode code);
    bool KeyReleased(KeyCode code);

private:
    std::shared_ptr<Window> _window;

    int KeyCodeToGlfwKeyCode(KeyCode code);
    int GetGlfwKeyState(KeyCode code);
};


