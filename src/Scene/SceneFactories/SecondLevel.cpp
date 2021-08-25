#include "SecondLevel.h"

std::shared_ptr<Scene> SecondLevel::LoadScene()
{
    auto cache = DependencyContainer::GetInstance()->_assetsCache;
    _scene = std::make_shared<Scene>();

    SetupCamera();

    SetupGround(cache);

    SetupPlayer(cache);

    SetupSystems();

    return _scene;
}

void SecondLevel::SetupPlayer(const std::shared_ptr<AssetsCache>& cache)
{
    auto player = _scene->CreateEntity();
    player.AddComponent<TransformComponent>(glm::vec2(-8, -1.0f));
    player.AddComponent<SpriteComponent>(&cache->_playerSprite);
    player.AddComponent<PhysicsComponent>(1.0f, 0.2f, 50.0f, Body::BodyType::Dynamic, glm::vec2(1,1), 0.0f, glm::vec2(0,0), true);
    player.AddComponent<PlayerComponent>();
}

void SecondLevel::SetupSystems()
{
    _scene->AddSystem<SpriteRenderSystem>();
    _scene->AddSystem<PhysicsSystem>();
    _scene->AddSystem<PlayerSystem>();
    _scene->AddSystem<CameraSystem>();
    _scene->AddSystem<PathMovingSystem>();
}

void SecondLevel::SetupGround(const std::shared_ptr<AssetsCache>& cache)
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

    auto spike = _scene->CreateEntity();
    spike.AddComponent<DangerComponent>();
    spike.AddComponent<TransformComponent>(glm::vec2(3, -1.2f), glm::vec2(0.8f, 0.8f));
    spike.AddComponent<PhysicsComponent>(1.0f, 1.0f, 0.2f, Body::BodyType::Static);
    spike.AddComponent<SpriteComponent>(&cache->_spikeSprite);

    auto movingSpike = _scene->CreateEntity();
    movingSpike.AddComponent<DangerComponent>();
    movingSpike.AddComponent<PathComponent>(glm::vec2(-8, 1), glm::vec2(-5, 0.5f));
    movingSpike.AddComponent<TransformComponent>(glm::vec2(0, 0), glm::vec2(0.8f, 0.8f));
    movingSpike.AddComponent<PhysicsComponent>(1.0f, 1.0f, 0.2f, Body::BodyType::Kinematic);
    movingSpike.AddComponent<SpriteComponent>(&cache->_spikeSprite);

    auto movingSpike2 = _scene->CreateEntity();
    movingSpike2.AddComponent<DangerComponent>();
    movingSpike2.AddComponent<PathComponent>(glm::vec2(-1, 5), glm::vec2(1, -0.5f));
    movingSpike2.AddComponent<TransformComponent>(glm::vec2(0, 0), glm::vec2(0.8f, 0.8f));
    movingSpike2.AddComponent<PhysicsComponent>(1.0f, 1.0f, 0.2f, Body::BodyType::Kinematic);
    movingSpike2.AddComponent<SpriteComponent>(&cache->_spikeSprite);

    auto groundCollision = _scene->CreateEntity();
    groundCollision.AddComponent<TransformComponent>(glm::vec2(0,-2), glm::vec2(20, 0.95));
    groundCollision.AddComponent<PhysicsComponent>(1.0f, 1.0f, 0.2f, Body::BodyType::Static);

    auto leftWallCollision = _scene->CreateEntity();
    leftWallCollision.AddComponent<TransformComponent>(glm::vec2(-10,3), glm::vec2(1, 30));
    leftWallCollision.AddComponent<PhysicsComponent>(1.0f, 1.0f, 0.0f, Body::BodyType::Static);

    auto rightWallCollision = _scene->CreateEntity();
    rightWallCollision.AddComponent<TransformComponent>(glm::vec2(10,3), glm::vec2(1, 30));
    rightWallCollision.AddComponent<PhysicsComponent>(1.0f, 1.0f, 0.0f, Body::BodyType::Static);

    auto exitDoor = _scene->CreateEntity();
    exitDoor.AddComponent<TransformComponent>(glm::vec2(8,-1), glm::vec2(0.8f, 1));
    exitDoor.AddComponent<PhysicsComponent>(1.0f, 1.0f, 0.0f, Body::BodyType::Static);
    exitDoor.AddComponent<SpriteComponent>(&cache->_doorSprite);
    exitDoor.AddComponent<DoorComponent>();
}

void SecondLevel::SetupCamera()
{
    auto camera = _scene->CreateEntity();
    camera.AddComponent<TransformComponent>(glm::vec2(-8, 0));
    camera.AddComponent<CameraComponent>(10.0f);
}

void SecondLevel::UnloadScene()
{
    _scene.reset();
}
