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
    : _a(bodyA), _b(bodyB)
{

}
