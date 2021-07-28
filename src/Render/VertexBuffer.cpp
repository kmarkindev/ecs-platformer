#include "VertexArray.h"
#include "VertexBuffer.h"

VertexBuffer::VertexBuffer(std::shared_ptr<Renderer> renderer,
                           const std::vector<float>& data, std::vector<BufferParam> params)
                           : _bufferParams(std::move(params)),
                           _renderer(std::move(renderer)),
                           _vertexBufferId(0),
                           _dataSize(0)
{
    glGenBuffers(1, &_vertexBufferId);
    SetData(data, _bufferParams);
}

const std::vector<VertexBuffer::BufferParam>& VertexBuffer::GetBufferParams() const
{
    CheckBufferId();
    return _bufferParams;
}

void VertexBuffer::SetData(const std::vector<float>& data, const std::vector<BufferParam>& bufferParams)
{
    CheckBufferId();

    _bufferParams = bufferParams;

    Bind();

    int chunkSize = std::accumulate(bufferParams.begin(), bufferParams.end(), 0,
[](int sum, BufferParam param){
        return sum + param.size;
    });

    _dataSize = data.size() / chunkSize;
    glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), data.data(), GL_STATIC_DRAW);

    Unbind();
}

void VertexBuffer::Bind() const
{
    CheckBufferId();
    glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferId);
}

void VertexBuffer::Unbind() const
{
    CheckBufferId();
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

VertexBuffer::~VertexBuffer()
{
    if(_vertexBufferId > 0)
        glDeleteBuffers(1, &_vertexBufferId);
}

int VertexBuffer::GetDataSize() const
{
    CheckBufferId();

    return _dataSize;
}

VertexBuffer::VertexBuffer(VertexBuffer&& buffer) noexcept
    : _renderer(std::move(buffer._renderer)),
    _vertexBufferId(buffer._vertexBufferId),
    _dataSize(buffer._dataSize),
    _bufferParams(std::move(buffer._bufferParams))
{
    buffer._vertexBufferId = 0;
    buffer._dataSize = 0;
}

void VertexBuffer::CheckBufferId() const
{
    if(_vertexBufferId == 0)
        throw std::runtime_error("Trying to use deleted/moved VBO.");
}

bool VertexBuffer::operator==(const VertexBuffer& rhs) const
{
    return _vertexBufferId == rhs._vertexBufferId;
}

bool VertexBuffer::operator!=(const VertexBuffer& rhs) const
{
    return !(rhs == *this);
}
