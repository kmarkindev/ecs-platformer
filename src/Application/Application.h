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
#include "Scene/SceneManager.h"
#include "Scene/SceneFactories/TestScene.h"

class Application
{
public:
    explicit Application(AppParams params);
    bool Update();
private:
    DependencyContainer* _container;

    void InitializeContainer(AppParams params);
    void RegisterSceneFactories();
};


