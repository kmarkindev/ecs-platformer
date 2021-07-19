#include "Scene.h"

Scene::Scene()
    : _registry()
{
}

Entity Scene::CreateEntity()
{
    return Entity(_registry.create(), _registry);
}
