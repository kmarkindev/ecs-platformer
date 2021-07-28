#pragma once

#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>
#include "Scene/IComponent.h"
#include <memory>

struct TransformComponent : public IComponent
{
    glm::vec2 position;
    glm::vec2 scale;
    glm::quat rotation;

    TransformComponent(glm::vec2 position, glm::vec2 scale, glm::quat rotation)
        : position(position), scale(scale), rotation(rotation)
    {
    }
};