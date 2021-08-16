#include "CollisionEnter.h"

const Body& CollisionEnter::GetA() const
{
    return _a;
}

const Body& CollisionEnter::GetB() const
{
    return _b;
}

CollisionEnter::CollisionEnter(Body& bodyA, Body& bodyB)
    : _a(std::move(bodyA)), _b(std::move(bodyB))
{

}
