#include "SpriteRenderSystem.h"

void SpriteRenderSystem::Init(Scene& scene)
{

}

void SpriteRenderSystem::Update(Scene& scene)
{
    auto camera = scene.GetEntities<CameraComponent, TransformComponent>().front();
    auto sprites = scene.GetEntities<SpriteComponent, TransformComponent>();

    auto cameraMatrix = GetCameraMatrix(camera.GetComponent<TransformComponent>().position, 0);
    auto projectionMatrix = GetOthroProjectionMatrix(
            _container->_window->GetWindowSize(), camera.GetComponent<CameraComponent>().zoom);

    auto cameraProjectionMatrix = projectionMatrix * cameraMatrix;

    for(auto& sprite : sprites)
    {
        auto spriteObjPtr = sprite.GetComponent<SpriteComponent>().sprite;

        if(!spriteObjPtr)
            continue;

        auto transform = sprite.GetComponent<TransformComponent>();

        auto transformMatrix = cameraProjectionMatrix
                * GetModelMatrix(transform.position, transform.scale, transform.angle);

        _container->_spriteRenderer->RenderSprite({
            .sprite = *spriteObjPtr,
            .transformMatrix = transformMatrix
        });
    }
}

SpriteRenderSystem::SpriteRenderSystem()
    : _container(DependencyContainer::GetInstance())
{

}

int SpriteRenderSystem::GetPriority()
{
    return 0;
}
