#include "TestSystem.h"

void TestSystem::Init(Scene& scene)
{

}

void TestSystem::Update(Scene& scene)
{
    for(auto& entity : scene.GetEntities<TransformComponent>())
    {
        auto transformComponent = entity.GetComponent<TransformComponent>();
        transformComponent.position += glm::vec3(0, -1, 0);
        entity.ReplaceComponent<TransformComponent>(
                transformComponent.position,
                transformComponent.scale,
                transformComponent.rotation,
                transformComponent.parent);
    }
}
