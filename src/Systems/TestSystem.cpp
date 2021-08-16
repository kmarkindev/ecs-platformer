#include "TestSystem.h"

void TestSystem::Init(Scene& scene)
{
    scene.GetEventListener().Subscribe<CollisionExit>([](CollisionExit& event)
    {
        DependencyContainer::GetInstance()->_sceneManager->LoadScene(0);
    });
}

void TestSystem::Update(Scene& scene)
{

}