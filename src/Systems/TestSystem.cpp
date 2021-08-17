#include "TestSystem.h"

void TestSystem::Init(Scene& scene)
{
    scene.GetEventListener().Subscribe<CollisionExit>([](CollisionExit& event)
    {
        //DependencyContainer::GetInstance()->_sceneManager->LoadScene(0);
    });
}

void TestSystem::Update(Scene& scene)
{
    auto _container = DependencyContainer::GetInstance();
    bool spacePressed = _container
            ->_inputManager
            ->KeyPressed(KeyCode::KEY_SPACE);

    if(spacePressed)
        _container
            ->_sceneManager
            ->LoadScene(_container->_sceneManager->GetActiveScene().first);
}