#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include "Scene/IComponent.h"
#include <memory>

struct TransformComponent : public IComponent
{
    glm::vec3 position;
    glm::vec3 scale;
    glm::quat rotation;

    TransformComponent* parent;

    TransformComponent(glm::vec3 position, glm::vec3 scale, glm::quat rotation, TransformComponent* parent = nullptr)
        : position(position), scale(scale), rotation(rotation), parent(parent)
    {
    }
};