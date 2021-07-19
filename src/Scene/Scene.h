#pragma once

#include <entt/entt.hpp>
#include "Entity.h"

class Scene
{
public:

    template<typename... Exclude> struct ExcludeComponents {};

public:
    Scene();

    Entity CreateEntity();

    template<typename... Filter, typename... Exclude>
    std::vector<Entity> GetEntities(ExcludeComponents<Exclude...> exclude = {})
    {
        auto entities = _registry.view<Filter...>(entt::exclude<Exclude...>);

        std::vector<Entity> result;
        for(const auto& entity : entities)
        {
            result.push_back(Entity(entity, _registry));
        }

        return result;
    }

private:
    friend class Entity;
    entt::registry _registry;
};


