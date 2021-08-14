#pragma once

#include <stdexcept>
#include <box2d/b2_world.h>
#include <box2d/b2_body.h>
#include <glm/glm.hpp>

class Body
{
public:
    enum class BodyType
    {
        Static,
        Kinematic,
        Dynamic
    };

    struct BodyParams
    {
        glm::vec2 position;
        float angle;
        float mass;
        float momentOfInertia;
        float friction;
        BodyType type;
    };

public:
    explicit Body(b2World& world, const BodyParams& params);
    Body(const Body&) = delete;
    Body(Body&&) = default;
    ~Body();

    [[nodiscard]] glm::vec2 GetPosition() const;
    void SetPosition(glm::vec2 pos);
    [[nodiscard]] float GetAngle() const;
    void SetAngle(float angle);

private:
    b2Body* _body;
    b2World* _world;

    b2BodyType ConvertBodyType(BodyType type);
};