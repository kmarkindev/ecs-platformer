#pragma once

#include "Physics/Body.h"

struct PhysicsComponent
{
    float mass;
    float momentOfInertia;
    float friction;
    Body::BodyType bodyType;
    glm::vec2 collisionBoxSize;
    float angularVelocity = 0.0f;
    glm::vec2 linearVelocity = {0.0f, 0.0f};
};