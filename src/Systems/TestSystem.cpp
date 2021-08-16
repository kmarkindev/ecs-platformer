#include "TestSystem.h"

void TestSystem::Init(Scene& scene)
{
    scene.GetEventListener().Subscribe<CollisionEnter>([](CollisionEnter& event)
    {
        DependencyContainer::GetInstance()->_window->RaiseCloseSignal();
    });
}

void TestSystem::Update(Scene& scene)
{

}