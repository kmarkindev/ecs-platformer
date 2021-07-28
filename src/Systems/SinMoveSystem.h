#pragma once

#include "Scene/ISystem.h"
#include "Components/TransformComponent.h"
#include "Components/CameraComponent.h"
#include "Components/SpriteComponent.h"

class SinMoveSystem : public ISystem
{
public:
    void Init(Scene& scene) override;

    void Update(Scene& scene) override;

    int GetPriority() override;

};


