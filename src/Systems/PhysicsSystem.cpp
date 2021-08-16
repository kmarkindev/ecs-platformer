#include "PhysicsSystem.h"

PhysicsSystem::PhysicsSystem()
    : _world({0.0f, -9.8f}),
    _container(DependencyContainer::GetInstance()),
    _physicsDeltaTime(0.0f)
{

}

void PhysicsSystem::Init(Scene& scene)
{
    BindSceneEvents(scene);

    _world.OnCollisionEnter([&](Body a, Body b)
    {
        scene.GetEventListener().RaiseEvent<CollisionEnter>(a, b);
    });

    _world.OnCollisionExit([&](Body a, Body b)
    {
        scene.GetEventListener().RaiseEvent<CollisionExit>(a, b);
    });
}

void PhysicsSystem::BindSceneEvents(Scene& scene)
{
    scene.OnUpdate<PhysicsComponent>([this](Scene& scene, Entity entity){
        if(entity.HasAllOfComponents<PhysicsBodyComponent, TransformComponent>())
            UpdateParams(entity);
    });

    scene.OnUpdate<TransformComponent>([this](Scene& scene, Entity entity){
        if(entity.HasAllOfComponents<PhysicsBodyComponent>())
            UpdatePhysicsTransforms(entity);
    });

    scene.OnDestroy<PhysicsBodyComponent>([](Scene& scene, Entity entity){
        entity.GetComponent<PhysicsBodyComponent>().body->DestroyBody();
    });
}

void PhysicsSystem::Update(Scene& scene)
{
    UpdatePhysics();

    InitializeNewEntities(scene);

    SyncPropsBetweenSceneAndPhysicsWorld(scene);
}

void PhysicsSystem::UpdatePhysics()
{
    _physicsDeltaTime += _container->_deltaTime->GetDeltaTime();
    constexpr float physicsTimestamp = 1.0f / 50.0f;

    if(_physicsDeltaTime >= physicsTimestamp)
    {
        _physicsDeltaTime = 0.0f;
        _world.Update(physicsTimestamp);
    }
}

int PhysicsSystem::GetPriority()
{
    return (int)SystemPriorities::PhysicsSystem;
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
}

void PhysicsSystem::UpdateParams(Entity& ent)
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

void PhysicsSystem::UpdateTransforms(std::vector<Entity>& entities)
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

void PhysicsSystem::UpdatePhysicsTransforms(Entity& ent)
{
    auto pbComp = ent.GetComponent<PhysicsBodyComponent>();
    auto tComp = ent.GetComponent<TransformComponent>();

    pbComp.body->SetAngle(tComp.angle);
    pbComp.body->SetPosition(tComp.position);
}
