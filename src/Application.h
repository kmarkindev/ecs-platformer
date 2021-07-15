#pragma once

#include "Window/Window.h"

class Application
{
public:
    explicit Application();
    bool Update();
private:
    Window _window;
};


