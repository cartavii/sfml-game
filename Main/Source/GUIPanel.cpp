#include "GUIPanel.hpp"

#include "imgui.h"

GUIPanel::GUIPanel(RectanglesManager& rectanglesManager)
: m_RectanglesManager(rectanglesManager) {}

void GUIPanel::show() {
    if (ImGui::Begin("Panel")) {
        render();
    }
    ImGui::End();
}

void GUIPanel::render() {
    ImGui::SeparatorText("Rectangle");
    if (ImGui::Button("Spawn rectangle")) {
        m_RectanglesManager.generate(sf::View({ 400, 300 }, { 800, 600 }));
    }
    if (ImGui::Button("Clear rectangles")) {
        m_RectanglesManager.clearAll();
    }
    ImGui::SeparatorText("File");
    if (ImGui::Button("Save")) {
        m_RectanglesManager.save();
    }
    if (ImGui::Button("Load last")) {
        m_RectanglesManager.loadLast();
    }
}
