#include "FirstLevel.h"

std::shared_ptr<Scene> FirstLevel::LoadScene()
{
    auto cache = DependencyContainer::GetInstance()->_assetsCache;
    _scene = std::make_shared<Scene>();

    SetupCamera();

    SetupGround(cache);

    SetupPlayer(cache);

    SetupSystems();

    return _scene;
}

void FirstLevel::SetupPlayer(const std::shared_ptr<AssetsCache>& cache)
{
    auto player = _scene->CreateEntity();
    player.AddComponent<TransformComponent>(glm::vec2(0, -1.0f));
    player.AddComponent<SpriteComponent>(&cache->_doorSprite);
    player.AddComponent<PhysicsComponent>(1.0f, 0.2f, 50.0f, Body::BodyType::Dynamic, glm::vec2(1,1), 0.0f, glm::vec2(0,0), true);
    player.AddComponent<PlayerComponent>();
}

void FirstLevel::SetupSystems()
{
    _scene->AddSystem<SpriteRenderSystem>();
    _scene->AddSystem<PhysicsSystem>();
    _scene->AddSystem<PlayerSystem>();
    _scene->AddSystem<CameraSystem>();
}

void FirstLevel::SetupGround(const std::shared_ptr<AssetsCache>& cache)
{
    for(int x = -10; x <= 10; ++x)
    {
        auto groundGrassTile = _scene->CreateEntity();
        groundGrassTile.AddComponent<TransformComponent>(glm::vec2(x, -2));
        groundGrassTile.AddComponent<SpriteComponent>(&cache->_groundGrassSprite);
    }

    for(int y = -3; y > -7; --y)
    {
        for(int x = -10; x <= 10; ++x)
        {
            auto groundGrassTile = _scene->CreateEntity();
            groundGrassTile.AddComponent<TransformComponent>(glm::vec2(x, y));
            groundGrassTile.AddComponent<SpriteComponent>(&cache->_groundSprite);
        }
    }

    auto groundCollision = _scene->CreateEntity();
    groundCollision.AddComponent<TransformComponent>(glm::vec2(0,-2), glm::vec2(20, 0.95));
    groundCollision.AddComponent<PhysicsComponent>(1.0f, 1.0f, 0.2f, Body::BodyType::Static);

    auto leftWallCollision = _scene->CreateEntity();
    leftWallCollision.AddComponent<TransformComponent>(glm::vec2(-10,3), glm::vec2(1, 30));
    leftWallCollision.AddComponent<PhysicsComponent>(1.0f, 1.0f, 0.0f, Body::BodyType::Static);

    auto rightWallCollision = _scene->CreateEntity();
    rightWallCollision.AddComponent<TransformComponent>(glm::vec2(10,3), glm::vec2(1, 30));
    rightWallCollision.AddComponent<PhysicsComponent>(1.0f, 1.0f, 0.0f, Body::BodyType::Static);
}

void FirstLevel::SetupCamera()
{
    auto camera = _scene->CreateEntity();
    camera.AddComponent<TransformComponent>();
    camera.AddComponent<CameraComponent>(10.0f);
}

void FirstLevel::UnloadScene()
{
    _scene.reset();
}
