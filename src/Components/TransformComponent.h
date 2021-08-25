#pragma once

#include <glm/glm.hpp>
#include <memory>

struct TransformComponent
{
    glm::vec2 position = {0.0f, 0.0f};
    glm::vec2 scale = {1.0f, 1.0f};
    float angle = 0.0f;
};