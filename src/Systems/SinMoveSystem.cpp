#include "SinMoveSystem.h"

void SinMoveSystem::Init(Scene& scene)
{

}

void SinMoveSystem::Update(Scene& scene)
{
    auto objs = scene.GetEntities<TransformComponent, SpriteComponent>();

    _offset += _container->_deltaTime->GetDeltaTime();

    for(auto& obj : objs)
    {
        obj.PatchComponent<TransformComponent>([this](auto& transform){
            transform.position.x = glm::sin(_offset);
        });
    }
}

int SinMoveSystem::GetPriority()
{
    return 1;
}

SinMoveSystem::SinMoveSystem()
    : _container(DependencyContainer::GetInstance()),
    _offset(0.0f)
{

}
