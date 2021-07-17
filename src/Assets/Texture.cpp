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
    glDeleteTextures(1, &_textureId);
}

GLuint Texture::GetTextureId() const
{
    return _textureId;
}
