#include "GUIPanel.hpp"

#include "imgui.h"

void GUIPanel::show() {
    if (ImGui::Begin("Panel")) {
        render();
    }
    ImGui::End();
}

Event<>& GUIPanel::getGenerateEvent() {
    return m_GenerateEvent;
}

Event<>& GUIPanel::getClearEvent() {
    return m_ClearEvent;
}

Event<>& GUIPanel::getSaveEvent() {
    return m_SaveEvent;
}

Event<>& GUIPanel::getLoadEvent() {
    return m_LoadEvent;
}

void GUIPanel::render() {
    ImGui::SeparatorText("Rectangle");
    if (ImGui::Button("Spawn rectangle")) {
        m_GenerateEvent.emit();
    }
    if (ImGui::Button("Clear rectangles")) {
        m_ClearEvent.emit();
    }
    ImGui::SeparatorText("File");
    if (ImGui::Button("Save")) {
        m_SaveEvent.emit();
    }
    if (ImGui::Button("Load last")) {
        m_LoadEvent.emit();
    }
}
