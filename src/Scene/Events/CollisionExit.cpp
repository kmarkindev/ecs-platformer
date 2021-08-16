#include "CollisionExit.h"

CollisionExit::CollisionExit(Body& bodyA, Body& bodyB)
    : _a(std::move(bodyA)), _b(std::move(bodyB))
{

}

const Body& CollisionExit::GetA() const
{
    return _a;
}

const Body& CollisionExit::GetB() const
{
    return _b;
}
