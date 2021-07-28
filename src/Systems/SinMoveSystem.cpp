#include "SinMoveSystem.h"

void SinMoveSystem::Init(Scene& scene)
{

}

void SinMoveSystem::Update(Scene& scene)
{
    auto objs = scene.GetEntities<TransformComponent, SpriteComponent>();

    //Systems should not have stored data. I need it only for testing purposes.
    static float offset = 0.0f;
    offset += 0.001f;
    float offsetForLambda = offset;

    for(auto& obj : objs)
    {
        obj.PatchComponent<TransformComponent>([offsetForLambda](auto& transform){
            transform.position.x = glm::sin(offsetForLambda);
        });
    }
}

int SinMoveSystem::GetPriority()
{
    return 1;
}
