#pragma once

#include <box2d/b2_world.h>
#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>
#include <memory>
#include "Body.h"
#include <stdexcept>

class World
{
friend class Body;
public:
    explicit World(glm::vec2 gravity);

    Body CreateBody(const Body::BodyParams& params);

    void Update();

private:
    b2World _world;
};