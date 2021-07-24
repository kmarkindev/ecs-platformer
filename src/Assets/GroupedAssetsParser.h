#pragma once

#include <vector>
#include <string>
#include <stdexcept>

class GroupedAssetsParser
{
public:

    [[nodiscard]] std::vector<unsigned char> ParseData(
            const std::vector<unsigned char>& data, const std::string& key) const;

};


