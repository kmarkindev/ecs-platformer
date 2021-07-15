#include "Application.h"

Application::Application()
    : _window("Platformer", 800, 600, false)
{

}

bool Application::Update()
{
    _window.PollEvents();

    if(_window.HasCloseSignal())
        return false;

    

    _window.SwapBuffers();

    return true;
}