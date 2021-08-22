#pragma once

#include "Scene/Scene.h"
#include "Components/PhysicsComponent.h"
#include "Container/DependencyContainer.h"
#include "Components/PlayerComponent.h"
#include "Components/TransformComponent.h"

class PlayerSystem : public ISystem
{
public:
    explicit PlayerSystem();

    void Init(Scene& scene) override;

    void Update(Scene& scene) override;

private:

    DependencyContainer* _container;

};
