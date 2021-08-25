#pragma once

#include "Scene/SceneFactory.h"
#include "Container/DependencyContainer.h"
#include "Components/TransformComponent.h"
#include "Components/SpriteComponent.h"
#include "Components/CameraComponent.h"
#include "Components/PhysicsComponent.h"
#include "Systems/SpriteRenderSystem.h"
#include "Systems/PhysicsSystem.h"
#include "Systems/PlayerSystem.h"
#include "Systems/CameraSystem.h"
#include "Components/PlayerComponent.h"
#include "Components/DangerComponent.h"
#include "Components/DoorComponent.h"

class SecondLevel : public ISceneFactory
{
public:

    std::shared_ptr<Scene> LoadScene() override;
    void UnloadScene() override;

private:

    std::shared_ptr<Scene> _scene;

    void SetupCamera();

    void SetupGround(const std::shared_ptr<AssetsCache>& cache);

    void SetupSystems();

    void SetupPlayer(const std::shared_ptr<AssetsCache>& cache);
};
