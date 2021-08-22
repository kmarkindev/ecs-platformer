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
    float jumpVelocity = physicsComp.linearVelocity.y;
    float moveSpeed = playerComp.moveSpeed;

    float fallVelocity = std::abs(physicsComp.linearVelocity.y);
    bool isOnGround = fallVelocity < 0.05f;

    if(!isOnGround)
        moveSpeed *= 0.3f;

    if(inputManager->KeyPressed(KeyCode::A))
        moveVelocity -= moveSpeed;

    if(inputManager->KeyPressed(KeyCode::D))
        moveVelocity += moveSpeed;

    if(inputManager->KeyPressed(KeyCode::SPACE)
        && isOnGround)
        jumpVelocity = playerComp.jumpForce;

    player.PatchComponent<PhysicsComponent>([moveVelocity, jumpVelocity](auto& pComp)
    {
        if(moveVelocity > 0)
        {
            if(pComp.linearVelocity.x < moveVelocity)
                pComp.linearVelocity.x = moveVelocity;
        }
        else if(moveVelocity < 0)
        {
            if(pComp.linearVelocity.x > moveVelocity)
                pComp.linearVelocity.x = moveVelocity;
        }

        pComp.linearVelocity.y = jumpVelocity;
    });
}

PlayerSystem::PlayerSystem()
    : _container(DependencyContainer::GetInstance())
{

}
