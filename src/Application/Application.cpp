#include "Application.h"

Application::Application(AppParams params)
    : _window(std::make_shared<Window>("Platformer", 800, 600, false)),
    _inputManager(std::make_shared<InputManager>(_window)),
    _appParams(std::make_shared<AppParams>(std::move(params))),
    _renderer(std::make_shared<Renderer>(_window)),
    _assetsManager(std::make_shared<AssetsManager>(_appParams->GetAppRootFolder())),
    _textureLoader(std::make_shared<TextureLoader>())
{

}

bool Application::Update()
{
    _window->PollEvents();

    if(_window->HasCloseSignal())
        return false;



    _window->SwapBuffers();

    return true;
}