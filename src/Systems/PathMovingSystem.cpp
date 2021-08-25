#include "PathMovingSystem.h"

void PathMovingSystem::Init(Scene& scene)
{

}

void PathMovingSystem::Update(Scene& scene)
{
    auto deltaTime = DependencyContainer::GetInstance()->_deltaTime->GetDeltaTime();
    auto entities = scene.GetEntities<TransformComponent, PathComponent>();

    for(auto& ent : entities)
    {
        auto pthComp = ent.GetComponent<PathComponent>();

        ent.PatchComponent<TransformComponent>([&pthComp, deltaTime](auto& transform)
        {
            auto moveForward = pthComp.movingForward;

            pthComp.progress += deltaTime;

            if(pthComp.progress < 1.0f)
            {
                auto startPos = moveForward ? pthComp.startPos : pthComp.endPos;
                auto endPos = moveForward ? pthComp.endPos : pthComp.startPos;

                auto pos = glm::mix(startPos, endPos, pthComp.progress);
                transform.position = pos;
            }
            else
            {
                pthComp.progress = 0.0;
                pthComp.movingForward = !pthComp.movingForward;
            }
        });

        ent.ReplaceComponent<PathComponent>(
                pthComp.startPos, pthComp.endPos, pthComp.progress, pthComp.movingForward);
    }
}
