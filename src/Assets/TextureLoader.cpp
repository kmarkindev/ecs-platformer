#include "TextureLoader.h"

TextureLoader::TextureLoader()
{

}

Texture TextureLoader::loadTexture(const std::ifstream& ifstream)
{
    return loadTexture(ifstream, std::ios::beg, std::ios::end);
}

Texture TextureLoader::loadTexture(const std::ifstream& ifstream, const std::streampos start, const std::streampos end)
{
    return Texture(0);
}
