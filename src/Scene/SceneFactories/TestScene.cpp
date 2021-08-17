#include "TestScene.h"

std::shared_ptr<Scene> TestScene::LoadScene()
{
    auto scene = std::make_shared<Scene>();
    auto _container = DependencyContainer::GetInstance();

    _doorSprite = new Sprite(&_container->_assetsCache->_door);

    _groundSprite = new Sprite(&_container->_assetsCache->_ground_grass);
    _groundSprite->SetSize({1.0f, 1.0f});

    auto camera = scene->CreateEntity();
    camera.AddComponent<TransformComponent>(glm::vec2(0, 0),
                                            glm::vec2(1, 1), 0.0f);
    camera.AddComponent<CameraComponent>(10.0f);

    auto image = scene->CreateEntity();
    image.AddComponent<TransformComponent>(glm::vec2(0, 7),
                                           glm::vec2(1, 1), 90.0f);
    image.AddComponent<SpriteComponent>(_doorSprite);
    image.AddComponent<PhysicsComponent>(1.0f, 0.2f, 0.0f, Body::BodyType::Dynamic, glm::vec2(0.7f, 1.0f));

    auto ground = scene->CreateEntity();
    ground.AddComponent<TransformComponent>(glm::vec2(0, -3),
                                           glm::vec2(10, 1), 10.0f);
    ground.AddComponent<SpriteComponent>(_groundSprite);
    ground.AddComponent<PhysicsComponent>(1.0f, 1.0f, 0.0f, Body::BodyType::Static, glm::vec2(1.0f, 1.0f));

    scene->AddSystem<SpriteRenderSystem>();
    scene->AddSystem<PhysicsSystem>();
    scene->AddSystem<TestSystem>();

    return scene;
}

void TestScene::UnloadScene()
{
    delete _groundSprite;
    delete _doorSprite;
}
