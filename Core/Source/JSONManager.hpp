#ifndef JSONMANAGER_HPP
#define JSONMANAGER_HPP

#include "nlohmann/json.hpp"
#include <filesystem>

class JSONManager {
public:
    static void save(const nlohmann::json& data, const std::filesystem::path& filePath);
    static nlohmann::json load(const std::filesystem::path& filePath);
};

#endif //JSONMANAGER_HPP
