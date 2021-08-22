#include "CameraSystem.h"

void CameraSystem::Init(Scene& scene)
{

}

void CameraSystem::Update(Scene& scene)
{
    //Update camera pos only when we are updating physics
    //(works only when physics system and camera system started updating at the same time)
    auto deltaTime = DependencyContainer::GetInstance()->_deltaTime->GetDeltaTime();

    _physicsDeltaTime += deltaTime;
    constexpr float physicsTimestamp = 1.0f / 50.0f;

    if(_physicsDeltaTime < physicsTimestamp)
        return;

    _physicsDeltaTime = 0.0f;


    auto player = scene.GetEntities<TransformComponent, PlayerComponent>().front();
    auto camera = scene.GetEntities<TransformComponent, CameraComponent>().front();

    auto playerPos = player.GetComponent<TransformComponent>().position;
    auto cameraPos = camera.GetComponent<TransformComponent>().position;

    camera.PatchComponent<TransformComponent>([&playerPos, &cameraPos](auto& tComp)
    {
        tComp.position = glm::mix(cameraPos, playerPos + glm::vec2(0, 1), 0.125f);
    });
}
