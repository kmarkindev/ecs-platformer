#pragma once

#include "Utils/Singleton.h"
#include <memory>
#include "Window/Window.h"
#include "Application/AppParams.h"
#include "Assets/AssetsManager.h"
#include "Assets/OpenGlTextureLoader.h"
#include "Assets/OpenGlShaderLoader.h"
#include "Assets/GroupedAssetsParser.h"
#include "Assets/AssetsCache.h"
#include "Render/Renderer.h"
#include "Input/InputManager.h"
#include "Render/SpriteRenderer.h"
#include "Time/DeltaTime.h"
#include "Scene/SceneManager.h"

class SceneManager;

class DependencyContainer : public Singleton<DependencyContainer>
{
public:
    std::shared_ptr<Window> _window;
    std::shared_ptr<InputManager> _inputManager;
    std::shared_ptr<AppParams> _appParams;
    std::shared_ptr<AssetsManager> _assetsManager;
    std::shared_ptr<GroupedAssetsParser> _groupedAssetsParser;
    std::shared_ptr<OpenGlTextureLoader> _textureLoader;
    std::shared_ptr<OpenGlShaderLoader> _shaderLoader;
    std::shared_ptr<Renderer> _renderer;
    std::shared_ptr<SpriteRenderer> _spriteRenderer;
    std::shared_ptr<DeltaTime> _deltaTime;
    std::shared_ptr<SceneManager> _sceneManager;
    std::shared_ptr<AssetsCache> _assetsCache;
};


