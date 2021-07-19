#pragma once

#include <glm/glm.hpp>
#include "Scene/IComponent.h"
#include <memory>

struct TransformComponent : public IComponent
{
    glm::vec3 position;
    glm::vec3 scale;
    glm::quat rotation;

    std::weak_ptr<TransformComponent> parent;

    TransformComponent(glm::vec3 position, glm::vec3 scale, glm::vec3 rotation, TransformComponent* parent)
        : position(position), scale(scale), rotation(rotation), parent(parent)
    {
    }
};