#pragma once

#include "Scene.h"
#include "SceneFactory.h"
#include <map>

class DependencyContainer;
class ISceneFactory;

class SceneManager
{
public:

    void RegisterSceneFactory(std::shared_ptr<ISceneFactory> factory, int sceneId);

    bool HasRegisteredSceneFactory(int sceneId);

    void LoadScene(int sceneId);

    void ReloadActiveScene();

    std::pair<int, std::shared_ptr<Scene>> GetActiveScene();

    [[nodiscard]] bool SceneChanged() const;

    void ResetSceneChanged();

private:

    bool _sceneChanged = false;
    std::map<int, std::shared_ptr<ISceneFactory>> _factories;
    std::pair<int, std::shared_ptr<Scene>> _activeScene;

};


