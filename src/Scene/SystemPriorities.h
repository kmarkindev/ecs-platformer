#pragma once

/*
    Systems are ASC sorted by these ids when updating scene
*/

enum class SystemPriorities : int
{
    PhysicsSystem = 2,
    GameSystems = 1,
    SpriteRenderSystem = 0
};