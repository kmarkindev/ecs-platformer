#include "AssetsManager.h"

std::vector<unsigned char> AssetsManager::GetAssetData(const std::filesystem::path& assetPath)
{
    auto finalPath = _appRootFolderPath / "resources" / assetPath;
    auto assetSize = std::filesystem::file_size(finalPath);

    if(!std::filesystem::exists(finalPath))
        throw std::invalid_argument("Cannot find such asset");

    std::vector<unsigned char> data;
    data.reserve(assetSize);

    std::ifstream ifs;
    ifs.open(finalPath, std::ios::in | std::ios::binary);

    data.assign(std::istreambuf_iterator<char>(ifs), std::istreambuf_iterator<char>());

    return data;
}

AssetsManager::AssetsManager(std::filesystem::path appFolderPath)
    : _appRootFolderPath(std::move(appFolderPath))
{

}