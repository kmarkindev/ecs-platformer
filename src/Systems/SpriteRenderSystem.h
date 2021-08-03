#pragma once

#include "Scene/ISystem.h"
#include "Components/TransformComponent.h"
#include "Components/CameraComponent.h"
#include "Components/SpriteComponent.h"
#include "Math/Transform.h"
#include "Container/DependencyContainer.h"

class DependencyContainer;

class SpriteRenderSystem : public ISystem
{
public:
    SpriteRenderSystem();

    void Init(Scene& scene) override;
    int GetPriority() override;
    void Update(Scene& scene) override;

private:
    DependencyContainer* _container;
};


