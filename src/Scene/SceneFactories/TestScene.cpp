#include "TestScene.h"

std::shared_ptr<Scene> TestScene::LoadScene()
{
    auto scene = std::make_shared<Scene>();
    auto _container = DependencyContainer::GetInstance();

    static Texture txt = _container->_textureLoader->LoadTexture(
            _container->_assetsManager->GetAssetData(std::filesystem::path("image.png")));
    static Sprite sprite = Sprite(&txt);
    static Sprite groundSprite = Sprite(&txt);
    groundSprite.SetSize({1.0f, 1.0f});

    auto camera = scene->CreateEntity();
    camera.AddComponent<TransformComponent>(glm::vec2(0, 0),
                                            glm::vec2(1, 1), 0.0f);
    camera.AddComponent<CameraComponent>(15.0f);

    auto image = scene->CreateEntity();
    image.AddComponent<TransformComponent>(glm::vec2(0, 7),
                                           glm::vec2(1, 1), 60.0f);
    image.AddComponent<SpriteComponent>(&sprite);
    image.AddComponent<PhysicsComponent>(1.0f, 0.2f, 0.0f, Body::BodyType::Dynamic, glm::vec2(1.0f, 1.0f));

    auto ground = scene->CreateEntity();
    ground.AddComponent<TransformComponent>(glm::vec2(0, -3),
                                           glm::vec2(10, 1), 10.0f);
    ground.AddComponent<SpriteComponent>(&groundSprite);
    ground.AddComponent<PhysicsComponent>(1.0f, 1.0f, 0.0f, Body::BodyType::Static, glm::vec2(1.0f, 1.0f));

    scene->AddSystem<SpriteRenderSystem>();
    scene->AddSystem<PhysicsSystem>();
    scene->AddSystem<TestSystem>();

    return scene;
}
