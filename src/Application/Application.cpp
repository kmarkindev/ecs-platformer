#include "Application.h"

Application::Application(AppParams params)
    : _window("Platformer", 800, 600, false),
    _appParams(std::move(params)),
    _renderer(),
    _assetsManager(_appParams.GetAppRootFolder()),
    _textureLoader()
{

}

bool Application::Update()
{
    _window.PollEvents();

    if(_window.HasCloseSignal())
        return false;

    auto data = _assetsManager.GetAssetData(std::filesystem::path("image.png"));
    auto texture = _textureLoader.loadTexture(data);

    _window.SwapBuffers();

    return true;
}