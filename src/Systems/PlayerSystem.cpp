#include "PlayerSystem.h"

void PlayerSystem::Init(Scene& scene)
{

}

void PlayerSystem::Update(Scene& scene)
{
    auto player = scene.GetEntities<TransformComponent, PhysicsComponent, PlayerComponent>().front();
    auto playerComp = player.GetComponent<PlayerComponent>();
    auto physicsComp = player.GetComponent<PhysicsComponent>();

    auto inputManager = _container->_inputManager;

    float moveVelocity = 0.0f;
    float moveSpeed = playerComp.moveSpeed;

    if(std::abs(physicsComp.linearVelocity.y) > 0.1f)
        moveSpeed *= 0.35f;

    if(inputManager->KeyPressed(KeyCode::A))
        moveVelocity -= moveSpeed;

    if(inputManager->KeyPressed(KeyCode::D))
        moveVelocity += moveSpeed;

    player.PatchComponent<PhysicsComponent>([moveVelocity](auto& pComp)
    {
        pComp.linearVelocity.x = moveVelocity;
    });
}

PlayerSystem::PlayerSystem()
    : _container(DependencyContainer::GetInstance())
{

}
