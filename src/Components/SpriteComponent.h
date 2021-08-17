#pragma once

#include "Assets/Sprite.h"

struct SpriteComponent
{
    Sprite* sprite;
    int renderingLayer = 0;
};