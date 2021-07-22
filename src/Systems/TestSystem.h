#pragma once

#include "Scene/ISystem.h"
#include "Components/TransformComponent.h"
#include <glm/glm.hpp>

class TestSystem : public ISystem
{
public:
    void Init(Scene& scene) override;

    void Update(Scene& scene) override;
};

