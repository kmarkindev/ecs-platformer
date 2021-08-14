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
    _world.Update();

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
            scene.GetEntities<PhysicsComponent,
                TransformComponent>(Scene::ExcludeComponents<PhysicsBodyComponent>());

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
            .type = pComp.bodyType,
            .boxSize = pComp.collisionBoxSize * tComp.scale
        };

        auto body = _world.CreateBody(params);
        _bodies.push_front(std::move(body));

        entity.AddComponent<PhysicsBodyComponent>(&_bodies.front());
    }
}

void PhysicsSystem::SyncPropsBetweenSceneAndPhysicsWorld(Scene& scene)
{
    auto entities = scene.GetEntities<PhysicsComponent,
        PhysicsBodyComponent, TransformComponent>();

    UpdateTransforms(entities);

    //TODO: Call it only when smth is changed in PhysicsComponent
    //UpdateParams(entities);
}

void PhysicsSystem::UpdateParams(std::vector<Entity>& entities) const
{
    for(auto& ent : entities)
    {
        auto pComp = ent.GetComponent<PhysicsComponent>();
        auto pbComp = ent.GetComponent<PhysicsBodyComponent>();
        auto tComp = ent.GetComponent<TransformComponent>();

        Body::BodyParams params = {
            .mass = pComp.mass,
            .momentOfInertia = pComp.momentOfInertia,
            .friction = pComp.friction,
            .type = pComp.bodyType,
            .boxSize = pComp.collisionBoxSize * tComp.scale
        };

        pbComp.body->UpdateParams(params);
    }
}

void PhysicsSystem::UpdateTransforms(std::vector<Entity>& entities) const
{
    for(auto& ent : entities)
    {
        auto pbComp = ent.GetComponent<PhysicsBodyComponent>();

        ent.PatchComponent<TransformComponent>([&pbComp](auto& tComp){
            tComp.position = pbComp.body->GetPosition();
            tComp.angle = pbComp.body->GetAngle();
        });
    }
}