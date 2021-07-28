#include "Texture.h"

Texture::Texture(GLuint textureId, int width, int height, int channels)
    : _textureId(textureId),
    _width(width),
    _height(height),
    _channels(channels)
{

}

Texture::~Texture()
{
    if(_textureId != 0)
        glDeleteTextures(1, &_textureId);
}

GLuint Texture::GetTextureId() const
{
    return _textureId;
}

Texture::Texture(Texture&& texture) noexcept
    : _textureId(texture._textureId),
    _height(texture._height),
    _width(texture._width),
    _channels(texture._channels)
{
    texture._textureId = 0;
    texture._channels = 0;
    texture._width = 0;
    texture._height = 0;
}

Texture& Texture::operator=(Texture&& texture) noexcept
{
    _textureId = texture._textureId;
    _height = texture._height;
    _width = texture._width;
    _channels = texture._channels;

    texture._textureId = 0;
    texture._channels = 0;
    texture._width = 0;
    texture._height = 0;

    return *this;
}

void Texture::Bind(int textureBlockId)
{
    _bindedBlockId = textureBlockId;
    glActiveTexture(GL_TEXTURE0 + textureBlockId);
    glBindTexture(GL_TEXTURE_2D, _textureId);
}

void Texture::Unbind()
{
    glActiveTexture(GL_TEXTURE0 + _bindedBlockId);
    glBindTexture(GL_TEXTURE_2D, _textureId);
    _bindedBlockId = -1;
}

bool Texture::IsBinded() const
{
    return _bindedBlockId > -1;
}

int Texture::GetBindedBlockId() const
{
    return _bindedBlockId;
}
