#pragma once

#include <utility>
#include <entt/entt.hpp>
#include "IComponent.h"
#include "Scene.h"
#include <functional>


template<typename T>
concept Component = std::is_base_of_v<IComponent, T>;

class Entity
{
public:
    Entity(entt::entity, entt::registry& registry);

    template<Component T, typename... Args>
    T AddComponent(Args&& ... args)
    {
        return _registry.emplace<T>(_entity, std::forward<Args>(args)...);
    }

    template<Component T, typename... Args>
    T ReplaceComponent(Args&& ... args)
    {
        return _registry.replace<T>(_entity, std::forward<Args>(args)...);
    }

    template<Component T>
    void PatchComponent(std::function<void(T&)> callback)
    {
        _registry.patch<T>(_entity, callback);
    }

    template<Component T>
    void RemoveComponent()
    {
        _registry.remove<T>(_entity);
    }

    template<Component T>
    T GetComponent()
    {
        return _registry.get<T>(_entity);
    }

    template<Component... Comps>
    bool HasAnyOfComponents()
    {
        return _registry.any_of<Comps...>(_entity);
    }

    template<Component... Copms>
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
