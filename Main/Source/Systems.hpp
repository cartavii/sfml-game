#ifndef SYSTEMS_HPP
#define SYSTEMS_HPP

#include <entt/entt.hpp>
#include <filesystem>
#include <SFML/Graphics/RenderTarget.hpp>

void MovementSystem(entt::registry& registry, float deltaTime);

void SaveSystem(entt::registry& registry, const std::filesystem::path& filename);

void LoadSystem(entt::registry& registry, const std::filesystem::path& filename);

void RenderSystem(entt::registry& registry, sf::RenderTarget& target);

#endif //SYSTEMS_HPP
