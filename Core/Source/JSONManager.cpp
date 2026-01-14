#include "JSONManager.hpp"
#include <fstream>

void JSONManager::save(const nlohmann::json& data, const std::filesystem::path& filePath) {
    std::ofstream file(filePath);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file");
    }
    file << data.dump(4);
    file.close();
}

nlohmann::json JSONManager::load(const std::filesystem::path& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file");
    }
    nlohmann::json data;
    file >> data;
    file.close();
    return data;
}
