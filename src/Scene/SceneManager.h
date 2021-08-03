#pragma once

#include "Scene.h"
#include "SceneFactory.h"
#include <map>

class SceneManager
{
public:

    void RegisterSceneFactory(std::shared_ptr<ISceneFactory> factory, int sceneId);

    bool HasRegisteredSceneFactory(int sceneId);

    void LoadScene(int sceneId);

    std::pair<int, std::shared_ptr<Scene>> GetActiveScene();

private:

    std::map<int, std::shared_ptr<ISceneFactory>> _factories;
    std::pair<int, std::shared_ptr<Scene>> _activeScene;

};


