#pragma once

#include <stdexcept>
#include <box2d/b2_world.h>
#include <box2d/b2_body.h>
#include <box2d/b2_fixture.h>
#include <box2d/b2_polygon_shape.h>
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
        glm::vec2 boxSize;
    };

public:
    explicit Body(b2World& world, const BodyParams& params);
    Body(const Body&) = delete;
    Body(Body&&) noexcept;
    ~Body();

    [[nodiscard]] glm::vec2 GetPosition() const;
    void SetPosition(glm::vec2 pos);
    [[nodiscard]] float GetAngle() const;
    void SetAngle(float angle);
    void UpdateParams(const BodyParams& params);

private:
    b2Body* _body;
    b2Fixture* _fixture;
    b2World* _world;

    b2BodyType ConvertBodyType(BodyType type);
    b2FixtureDef CreateFixtureDef(const BodyParams& params, b2Shape& shape);
    b2MassData CreateMassData(const BodyParams& params);
    b2PolygonShape CreateBoxShape(const BodyParams& params);
};