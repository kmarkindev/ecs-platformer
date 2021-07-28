#pragma once

#include <memory>
#include <glad/glad.h>
#include <stdexcept>
#include "VertexArray.h"
#include "Window/Window.h"

class VertexArray;

class Renderer
{
public:
    explicit Renderer(std::shared_ptr<Window> window);

    void StartRender();
    void EndRender();

    void DrawArrays(const VertexArray& vertexArray);

private:
    std::shared_ptr<Window> _window;
};


