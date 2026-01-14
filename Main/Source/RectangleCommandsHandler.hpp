#ifndef RECTANGLECOMMANDSHANDLER_HPP
#define RECTANGLECOMMANDSHANDLER_HPP

#include "RectangleCommands.hpp"

struct RectangleCommandsHandler {
    RectangleCommandGenerate m_Generate;
    RectangleCommandClear m_Clear;
    RectangleCommandSave m_Save;
    RectangleCommandLoadLast m_LoadLast;
};

#endif //RECTANGLECOMMANDSHANDLER_HPP
