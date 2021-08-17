#include "AssetsCache.h"

AssetsCache::AssetsCache(const std::shared_ptr<AssetsManager>& assetsManager,
                         const std::shared_ptr<OpenGlTextureLoader>& textureLoader)
    : _ground(textureLoader->LoadTexture(assetsManager->GetAssetData("textures/ground.png"))),
    _ground_grass(textureLoader->LoadTexture(assetsManager->GetAssetData("textures/ground_grass.png"))),
    _door(textureLoader->LoadTexture(assetsManager->GetAssetData("textures/door.png"))),
    _grass(textureLoader->LoadTexture(assetsManager->GetAssetData("textures/grass.png"))),
    _spike(textureLoader->LoadTexture(assetsManager->GetAssetData("textures/spike.png")))
{

}
