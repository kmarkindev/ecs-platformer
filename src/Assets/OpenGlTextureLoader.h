#pragma once

#include <glad/glad.h>
#include "Texture.h"
#include <vector>
#include <stb/stb_image.h>
#include <stdexcept>

class OpenGlTextureLoader
{
public:
    OpenGlTextureLoader();
    [[nodiscard]] Texture LoadTexture(const std::vector<unsigned char>& data) const;
};


