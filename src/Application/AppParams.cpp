#include "AppParams.h"

AppParams::AppParams(int argc, char** argv)
{
    _rootFolder = argv[0];
    _rootFolder = _rootFolder.parent_path();
}

std::filesystem::path AppParams::GetAppRootFolder()
{
    return _rootFolder;
}
