#pragma once

#include <memory>
#include "Window/Window.h"
#include "Application/AppParams.h"
#include "Assets/AssetsManager.h"
#include "Assets/TextureLoader.h"
#include "Render/Renderer.h"
#include "Input/InputManager.h"

class Application
{
public:
    explicit Application(AppParams params);
    bool Update();
private:
    std::shared_ptr<Window> _window;
    std::shared_ptr<InputManager> _inputManager;
    std::shared_ptr<AppParams> _appParams;
    std::shared_ptr<AssetsManager> _assetsManager;
    std::shared_ptr<TextureLoader> _textureLoader;
    std::shared_ptr<Renderer> _renderer;
};


