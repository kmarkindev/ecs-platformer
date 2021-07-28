#pragma once

#include <memory>
#include "Application/AppParams.h"
#include "Container/DependencyContainer.h"
#include "Window/Window.h"
#include "Application/AppParams.h"
#include "Assets/AssetsManager.h"
#include "Assets/OpenGlTextureLoader.h"
#include "Render/Renderer.h"
#include "Input/InputManager.h"
#include "Assets/OpenGlShaderLoader.h"
#include "Scene/Scene.h"
#include "Math/Transform.h"

#include "Components/TransformComponent.h"
#include "Components/CameraComponent.h"
#include "Components/SpriteComponent.h"
#include "Systems/SpriteRenderSystem.h"
#include "Systems/SinMoveSystem.h"
#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>

class Application
{
public:
    explicit Application(AppParams params);
    bool Update();
private:
    DependencyContainer* _container;
    Scene _scene;

    void InitializeContainer(AppParams params);
    void InitializeScene();
};


