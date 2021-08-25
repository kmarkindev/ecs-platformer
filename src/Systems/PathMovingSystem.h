#pragma once

#include "Scene/Scene.h"
#include "Components/TransformComponent.h"
#include "Components/PathComponent.h"
#include "Container/DependencyContainer.h"

class PathMovingSystem : public ISystem
{
public:
    void Init(Scene& scene) override;

    void Update(Scene& scene) override;
};


