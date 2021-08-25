#include "Renderer.h"

Renderer::Renderer(std::shared_ptr<Window> window)
    : _window(std::move(window))
{
    gladLoadGL();

    glClearColor(178.0f / 255.0f, 1, 1, 1);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

#if DEBUG_BUILD
    glEnable(GL_DEBUG_OUTPUT);
    glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);

    auto handler = [](
            GLenum source, GLenum type, GLuint id, GLenum severity,
            GLsizei length, const GLchar *message, const void *userParam)
    {
        if(severity != GL_DEBUG_SEVERITY_NOTIFICATION)
            throw std::runtime_error(message);
    };

    glDebugMessageCallback(handler, nullptr);

    glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, nullptr, GL_TRUE);
#endif
}

void Renderer::StartRender()
{
    auto windowSize = _window->GetWindowSize();
    glViewport(0, 0, windowSize[0], windowSize[1]);

    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::EndRender()
{

}

void Renderer::DrawArrays(const VertexArray& vertexArray)
{
    vertexArray.Bind();
    glDrawArrays(GL_TRIANGLES, 0, vertexArray.GetBindedVertexBuffer().GetDataSize());
    vertexArray.Unbind();
}

