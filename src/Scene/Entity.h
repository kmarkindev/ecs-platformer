#pragma once

#include <utility>
#include <entt/entt.hpp>
#include <functional>

class Entity
{
public:
    Entity(entt::entity entity, entt::registry* registry);
    Entity(const Entity& entity) = default;

    template<typename T, typename... Args>
    decltype(auto) AddComponent(Args&& ... args)
    {
        return _registry->emplace<T>(_entity, std::forward<Args>(args)...);
    }

    template<typename T, typename... Args>
    T ReplaceComponent(Args&& ... args)
    {
        return _registry->replace<T>(_entity, std::forward<Args>(args)...);
    }

    template<typename T>
    void PatchComponent(std::function<void(T&)> callback)
    {
        _registry->patch<T>(_entity, callback);
    }

    template<typename T>
    void RemoveComponent()
    {
        _registry->remove<T>(_entity);
    }

    template<typename T>
    [[nodiscard]] T GetComponent() const
    {
        return _registry->get<T>(_entity);
    }

    template<typename... Comps>
    [[nodiscard]] bool HasAnyOfComponents() const
    {
        return _registry->any_of<Comps...>(_entity);
    }

    template<typename... Comps>
    [[nodiscard]] bool HasAllOfComponents() const
    {
        return _registry->all_of<Comps...>(_entity);
    }

    [[nodiscard]] bool IsValid() const;

    void Delete();

private:
    entt::entity _entity;
    entt::registry* _registry;
};
