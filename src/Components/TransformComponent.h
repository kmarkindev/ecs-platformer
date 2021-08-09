#pragma once

#include <glm/glm.hpp>
#include "Scene/IComponent.h"
#include <memory>

struct TransformComponent : public IComponent
{
    glm::vec2 position;
    glm::vec2 scale;
    float angle;

    TransformComponent(glm::vec2 position, glm::vec2 scale, float angle)
        : position(position), scale(scale), angle(angle)
    {
    }
};