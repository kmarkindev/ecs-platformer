#pragma once

#include <filesystem>

class AppParams
{
public:
    AppParams(int argc, char** argv);
    std::filesystem::path GetAppRootFolder();
private:
    std::filesystem::path _rootFolder;
};


