#include "Application/AppParams.h"
#include "Application/Application.h"

int main(int argc, char** argv)
{
    auto params = AppParams(argc, argv);
    auto app = Application(params);

    while(app.Update());

    return 0;
}