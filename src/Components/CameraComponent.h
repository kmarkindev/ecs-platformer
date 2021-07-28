#pragma once

#include "Scene/IComponent.h"

struct CameraComponent : public IComponent
{
    float zoom;

    explicit CameraComponent(float zoom)
        : zoom(zoom)
    {

    }
};