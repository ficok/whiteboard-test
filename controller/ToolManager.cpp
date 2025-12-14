#include "ToolManager.hpp"
#include "Tool.hpp"

ToolManager* ToolManager::_instance = nullptr;
ToolManager::ToolManager() {}

ToolManager& ToolManager::instance() {
    if (_instance == nullptr)
        _instance = new ToolManager();

    return *_instance;
}

Tool& ToolManager::activeTool() const {
    return *_activeTool;
}
void ToolManager::activeTool(Tool* tool) {
    _activeTool = tool;
}
