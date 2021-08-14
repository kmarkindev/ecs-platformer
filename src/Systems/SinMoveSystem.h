#pragma once

#include "Scene/ISystem.h"
#include "Container/DependencyContainer.h"
#include "Components/TransformComponent.h"
#include "Components/CameraComponent.h"
#include "Components/SpriteComponent.h"

class DependencyContainer;

class SinMoveSystem : public ISystem
{
public:
    explicit SinMoveSystem();

    void Init(Scene& scene) override;

    void Update(Scene& scene) override;

    int GetPriority() override;

private:
    DependencyContainer* _container;
    float _offset;
};


