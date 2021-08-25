#include "PlayerSystem.h"

void PlayerSystem::Init(Scene& scene)
{
    scene.GetEventListener().Subscribe<CollisionEnter>([](CollisionEnter& event)
    {
        auto entA = event.GetA().GetEntity();
        auto entB = event.GetB().GetEntity();

        bool playerDied = entA.HasAnyOfComponents<PlayerComponent, DangerComponent>();
        playerDied = playerDied
                && entB.HasAnyOfComponents<PlayerComponent, DangerComponent>();

        //it doesn't work if there are colliding entities with DangerComponent
        //but there are no such entities :)
        if(playerDied)
            DependencyContainer::GetInstance()->_sceneManager->ReloadActiveScene();
    });

    scene.GetEventListener().Subscribe<CollisionEnter>([](CollisionEnter& event)
    {
        auto entA = event.GetA().GetEntity();
        auto entB = event.GetB().GetEntity();

        bool playerEscaped = entA.HasAnyOfComponents<PlayerComponent, DoorComponent>();
        playerEscaped = playerEscaped
                        && entB.HasAnyOfComponents<PlayerComponent, DoorComponent>();

        if(playerEscaped)
        {
            auto container = DependencyContainer::GetInstance();
            auto levelId = container->_sceneManager->GetActiveScene().first + 1;

            if(container->_sceneManager->HasRegisteredSceneFactory(levelId))
                container->_sceneManager->LoadScene(levelId);
            else
                container->_sceneManager->LoadScene(0);
        }
    });
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
        moveSpeed *= 0.4f;

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
