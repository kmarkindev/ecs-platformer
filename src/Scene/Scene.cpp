#include "Scene.h"

Scene::Scene()
    : _registry(),
    _sceneManager(DependencyContainer::GetInstance()->_sceneManager)
{

}

Entity Scene::CreateEntity()
{
    return {_registry.create(), &_registry};
}

void Scene::UpdateSystems()
{
    for(auto& [key, sys] : GetSortedSystems())
    {
        if(_sceneManager->SceneChanged())
            return;

        sys->Update(*this);
    }
}

void Scene::InitSystems()
{
    for(auto& [key, sys] : GetSortedSystems())
    {
        sys->Init(*this);
    }
}

std::vector<std::pair<std::size_t, std::shared_ptr<ISystem>>> Scene::GetSortedSystems()
{
    typedef std::pair<std::size_t, std::shared_ptr<ISystem>> pair;
    std::vector<pair> res;
    res.reserve(_systems.size());

    std::copy(_systems.begin(), _systems.end(), std::back_inserter(res));

    std::sort(res.begin(), res.end(), [](const pair& p1, const pair& p2){
        return p1.second->GetPriority() > p2.second->GetPriority();
    });

    return res;
}

Scene::EventHandler::EventHandler(Scene& scene, Scene::EventHandler::Callback callback)
    : _scene(&scene),
    _callback(std::move(callback))
{

}

void Scene::EventHandler::HandleSignal(entt::registry& reg, entt::entity ent)
{
    _callback(*_scene, Entity(ent, &reg));
}

Scene::EventHandler* Scene::GetHandler(const std::function<void(Scene&, Entity)>& callback)
{
    auto handler = new Scene::EventHandler(*this, callback);
    _eventHandlers.push_front(handler);
    return handler;
}

Scene::~Scene()
{
    for(auto handler : _eventHandlers)
        delete handler;
}

EventListener& Scene::GetEventListener()
{
    return _eventlistener;
}
