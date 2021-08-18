#include "AssetsCache.h"

AssetsCache::AssetsCache(const std::shared_ptr<AssetsManager>& assetsManager,
                         const std::shared_ptr<OpenGlTextureLoader>& textureLoader)
    : _groundTexture(textureLoader->LoadTexture(assetsManager->GetAssetData("textures/ground.png"))),
      _groundGrassTexture(textureLoader->LoadTexture(assetsManager->GetAssetData("textures/ground_grass.png"))),
      _doorTexture(textureLoader->LoadTexture(assetsManager->GetAssetData("textures/door.png"))),
      _grassTexture(textureLoader->LoadTexture(assetsManager->GetAssetData("textures/grass.png"))),
      _spikeTexture(textureLoader->LoadTexture(assetsManager->GetAssetData("textures/spike.png"))),

      _groundSprite(&_groundTexture),
      _groundGrassSprite(&_groundGrassTexture),
      _doorSprite(&_doorTexture),
      _grassSprite(&_grassTexture),
      _spikeSprite(&_spikeTexture)
{

}
