#include "PlayerSystem.h"

void PlayerSystem::Init(Scene& scene)
{

}

void PlayerSystem::Update(Scene& scene)
{
    auto player = scene.GetEntities<PhysicsComponent, PlayerComponent>().front();
    auto playerComp = player.GetComponent<PlayerComponent>();
    auto physicsComp = player.GetComponent<PhysicsComponent>();

    auto inputManager = _container->_inputManager;

    float moveVelocity = 0.0f;
    float moveSpeed = playerComp.moveSpeed;

    if(physicsComp.linearVelocity.y > 0.1f)
        moveSpeed *= 0.2f;

    if(inputManager->KeyPressed(KeyCode::KEY_A))
        moveVelocity -= moveSpeed;

    if(inputManager->KeyPressed(KeyCode::KEY_D))
        moveVelocity += moveSpeed;

    if(std::abs(physicsComp.linearVelocity.x) < std::abs(moveVelocity))
    {
        player.PatchComponent<PhysicsComponent>([moveVelocity](auto& pComp)
        {
            pComp.linearVelocity.x = moveVelocity;
        });
    }
}

PlayerSystem::PlayerSystem()
    : _container(DependencyContainer::GetInstance())
{

}
