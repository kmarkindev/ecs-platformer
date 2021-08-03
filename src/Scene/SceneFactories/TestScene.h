#pragma once

#include "Scene/SceneFactory.h"
#include "Container/DependencyContainer.h"
#include "Components/CameraComponent.h"
#include "Components/SpriteComponent.h"
#include "Components/TransformComponent.h"
#include "Systems/SinMoveSystem.h"
#include "Systems/SpriteRenderSystem.h"
#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>

class TestScene : public ISceneFactory
{
public:
    std::shared_ptr<Scene> LoadScene() override;
};


