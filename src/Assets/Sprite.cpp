#include "Sprite.h"

Sprite::Sprite(Texture* texture)
    : _texture(texture),
    _shader(nullptr),
    _offset({0,0}),
    _size({1,1})
{

}

const glm::vec2& Sprite::GetSize() const
{
    return _size;
}

void Sprite::SetSize(const glm::vec2& size)
{
    assert(size.x >= 0 && size.y >= 0);

    _size = size;
}

Texture* Sprite::GetTexture() const
{
    return _texture;
}

void Sprite::SetTexture(Texture* texture)
{
    _texture = texture;
}

const glm::vec2& Sprite::GetOffset() const
{
    return _offset;
}

void Sprite::SetOffset(const glm::vec2& offset)
{
    _offset = offset;
}

const std::shared_ptr<IShader>& Sprite::GetShader() const
{
    return _shader;
}

void Sprite::SetShader(const std::shared_ptr<IShader>& shader)
{
    _shader = shader;
}
