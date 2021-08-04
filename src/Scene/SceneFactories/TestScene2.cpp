#include "TestScene2.h"

std::shared_ptr<Scene> TestScene2::LoadScene()
{
    auto scene = std::make_shared<Scene>();
    auto _container = DependencyContainer::GetInstance();

    static Texture txt = _container->_textureLoader->LoadTexture(
            _container->_assetsManager->GetAssetData(std::filesystem::path("image.png")));
    static Sprite sprite = Sprite(&txt);

    auto camera = scene->CreateEntity();
    camera.AddComponent<TransformComponent>(glm::vec2({0, 0}),
                                            glm::vec2({1, 1}), glm::quat({1, 0, 0, 0}));
    camera.AddComponent<CameraComponent>(1.0f);

    auto image = scene->CreateEntity();
    image.AddComponent<TransformComponent>(glm::vec2({0, 0}),
                                           glm::vec2({1, 1}), glm::quat({1, 0, 0, 0}));
    image.AddComponent<SpriteComponent>(&sprite);

    scene->AddSystem<SpriteRenderSystem>();
    scene->AddSystem<SinMoveSystem>();

    return scene;
}