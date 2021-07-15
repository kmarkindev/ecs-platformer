#pragma once

#include "Window/Window.h"
#include "Application/AppParams.h"
#include "Assets/AssetsManager.h"
#include "Assets/TextureLoader.h"

class Application
{
public:
    explicit Application(AppParams params);
    bool Update();
private:
    Window _window;
    AppParams _appParams;
    AssetsManager _assetsManager;
    TextureLoader _textureLoader;
};


