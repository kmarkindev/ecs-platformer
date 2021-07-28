#include "Scene.h"

Scene::Scene()
    : _registry()
{
}

Entity Scene::CreateEntity()
{
    return Entity(_registry.create(), &_registry);
}

void Scene::UpdateSystems()
{
    for(auto& [key, sys] : GetSortedSystems())
    {
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
