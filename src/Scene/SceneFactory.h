#pragma once

#include "Scene.h"

class ISceneFactory
{
public:

    virtual std::shared_ptr<Scene> LoadScene() = 0;
    virtual void UnloadScene() = 0;

};