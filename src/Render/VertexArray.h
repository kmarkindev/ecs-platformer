#pragma once

#include <memory>
#include <glad/glad.h>
#include "Renderer.h"
#include "VertexBuffer.h"

class Renderer;
class VertexBuffer;

class VertexArray
{
public:
    explicit VertexArray(std::shared_ptr<Renderer> renderer, VertexBuffer& buffer);
    VertexArray(const VertexArray&) = delete;
    VertexArray(VertexArray&& buffer) noexcept;
    ~VertexArray();
    void AssignVertexBuffer(VertexBuffer& vertexBuffer);
    void Bind() const;
    void Unbind() const;
    [[nodiscard]] const VertexBuffer& GetBindedVertexBuffer() const;

private:
    VertexBuffer _bindedVertexBuffer;
    std::shared_ptr<Renderer> _renderer;
    GLuint _vertexArrayId;

    void CheckBufferId() const;
};


