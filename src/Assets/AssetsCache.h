#pragma once

#include "Sprite.h"
#include "OpenGlTextureLoader.h"
#include "AssetsManager.h"

class AssetsCache
{
public:

    AssetsCache(const std::shared_ptr<AssetsManager>& assetsManager,
                const std::shared_ptr<OpenGlTextureLoader>& textureLoader);

    /* Textures */
    Texture _groundTexture;
    Texture _groundGrassTexture;
    Texture _doorTexture;
    Texture _grassTexture;
    Texture _spikeTexture;
    Texture _playerTexture;

    /* Sprites */
    Sprite _groundSprite;
    Sprite _groundGrassSprite;
    Sprite _doorSprite;
    Sprite _grassSprite;
    Sprite _spikeSprite;
    Sprite _playerSprite;

};


