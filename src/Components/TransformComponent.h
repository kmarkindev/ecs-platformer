#pragma once

#include <glm/glm.hpp>
#include <memory>

struct TransformComponent
{
    glm::vec2 position;
    glm::vec2 scale;
    float angle;
};