#pragma once

#include "Scene/SceneFactory.h"

class FirstLevel : public ISceneFactory
{
public:

    std::shared_ptr<Scene> LoadScene() override;
    void UnloadScene() override;

};
