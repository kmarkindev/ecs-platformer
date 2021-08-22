#pragma once

#include "Components/TransformComponent.h"
#include "Components/PlayerComponent.h"
#include "Components/CameraComponent.h"
#include "Scene/Scene.h"
#include "Scene/ISystem.h"
#include "Container/DependencyContainer.h"

class CameraSystem : public ISystem
{
public:
    void Init(Scene& scene) override;

    void Update(Scene& scene) override;

private:
    float _physicsDeltaTime = 0.0f;
};


