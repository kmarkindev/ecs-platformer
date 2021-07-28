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
    [[nodiscard]] bool IsBinded() const;
    [[nodiscard]] int GetBindedBlockId() const;
    void Bind(int textureBlockId);
    void Unbind();


    Texture& operator = (Texture&& texture) noexcept;
    Texture& operator = (const Texture&) = delete;

private:
    GLuint _textureId;
    int _width;
    int _height;
    int _channels;
    int _bindedBlockId;
};


