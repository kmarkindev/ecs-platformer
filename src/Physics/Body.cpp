#include "Body.h"

Body::Body(b2World& world, const BodyParams& params, const Entity& entity)
{
    _world = &world;

    CreateBody(params);

    auto shape = CreateBoxShape(params);

    auto fixtureDef = CreateFixtureDef(params, shape);

    _fixture = _body->CreateFixture(&fixtureDef);

    auto massData = CreateMassData(params);
    _body->SetMassData(&massData);

    SetEntity(entity);
}

Body::Body(b2World& world, b2Body* existingBody)
{
    _world = &world;

    _body = existingBody;
    _fixture = existingBody->GetFixtureList();
}

void Body::CreateBody(const Body::BodyParams& params)
{
    b2BodyDef bodyDef;
    bodyDef.type = ConvertBodyType(params.type);
    bodyDef.position = { params.position. x, params.position.y };
    bodyDef.angle = glm::radians(params.angle);
    bodyDef.angularVelocity = params.angularVelocity;
    bodyDef.linearVelocity = {params.linearVelocity.x, params.linearVelocity.y};
    bodyDef.fixedRotation = params.fixedRotation;

    _body = _world->CreateBody(&bodyDef);
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
    return glm::degrees(_body->GetAngle());
}

void Body::SetAngle(float angle)
{
    auto oldPos = _body->GetPosition();
    _body->SetTransform(oldPos, glm::radians(angle));
    _body->SetAwake(true);
}

void Body::UpdateParams(const Body::BodyParams& params)
{
    auto massData = CreateMassData(params);
    _body->SetMassData(&massData);

    _body->SetType(ConvertBodyType(params.type));
    _body->SetFixedRotation(params.fixedRotation);
    _body->SetLinearVelocity({params.linearVelocity.x, params.linearVelocity.y});
    _body->SetAngularVelocity(params.angularVelocity);

    _fixture->SetFriction(params.friction);
}

b2MassData Body::CreateMassData(const Body::BodyParams& params)
{
    return {
        .mass = params.mass,
        .center = {0.0f, 0.0f},
        .I = params.momentOfInertia
    };
}

b2FixtureDef Body::CreateFixtureDef(const Body::BodyParams& params, b2Shape& shape)
{
    b2FixtureDef fixtureDef;
    fixtureDef.friction = params.friction;
    fixtureDef.shape = &shape;

    return fixtureDef;
}

b2PolygonShape Body::CreateBoxShape(const Body::BodyParams& params)
{
    b2PolygonShape shape;
    shape.SetAsBox(params.boxSize.x / 2.0f, params.boxSize.y / 2.0f);
    return shape;
}

void Body::DestroyBody()
{
    delete reinterpret_cast<Entity*>(_body->GetUserData().pointer);

    _world->DestroyBody(_body);
    _body = nullptr;
    _fixture = nullptr;
}

void Body::SetVelocity(const glm::vec2& newVelocity)
{
    _body->SetLinearVelocity({newVelocity.x, newVelocity.y});
}

glm::vec2 Body::GetVelocity() const
{
    auto vel = _body->GetLinearVelocity();
    return {vel.x, vel.y};
}

void Body::SetAngularVelocity(float newVelocity)
{
    _body->SetAngularVelocity(newVelocity);
}

float Body::GetAngularVelocity() const
{
    return _body->GetAngularVelocity();
}

void Body::SetIsFixedRotation(bool isFixed)
{
    _body->SetFixedRotation(isFixed);
}

bool Body::GetIsFixedRotation() const
{
    return _body->IsFixedRotation();
}

void Body::SetEntity(const Entity& entity)
{
    auto* ent = new Entity(entity);
    _body->GetUserData().pointer = reinterpret_cast<uintptr_t>(ent);
}

Entity Body::GetEntity() const
{
    return Entity(*reinterpret_cast<Entity*>(_body->GetUserData().pointer));
}
