#pragma once

#include "Scene.h"
#include "SystemPriorities.h"

class Scene;

class ISystem
{
public:
    virtual void Init(Scene& scene) = 0;
    virtual void Update(Scene& scene) = 0;

    virtual int GetPriority()
    {
        return (int)SystemPriorities::GameSystems;
    };
};