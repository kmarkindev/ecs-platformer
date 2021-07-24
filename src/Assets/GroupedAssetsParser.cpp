#include "GroupedAssetsParser.h"

std::vector<unsigned char> GroupedAssetsParser::ParseData(
        const std::vector<unsigned char>& data, const std::string& key) const
{
    //find @@BEGIN@KEY_HERE@@...content_to_return_here...@@END@KEY_HERE@@
    //if no content - throw exception

    std::string strData = std::string(data.begin(), data.end());

    auto startKey = std::string("@@BEGIN@" + key + "@@");
    auto endKey = std::string("@@END@" + key + "@@");

    auto startPos = strData.find(startKey);
    auto endPos = strData.find(endKey);

    if(startPos == std::string::npos || endPos == std::string::npos)
        throw std::invalid_argument("Cannot find given key in data. There are not Start and/or End marks.");

    return std::vector<unsigned char>(strData.begin() + startPos + startKey.size(),
                                      strData.begin() + endPos);
}
