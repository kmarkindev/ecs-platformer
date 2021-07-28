#include "Application.h"

Application::Application(AppParams params)
{
    InitializeContainer(std::move(params));
    InitializeScene();
    _scene.InitSystems();
}

bool Application::Update()
{
    _container->_window->PollEvents();

    if(_container->_window->HasCloseSignal())
        return false;

    _container->_renderer->StartRender();
    _scene.UpdateSystems();
    _container->_renderer->EndRender();

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
    _container->_groupedAssetsParser = std::make_shared<GroupedAssetsParser>();
    _container->_textureLoader = std::make_shared<OpenGlTextureLoader>();
    _container->_shaderLoader = std::make_shared<OpenGlShaderLoader>(_container->_renderer, _container->_groupedAssetsParser);
    _container->_spriteRenderer = std::make_shared<SpriteRenderer>(_container->_renderer, _container->_shaderLoader,
                                                                   _container->_assetsManager);
}

void Application::InitializeScene()
{
    static Texture txt = _container->_textureLoader->LoadTexture(_container->_assetsManager->GetAssetData(std::filesystem::path("image.png")));
    static Sprite sprite = Sprite(&txt);

    auto camera = _scene.CreateEntity();
    camera.AddComponent<TransformComponent>(glm::vec2({0, 0}), glm::vec2({1, 1}), glm::quat({1, 0, 0, 0}));
    camera.AddComponent<CameraComponent>(5.0f);

    auto image = _scene.CreateEntity();
    image.AddComponent<TransformComponent>(glm::vec2({0, 0}), glm::vec2({1, 1}), glm::quat({1, 0, 0, 0}));
    image.AddComponent<SpriteComponent>(&sprite);

    _scene.AddSystem<SpriteRenderSystem>();
    _scene.AddSystem<SinMoveSystem>();
}
