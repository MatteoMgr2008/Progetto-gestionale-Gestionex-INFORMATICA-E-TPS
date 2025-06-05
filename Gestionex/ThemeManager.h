#pragma once
#ifndef THEMEMANAGER_H
#define THEMEMANAGER_H

#include "imgui.h"

class ThemeManager {
public:
    enum Theme {
        LIGHT = 0,
        DARK = 1
    };

    static ThemeManager& getInstance() {
        static ThemeManager instance;
        return instance;
    }

    void setTheme(Theme newTheme) {
        currentTheme = newTheme;
        applyTheme();
    }

    Theme getCurrentTheme() const {
        return currentTheme;
    }

    int getCurrentThemeInt() const {
        return static_cast<int>(currentTheme);
    }

    void setThemeFromInt(int themeValue) {
        if (themeValue >= 0 && themeValue <= 1) {
            setTheme(static_cast<Theme>(themeValue));
        }
    }

private:
    Theme currentTheme = DARK; // Tema predefinito

    ThemeManager() = default;
    ~ThemeManager() = default;
    ThemeManager(const ThemeManager&) = delete;
    ThemeManager& operator=(const ThemeManager&) = delete;

    void applyTheme() {
        ImGuiStyle& style = ImGui::GetStyle();

        if (currentTheme == LIGHT) {
            ImGui::StyleColorsLight();
            style.Colors[ImGuiCol_WindowBg] = ImVec4(0.9f, 0.9f, 0.9f, 1.0f);
        }
        else if (currentTheme == DARK) {
            ImGui::StyleColorsDark();
            style.Colors[ImGuiCol_WindowBg] = ImVec4(0.1f, 0.1f, 0.1f, 1.0f);
        }
    }
};

#endif // THEMEMANAGER_H