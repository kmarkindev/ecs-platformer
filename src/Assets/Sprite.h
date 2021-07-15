#pragma once

#include "Texture.h"

class Sprite
{
public:
    explicit Sprite(const Texture& texture);

private:
    Texture _texture;
};


