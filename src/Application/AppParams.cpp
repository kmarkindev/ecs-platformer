#include "AppParams.h"

AppParams::AppParams(int argc, char** argv)
{
    _rootFolder = argv[0];
}

std::filesystem::path AppParams::GetAppRootFolder()
{
    return _rootFolder;
}
