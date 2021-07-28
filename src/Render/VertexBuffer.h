#pragma once

#include "Renderer.h"
#include <memory>
#include <glad/glad.h>
#include <vector>
#include <numeric>

class Renderer;

class VertexBuffer
{
public:

    struct BufferParam
    {
        int size;
        bool normalized;
        int stride;
        int offset;
    };

public:
    explicit VertexBuffer(std::shared_ptr<Renderer> renderer,
                          const std::vector<float>& data, std::vector<BufferParam> params);
    VertexBuffer(const VertexBuffer&) = delete;
    VertexBuffer(VertexBuffer&& buffer) noexcept;
    VertexBuffer& operator = (const VertexBuffer&) = delete;
    VertexBuffer& operator = (VertexBuffer&&) = default;

    bool operator==(const VertexBuffer& rhs) const;

    bool operator!=(const VertexBuffer& rhs) const;

    ~VertexBuffer();
    [[nodiscard]] const std::vector<BufferParam>& GetBufferParams() const;
    void SetData(const std::vector<float>& data, const std::vector<BufferParam>& bufferParams);
    void Bind() const;
    void Unbind() const;
    [[nodiscard]] int GetDataSize() const;

private:
    std::shared_ptr<Renderer> _renderer;
    GLuint _vertexBufferId;
    int _dataSize;
    std::vector<BufferParam> _bufferParams;

    void CheckBufferId() const;
};


