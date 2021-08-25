#pragma once

#include <glm/glm.hpp>

struct PathComponent
{
    glm::vec2 startPos;
    glm::vec2 endPos;
    float progress = 0.0;
    bool movingForward = true;
};