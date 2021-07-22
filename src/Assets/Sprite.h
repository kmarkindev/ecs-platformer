#pragma once

#include <algorithm>
#include "Texture.h"

class Sprite
{
public:
    explicit Sprite(Texture&& texture);

private:
    Texture _texture;
};


