#pragma once

#include "Physics/Body.h"

struct PhysicsComponent
{
    float mass;
    float momentOfInertia;
    float friction;
    Body::BodyType bodyType;
    glm::vec2 collisionBoxSize;
};