#include "Application.h"

Application::Application(AppParams params)
{
    InitializeContainer(std::move(params));
}

bool Application::Update()
{
    _container->_window->PollEvents();

    if(_container->_window->HasCloseSignal())
        return false;



    _container->_window->SwapBuffers();

    return true;
}

void Application::InitializeContainer(AppParams params)
{
    _container = DependencyContainer::GetInstance();

    _container->_appParams = std::make_shared<AppParams>(std::move(params));
    _container->_window = std::make_shared<Window>("Platformer", 800, 600, false);
    _container->_inputManager = std::make_shared<InputManager>(_container->_window);
    _container->_renderer = std::make_shared<Renderer>(_container->_window);
    _container->_assetsManager = std::make_shared<AssetsManager>(_container->_appParams->GetAppRootFolder());
    _container->_textureLoader = std::make_shared<TextureLoader>();
}
