#include "AssetsManager.h"

std::ifstream AssetsManager::GetAssetStream(const std::filesystem::path& assetPath)
{
    auto finalPath = _appRootFolderPath / assetPath;

    std::ifstream ifs;
    ifs.open(finalPath, std::fstream::in);
    return std::move(ifs);
}

AssetsManager::AssetsManager(std::filesystem::path appFolderPath)
    : _appRootFolderPath(std::move(appFolderPath))
{

}

AssetsManager::~AssetsManager()
{

}
