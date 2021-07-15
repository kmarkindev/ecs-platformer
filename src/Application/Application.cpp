#include "Application.h"

Application::Application(AppParams params)
    : _window("Platformer", 800, 600, false),
    _appParams(std::move(params)),
    _assetsManager(_appParams.GetAppRootFolder()),
    _textureLoader()
{

}

bool Application::Update()
{
    _window.PollEvents();

    if(_window.HasCloseSignal())
        return false;



    _window.SwapBuffers();

    return true;
}