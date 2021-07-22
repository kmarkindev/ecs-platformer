#include "TestSystem.h"

void TestSystem::Init(Scene& scene)
{

}

void TestSystem::Update(Scene& scene)
{
    for(auto& entity : scene.GetEntities<TransformComponent>())
    {
        entity.PatchComponent<TransformComponent>([&](auto& transform){
            transform.position += glm::vec3(0, -1, 0);
        });
    }
}
