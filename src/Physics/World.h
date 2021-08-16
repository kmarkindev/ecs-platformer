#pragma once

#include <box2d/b2_world.h>
#include <box2d/b2_world_callbacks.h>
#include <box2d/b2_contact.h>
#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>
#include <memory>
#include "Body.h"
#include <stdexcept>
#include <functional>
#include <forward_list>

class World
{
    friend class Body;
    typedef std::function<void(Body, Body)> CollisionCallback;

    class Box2DCollisionListener : public b2ContactListener
    {
    public:
        b2World& _world;
        std::forward_list<CollisionCallback> _collisionEnterCallbacks;
        std::forward_list<CollisionCallback> _collisionExitCallbacks;

        explicit Box2DCollisionListener(b2World& world);

        void BeginContact(b2Contact* contact) override;

        void EndContact(b2Contact* contact) override;
    };

public:
    explicit World(glm::vec2 gravity);

    Body CreateBody(const Body::BodyParams& params);

    void OnCollisionEnter(const CollisionCallback& callback);
    void OnCollisionExit(const CollisionCallback& callback);

    void Update(float timestamp);

private:
    b2World _world;
    Box2DCollisionListener _collisionListener;
};