#pragma once

class Tool;
/**
 * @brief The ToolManager class
 * cuva trenutno aktivan tool.
 *
 * singleton klasa
 *
 * treba da daje referncu na aktivan tool i na isti nacin da daje
 * aktivna sva zajednicka podesavanja (boja, debljina itd). to drugo treba dodati.
 */
class ToolManager {
private:
    static ToolManager* _instance;
    ToolManager();
    ~ToolManager() = default;

    Tool* _activeTool;

public:
    static ToolManager* instance();
    ToolManager(const ToolManager& other) = delete;
    ToolManager(ToolManager&& other) = delete;
    ToolManager& operator=(const ToolManager& other) = delete;
    ToolManager& operator=(ToolManager&& other) = delete;

    Tool& activeTool() const;
    void activeTool(Tool* tool);
};
