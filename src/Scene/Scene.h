#pragma once

#include "Entity.h"
#include <entt/entt.hpp>
#include "ISystem.h"
#include <map>
#include <stdexcept>
#include <memory>
#include <typeinfo>
#include <forward_list>
#include "EventListener.h"
#include "SceneManager.h"
#include "Container/DependencyContainer.h"

class ISystem;
class Entity;
class SceneManager;

template<typename T>
concept System = std::is_base_of_v<ISystem, T>;

class Scene
{
public:

    template<typename... Exclude> struct ExcludeComponents {};

private:

    struct EventHandler
    {
        friend class Scene;
        typedef std::function<void(Scene&, Entity)> Callback;

        Callback _callback;
        Scene* _scene;

        EventHandler(Scene& scene, Callback callback);

        void HandleSignal(entt::registry& reg, entt::entity ent);
    };

public:
    Scene();
    ~Scene();

    Entity CreateEntity();
    void UpdateSystems();
    void InitSystems();
    EventListener& GetEventListener();

    template<typename... Filter, typename... Exclude>
    [[nodiscard]] std::vector<Entity> GetEntities(ExcludeComponents<Exclude...> exclude = {}) const
    {
        auto entities = _registry.view<Filter...>(entt::exclude<Exclude...>);

        std::vector<Entity> result;
        for(entt::entity entity : entities)
        {
            result.emplace_back(entity, const_cast<entt::registry*>(&_registry));
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

    template<typename Component>
    void OnUpdate(const std::function<void(Scene&, Entity)>& callback)
    {
        _registry.on_update<Component>()
            .template connect<&EventHandler::HandleSignal>(GetHandler(callback));
    }

    template<typename Component>
    void OnDestroy(const std::function<void(Scene&, Entity)>& callback)
    {
        _registry.on_destroy<Component>()
            .template connect<&EventHandler::HandleSignal>(GetHandler(callback));
    }

    template<typename Component>
    void OnCreate(const std::function<void(Scene&, Entity)>& callback)
    {
        _registry.on_construct<Component>()
            .template connect<&EventHandler::HandleSignal>(GetHandler(callback));
    }

private:
    mutable entt::registry _registry;
    std::map<std::size_t, std::shared_ptr<ISystem>> _systems;
    std::forward_list<EventHandler*> _eventHandlers;
    EventListener _eventlistener;
    std::shared_ptr<SceneManager> _sceneManager;

    std::vector<std::pair<std::size_t, std::shared_ptr<ISystem>>> GetSortedSystems();

    EventHandler* GetHandler(const std::function<void(Scene&, Entity)>& callback);
};


