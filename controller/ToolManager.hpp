#pragma once

class Tool;

class ToolManager {
private:
    static ToolManager* _instance;
    ToolManager();
    ~ToolManager() = default;

    Tool* _activeTool;

public:
    static ToolManager& instance();
    ToolManager(const ToolManager& other) = delete;
    ToolManager(ToolManager&& other) = delete;
    ToolManager& operator=(const ToolManager& other) = delete;
    ToolManager& operator=(ToolManager&& other) = delete;

    Tool& activeTool() const;
    void activeTool(Tool* tool);
};
