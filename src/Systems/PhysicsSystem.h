#pragma once

#include "Scene/Scene.h"

class PhysicsSystem : public ISystem
{
public:
    void Init(Scene& scene) override;

    void Update(Scene& scene) override;

    int GetPriority() override;
};


