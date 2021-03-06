#include "SpriteRenderSystem.h"

void SpriteRenderSystem::Init(Scene& scene)
{

}

void SpriteRenderSystem::Update(Scene& scene)
{
    auto camera = scene.GetEntities<CameraComponent, TransformComponent>().front();
    auto sprites = scene.GetEntities<SpriteComponent, TransformComponent>();

    auto cameraMatrix = GetCameraMatrix(camera.GetComponent<TransformComponent>().position,
                                        camera.GetComponent<TransformComponent>().angle);

    auto projectionMatrix = GetOthroProjectionMatrix(
            _container->_window->GetWindowSize(), camera.GetComponent<CameraComponent>().zoom);

    auto cameraProjectionMatrix = projectionMatrix * cameraMatrix;

    std::sort(sprites.begin(), sprites.end(),
        [](const auto& a, const auto& b)
    {
        auto aSpriteComp = a.template GetComponent<SpriteComponent>();
        auto bSpriteComp = b.template GetComponent<SpriteComponent>();

        return aSpriteComp.renderingLayer > bSpriteComp.renderingLayer;
    });

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
    return (int)SystemPriorities::SpriteRenderSystem;
}
