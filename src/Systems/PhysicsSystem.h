#pragma once

#include "Scene/Scene.h"
#include "Physics/World.h"
#include "Components/PhysicsBodyComponent.h"
#include "Components/PhysicsComponent.h"
#include "Components/TransformComponent.h"
#include "Scene/SystemPriorities.h"
#include "Container/DependencyContainer.h"

class DependencyContainer;

class PhysicsSystem : public ISystem
{
public:
    PhysicsSystem();

    void Init(Scene& scene) override;

    void Update(Scene& scene) override;

    int GetPriority() override;

private:
    World _world;
    std::list<Body> _bodies;
    DependencyContainer* _container;
    float _physicsDeltaTime;

    void InitializeNewEntities(Scene& scene);

    void SyncPropsBetweenSceneAndPhysicsWorld(Scene& scene);

    void UpdateTransforms(std::vector<Entity>& entities);

    void UpdateParams(Entity& ent);

    void UpdatePhysicsTransforms(Entity& ent);

    void BindSceneEvents(Scene& scene);

    void UpdatePhysics();
};


