#include "Application.h"

Application::Application(AppParams params)
{
    InitializeContainer(std::move(params));
    RegisterSceneFactories();
    _scene.InitSystems();
    _container->_deltaTime->ResetDeltaTime();
}

bool Application::Update()
{
    _container->_window->PollEvents();

    if(_container->_window->HasCloseSignal())
        return false;

    auto scene = _container->_sceneManager->GetActiveScene();

    _container->_renderer->StartRender();
    scene.second->UpdateSystems();
    _container->_renderer->EndRender();

    _container->_window->SwapBuffers();

    _container->_deltaTime->UpdateDeltaTime();

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
    _container->_groupedAssetsParser = std::make_shared<GroupedAssetsParser>();
    _container->_textureLoader = std::make_shared<OpenGlTextureLoader>();
    _container->_shaderLoader = std::make_shared<OpenGlShaderLoader>(_container->_renderer, _container->_groupedAssetsParser);
    _container->_spriteRenderer = std::make_shared<SpriteRenderer>(_container->_renderer, _container->_shaderLoader,
                                                                   _container->_assetsManager);
    _container->_deltaTime = std::make_shared<DeltaTime>();
    _container->_sceneManager = std::make_shared<SceneManager>();
}

void Application::RegisterSceneFactories()
{
    auto manager = _container->_sceneManager;

    manager->RegisterSceneFactory(std::make_shared<TestScene>(), 1);

    manager->LoadScene(1);
}
