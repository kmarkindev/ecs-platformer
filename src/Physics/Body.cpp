#include "Body.h"

Body::Body(b2World& world, const BodyParams& params)
{
    _world = &world;

    b2BodyDef bodyDef;
    bodyDef.type = ConvertBodyType(params.type);
    bodyDef.position = { params.position. x, params.position.y };
    bodyDef.angle = params.angle;

    _body = _world->CreateBody(&bodyDef);
}

Body::~Body()
{
    _world->DestroyBody(_body);
}

b2BodyType Body::ConvertBodyType(BodyType type)
{
    switch(type)
    {
        case BodyType::Static:
            return b2BodyType::b2_staticBody;
        case BodyType::Dynamic:
            return b2BodyType::b2_dynamicBody;
        case BodyType::Kinematic:
            return b2_kinematicBody;
        default:
            throw std::runtime_error("Cannot convert body type");
    }
}

glm::vec2 Body::GetPosition() const
{
    auto pos = _body->GetPosition();
    return {pos.x, pos.y};
}

void Body::SetPosition(glm::vec2 pos)
{
    float oldAngle = _body->GetAngle();
    _body->SetTransform({pos.x, pos.y}, oldAngle);
    _body->SetAwake(true);
}

float Body::GetAngle() const
{
    return _body->GetAngle();
}

void Body::SetAngle(float angle)
{
    auto oldPos = _body->GetPosition();
    _body->SetTransform(oldPos, angle);
    _body->SetAwake(true);
}
