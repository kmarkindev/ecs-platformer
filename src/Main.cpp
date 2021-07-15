#include "Application.h"

int main()
{
    auto app = Application();

    while(app.Update());

    return 0;
}