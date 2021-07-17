#include "TextureLoader.h"

TextureLoader::TextureLoader()
{

}

Texture TextureLoader::loadTexture(const std::vector<unsigned char>& data)
{
    int x, y, n;
    auto bitmap = stbi_load_from_memory(data.data(), (int)data.size(), &x, &y, &n, 0);

    if(!bitmap)
        throw std::invalid_argument("Cannot load image from given data");

    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    if(n < 3)
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, x, y, 0, GL_RGB, GL_UNSIGNED_BYTE, bitmap);
    else
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, x, y, 0, GL_RGBA, GL_UNSIGNED_BYTE, bitmap);

    glGenerateMipmap(GL_TEXTURE_2D);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, 0);

    stbi_image_free(bitmap);

    return Texture(texture, x, y, n);
}
