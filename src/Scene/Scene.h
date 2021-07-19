#pragma once

#include <entt/entt.hpp>
#include "Entity.h"

class Scene
{
public:
    Scene();

    Entity CreateEntity();

private:
    friend class Entity;
    entt::registry _registry;
};


