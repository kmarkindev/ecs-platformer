#include "World.h"

World::World(glm::vec2 gravity)
    : _world(b2Vec2(gravity.x, gravity.y)),
      _collisionListener(_world)
{

}

Body World::CreateBody(const Body::BodyParams& params)
{
    return Body(_world, params);
}

void World::Update()
{
    _world.Step(1 / 60.0f, 8, 3);
}

void World::OnCollisionEnter(const CollisionCallback& callback)
{
    _collisionListener
        ._collisionEnterCallbacks
        .push_front(callback);
}

void World::OnCollisionExit(const CollisionCallback& callback)
{
    _collisionListener
        ._collisionExitCallbacks
        .push_front(callback);
}

void World::Box2DCollisionListener::BeginContact(b2Contact* contact)
{
    auto bodyA = Body(_world, contact->GetFixtureA()->GetBody());
    auto bodyB = Body(_world, contact->GetFixtureB()->GetBody());

    for(auto& callback : _collisionEnterCallbacks)
        callback(bodyA, bodyB);
}

void World::Box2DCollisionListener::EndContact(b2Contact* contact)
{
    auto bodyA = Body(_world, contact->GetFixtureA()->GetBody());
    auto bodyB = Body(_world, contact->GetFixtureB()->GetBody());

    for(auto& callback : _collisionExitCallbacks)
        callback(bodyA, bodyB);
}

World::Box2DCollisionListener::Box2DCollisionListener(b2World& world)
    : _world(world)
{

}
