#pragma once

#include "Physics/Body.h"

struct PhysicsComponent
{
    float mass = 1.0f;
    float momentOfInertia = 0.2f;
    float friction = 0.2f;
    Body::BodyType bodyType = Body::BodyType::Dynamic;
    glm::vec2 collisionBoxSize = {1.0f, 1.0f};
    float angularVelocity = 0.0f;
    glm::vec2 linearVelocity = {0.0f, 0.0f};
    bool fixedRotation = false;
};