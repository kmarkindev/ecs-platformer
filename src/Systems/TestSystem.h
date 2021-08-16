#pragma once

#include "Scene/ISystem.h"
#include "Scene/Events/CollisionEnter.h"
#include "Container/DependencyContainer.h"

class TestSystem : public ISystem
{
public:
    void Init(Scene& scene) override;

    void Update(Scene& scene) override;
};


