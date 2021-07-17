#pragma once

#include <glad/glad.h>

class Texture
{
public:
    explicit Texture(GLuint textureId, int width, int height, int channels);
    ~Texture();
    [[nodiscard]] GLuint GetTextureId() const;
private:
    GLuint _textureId;
    int _width;
    int _height;
    int _channels;
};


