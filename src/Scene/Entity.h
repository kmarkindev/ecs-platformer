#pragma once

#include <utility>
#include <entt/entt.hpp>

class Entity
{
public:
    Entity(entt::entity, entt::registry& registry);

    template<typename T, typename... Args>
    T AddComponent(Args&& ... args)
    {
        return _registry.emplace<T>(_entity, std::forward<Args>(args)...);
    }

    template<typename T>
    void RemoveComponent()
    {
        _registry.remove<T>(_entity);
    }

    template<typename... Comps>
    bool HasAnyOfComponents()
    {
        return _registry.any_of<Comps...>(_entity);
    }

    template<typename... Copms>
    bool HasAllOfComponents()
    {
        return _registry.all_of<Copms...>(_entity);
    }

    bool IsValid()
    {
        return _registry.valid(_entity);
    }

    void Delete();

private:
    entt::entity _entity;
    entt::registry& _registry;
};