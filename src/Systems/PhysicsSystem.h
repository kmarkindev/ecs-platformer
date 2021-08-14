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
    std::list<Body> _bodies;

    void InitializeNewEntities(Scene& scene);

    void SyncPropsBetweenSceneAndPhysicsWorld(Scene& scene);

    void UpdateTransforms(std::vector<Entity>& entities) const;

    void UpdateParams(std::vector<Entity>& entities) const;
};


