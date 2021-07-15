#pragma once

#include "Texture.h"
#include <fstream>

class TextureLoader
{
public:
    TextureLoader();
    Texture loadTexture(const std::ifstream& ifstream);
    Texture loadTexture(const std::ifstream& ifstream, std::streampos start, std::streampos end);
};


