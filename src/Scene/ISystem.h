#pragma once

class ISystem
{
public:
    virtual void Init(Scene& scene) = 0;
    virtual void Update(Scene& scene) = 0;
};