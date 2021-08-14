#include "PhysicsSystem.h"

PhysicsSystem::PhysicsSystem()
: _world({0.0f, -9.8f})
{

}

void PhysicsSystem::Init(Scene& scene)
{

}

void PhysicsSystem::Update(Scene& scene)
{
    InitializeNewEntities(scene);

    SyncPropsBetweenSceneAndPhysicsWorld(scene);
}

int PhysicsSystem::GetPriority()
{
    return 9;
}

void PhysicsSystem::InitializeNewEntities(Scene& scene)
{
    auto notInitializedEntities =
            scene.GetEntities<PhysicsComponent>(Scene::ExcludeComponents<PhysicsBodyComponent>());

    for(auto& entity : notInitializedEntities)
    {
        auto pComp = entity.GetComponent<PhysicsComponent>();
        auto tComp = entity.GetComponent<TransformComponent>();

        Body::BodyParams params = {
            .position = tComp.position,
            .angle = tComp.angle,
            .mass = pComp.mass,
            .momentOfInertia = pComp.momentOfInertia,
            .friction = pComp.friction,
            .type = pComp.bodyType
        };

        auto body = _world.CreateBody(params);
        //FIXME: replace std::move to ptr
        //entity.AddComponent<PhysicsBodyComponent>(std::move(body));
    }
}

void PhysicsSystem::SyncPropsBetweenSceneAndPhysicsWorld(Scene& scene)
{

}
