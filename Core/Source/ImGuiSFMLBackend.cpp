#include "ImGuiSFMLBackend.hpp"

#include "imgui-SFML.h"

ImGuiSFMLBackend::ImGuiSFMLBackend(sf::RenderWindow& renderWindow)
: m_RenderWindow(renderWindow) {
    if (!ImGui::SFML::Init(renderWindow)) {
        throw std::runtime_error("Failed to initialize ImGui-SFML backend");
    }
}

ImGuiSFMLBackend::~ImGuiSFMLBackend() {
    ImGui::SFML::Shutdown();
}

void ImGuiSFMLBackend::processEvent(const sf::Event& event) {
    ImGui::SFML::ProcessEvent(m_RenderWindow, event);
}

void ImGuiSFMLBackend::update() {
    ImGui::SFML::Update(m_RenderWindow, m_DeltaClock.restart());
}

void ImGuiSFMLBackend::render() {
    ImGui::SFML::Render(m_RenderWindow);
}
