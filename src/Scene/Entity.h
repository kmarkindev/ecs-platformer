#pragma once

#include <utility>
#include <entt/entt.hpp>
#include "IComponent.h"
#include <functional>

template<typename T>
concept Component = std::is_base_of_v<IComponent, T>;

class Entity
{
public:
    Entity(entt::entity entity, entt::registry* registry);

    template<Component T, typename... Args>
    T AddComponent(Args&& ... args)
    {
        return _registry->emplace<T>(_entity, std::forward<Args>(args)...);
    }

    template<Component T, typename... Args>
    T ReplaceComponent(Args&& ... args)
    {
        return _registry->replace<T>(_entity, std::forward<Args>(args)...);
    }

    template<Component T>
    void PatchComponent(std::function<void(T&)> callback)
    {
        _registry->patch<T>(_entity, callback);
    }

    template<Component T>
    void RemoveComponent()
    {
        _registry->remove<T>(_entity);
    }

    template<Component T>
    [[nodiscard]] T GetComponent() const
    {
        return _registry->get<T>(_entity);
    }

    template<Component... Comps>
    [[nodiscard]] bool HasAnyOfComponents() const
    {
        return _registry->any_of<Comps...>(_entity);
    }

    template<Component... Copms>
    [[nodiscard]] bool HasAllOfComponents() const
    {
        return _registry->all_of<Copms...>(_entity);
    }

    [[nodiscard]] bool IsValid() const;

    void Delete();

private:
    entt::entity _entity;
    entt::registry* _registry;
};
