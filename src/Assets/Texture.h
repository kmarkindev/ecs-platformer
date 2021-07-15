#pragma once

#include <glad/glad.h>

class Texture
{
public:
    explicit Texture(GLuint textureId);
    ~Texture();
    [[nodiscard]] GLuint GetTextureId() const;
private:
    GLuint _textureId;
};


