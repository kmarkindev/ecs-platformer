#pragma once

#include <glad/glad.h>

class Texture
{
public:
    explicit Texture(GLuint textureId, int width, int height, int channels);
    Texture(Texture&& texture) noexcept;
    Texture(const Texture& texture) = delete;
    ~Texture();
    [[nodiscard]] GLuint GetTextureId() const;

    Texture& operator = (Texture&& texture) noexcept;
    Texture& operator = (const Texture& texture) = delete;

private:
    GLuint _textureId;
    int _width;
    int _height;
    int _channels;
};


