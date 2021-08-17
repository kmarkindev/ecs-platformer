#pragma once

#include <filesystem>
#include <fstream>
#include <vector>

class AssetsManager
{
public:
    explicit AssetsManager(std::filesystem::path appFolderPath);
    ~AssetsManager() = default;
    std::vector<unsigned char> GetAssetData(const std::filesystem::path& assetName);

private:
    std::filesystem::path _appRootFolderPath;
};


