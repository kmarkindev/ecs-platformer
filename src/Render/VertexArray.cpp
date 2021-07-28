#include "VertexArray.h"

void VertexArray::Bind() const
{
    CheckBufferId();
    glBindVertexArray(_vertexArrayId);
}

void VertexArray::Unbind() const
{
    CheckBufferId();
    glBindVertexArray(0);
}

VertexArray::VertexArray(std::shared_ptr<Renderer> renderer, VertexBuffer& buffer)
    : _renderer(std::move(renderer)),
    _vertexArrayId(0),
    _bindedVertexBuffer(std::move(buffer))
{
    glGenVertexArrays(1, &_vertexArrayId);
    AssignVertexBuffer(_bindedVertexBuffer);
}

void VertexArray::AssignVertexBuffer(VertexBuffer& vertexBuffer)
{
    CheckBufferId();

    if(vertexBuffer != _bindedVertexBuffer)
        _bindedVertexBuffer = std::move(vertexBuffer);

    auto& params = _bindedVertexBuffer.GetBufferParams();

    Bind();
    _bindedVertexBuffer.Bind();

    for(int i = 0; i < params.size(); ++i)
    {
        auto& param = params[i];

        glEnableVertexAttribArray(i);

        glVertexAttribPointer(i, param.size, GL_FLOAT,
                              param.normalized ? GL_TRUE : GL_FALSE,
                              param.stride * sizeof(float), (void*)(param.offset * sizeof(float)));
    }

    Unbind();
    _bindedVertexBuffer.Unbind();
}

VertexArray::~VertexArray()
{
    if(_vertexArrayId > 0)
        glDeleteVertexArrays(1, &_vertexArrayId);
}

const VertexBuffer& VertexArray::GetBindedVertexBuffer() const
{
    CheckBufferId();
    return _bindedVertexBuffer;
}

VertexArray::VertexArray(VertexArray&& buffer) noexcept
    : _renderer(std::move(buffer._renderer)),
    _vertexArrayId(buffer._vertexArrayId),
    _bindedVertexBuffer(std::move(buffer._bindedVertexBuffer))
{
    buffer._vertexArrayId = 0;
}

void VertexArray::CheckBufferId() const
{
    if(_vertexArrayId == 0)
        throw std::runtime_error("Trying to use deleted/moved VAO.");
}
