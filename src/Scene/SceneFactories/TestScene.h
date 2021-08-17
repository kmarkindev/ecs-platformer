#pragma once

#include "Scene/SceneFactory.h"
#include "Container/DependencyContainer.h"
#include "Components/CameraComponent.h"
#include "Components/SpriteComponent.h"
#include "Components/TransformComponent.h"
#include "Systems/PhysicsSystem.h"
#include "Systems/TestSystem.h"
#include "Systems/SpriteRenderSystem.h"
#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>

class TestScene : public ISceneFactory
{
public:

    std::shared_ptr<Scene> LoadScene() override;

    void UnloadScene() override;

private:

    Sprite* _groundSprite = nullptr;
    Sprite* _doorSprite = nullptr;

};


