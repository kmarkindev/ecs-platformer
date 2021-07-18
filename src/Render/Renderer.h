#pragma once

#include <memory>
#include <glad/glad.h>
#include "Window/Window.h"

class Renderer
{
public:
    explicit Renderer(std::shared_ptr<Window> window);
    void Render();

private:
    std::shared_ptr<Window> _window;
};


