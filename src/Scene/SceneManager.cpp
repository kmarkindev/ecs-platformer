#include "SceneManager.h"

void SceneManager::RegisterSceneFactory(std::shared_ptr<ISceneFactory> factory, int sceneId)
{
    _factories.insert_or_assign(sceneId, std::move(factory));
}

bool SceneManager::HasRegisteredSceneFactory(int sceneId)
{
    auto factory = _factories.find(sceneId);

    return factory == _factories.end();
}

void SceneManager::LoadScene(int sceneId)
{
    auto factory = _factories.find(sceneId);

    if(factory == _factories.end())
        throw std::invalid_argument("There is not registered scene factory under given id");

    _activeScene.second.reset();

    _activeScene = {sceneId, factory->second->LoadScene()};

    _activeScene.second->InitSystems();
}

std::pair<int, std::shared_ptr<Scene>> SceneManager::GetActiveScene()
{
    return _activeScene;
}