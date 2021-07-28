#pragma once

#include "Scene/IComponent.h"
#include "Assets/Sprite.h"

struct SpriteComponent : public IComponent
{
    Sprite* sprite;

    explicit SpriteComponent(Sprite* sprite)
        : sprite(sprite)
    {

    }
};