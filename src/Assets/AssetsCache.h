#pragma once

#include "Sprite.h"
#include "OpenGlTextureLoader.h"
#include "AssetsManager.h"

class AssetsCache
{
public:

    AssetsCache(const std::shared_ptr<AssetsManager>& assetsManager,
                const std::shared_ptr<OpenGlTextureLoader>& textureLoader);

    Texture _ground;
    Texture _ground_grass;
    Texture _door;
    Texture _grass;
    Texture _spike;

};


