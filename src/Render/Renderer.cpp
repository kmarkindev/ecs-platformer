#include "Renderer.h"

Renderer::Renderer(std::shared_ptr<Window> window)
    : _window(std::move(window))
{
    gladLoadGL();
}

void Renderer::Render()
{
    auto windowSize = _window->GetWindowSize();
    glViewport(0, 0, windowSize[0], windowSize[1]);


}

