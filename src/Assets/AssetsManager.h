#pragma once

#include <filesystem>
#include <fstream>

class AssetsManager
{
public:
    explicit AssetsManager(std::filesystem::path appFolderPath);
    ~AssetsManager();
    std::ifstream GetAssetStream(const std::filesystem::path& assetName);
private:
    std::filesystem::path _appRootFolderPath;
};


