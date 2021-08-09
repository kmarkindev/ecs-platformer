#include "World.h"

World::World(glm::vec2 gravity)
    : _world(b2Vec2(gravity.x, gravity.y))
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
