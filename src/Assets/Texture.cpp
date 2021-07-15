#include "Texture.h"

Texture::Texture(GLuint textureId)
    : _textureId(textureId)
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
