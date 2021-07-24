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
    for(auto& [key, sys] : _systems)
    {
        sys->Update(*this);
    }
}

void Scene::InitSystems()
{
    for(auto& [key, sys] : _systems)
    {
        sys->Init(*this);
    }
}