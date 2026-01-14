#include "GUIPanel.hpp"

#include "imgui.h"

GUIPanel::GUIPanel(RectangleCommandsHandler& commands)
: m_Commands(commands) {}

void GUIPanel::show() {
    if (ImGui::Begin("Panel")) {
        render();
    }
    ImGui::End();
}

void GUIPanel::render() {
    ImGui::SeparatorText("Rectangle");
    if (ImGui::Button("Spawn rectangle")) {
        m_Commands.m_Generate.execute();
    }
    if (ImGui::Button("Clear rectangles")) {
        m_Commands.m_Clear.execute();
    }
    ImGui::SeparatorText("File");
    if (ImGui::Button("Save")) {
        m_Commands.m_Save.execute();
    }
    if (ImGui::Button("Load last")) {
        m_Commands.m_LoadLast.execute();
    }
}
