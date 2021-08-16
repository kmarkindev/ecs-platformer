#pragma once

#include "Physics/Body.h"

class CollisionExit
{
public:
    CollisionExit(Body& bodyA, Body& bodyB);

    [[nodiscard]] const Body& GetA() const;

    [[nodiscard]] const Body& GetB() const;

private:

    Body _a;
    Body _b;

};


