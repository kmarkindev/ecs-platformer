#pragma once

#include "Entity.h"
#include <entt/entt.hpp>
#include "ISystem.h"
#include <map>
#include <stdexcept>
#include <memory>
#include <typeinfo>

class ISystem;
class Entity;

template<typename T>
concept System = std::is_base_of_v<ISystem, T>;

class Scene
{
public:

    template<typename... Exclude> struct ExcludeComponents {};

public:
    Scene();

    Entity CreateEntity();
    void UpdateSystems();
    void InitSystems();

    template<typename... Filter, typename... Exclude>
    [[nodiscard]] std::vector<Entity> GetEntities(ExcludeComponents<Exclude...> exclude = {}) const
    {
        auto entities = _registry.view<const Filter...>(entt::exclude<const Exclude...>);

        std::vector<Entity> result;
        for(entt::entity entity : entities)
        {
            result.push_back(Entity(entity, const_cast<entt::registry*>(&_registry)));
        }

        return result;
    }

    template<System T, typename... Args>
    void AddSystem(Args&& ... args)
    {
        if(HasSystem<T>())
            throw std::invalid_argument("Cannot add system that already exists");

        _systems.emplace(typeid(T).hash_code(), std::make_unique<T>(std::forward<Args>(args)...));
    }

    template<System T>
    [[nodiscard]] bool HasSystem() const
    {
        const auto typeId = typeid(T).hash_code();
        return _systems.contains(typeId);
    }

    template<System T>
    void RemoveSystem()
    {
        auto iterator = _systems.find(typeid(T).hash_code());
        if(iterator != _systems.end())
            _systems.erase(iterator);
    }

private:
    entt::registry _registry;
    std::map<std::size_t, std::shared_ptr<ISystem>> _systems;

    std::vector<std::pair<std::size_t, std::shared_ptr<ISystem>>> GetSortedSystems();
};


