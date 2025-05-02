#ifndef SELECTOR_TOOL_H
#define SELECTOR_TOOL_H

#include <bobcat_ui/all.h>
#include "Color.h"
#include "Enums.h"

class SelectorTool{
    bobcat::Button* selectButton;


public:
    SelectorTool();

    friend struct AppTest;
};

#endif