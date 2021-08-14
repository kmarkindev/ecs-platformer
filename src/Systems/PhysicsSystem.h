#pragma once

#include "Scene/Scene.h"
#include "Physics/World.h"
#include "Components/PhysicsBodyComponent.h"
#include "Components/PhysicsComponent.h"
#include "Components/TransformComponent.h"

class PhysicsSystem : public ISystem
{
public:
    PhysicsSystem();

    void Init(Scene& scene) override;

    void Update(Scene& scene) override;

    int GetPriority() override;

private:
    World _world;

    void InitializeNewEntities(Scene& scene);
    void SyncPropsBetweenSceneAndPhysicsWorld(Scene& scene);
};


