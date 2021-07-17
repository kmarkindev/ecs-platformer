#pragma once

#include <glad/glad.h>
#include "Texture.h"
#include <vector>
#include <stb/stb_image.h>
#include <stdexcept>

class TextureLoader
{
public:
    TextureLoader();
    Texture loadTexture(const std::vector<unsigned char>& data);
};


