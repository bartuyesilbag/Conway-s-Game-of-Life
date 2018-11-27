#ifndef GLOBALVERIABLES_H
#define GLOBALVERIABLES_H

#include <vector>

typedef std::vector<std::vector<bool>> CONTAINER;

enum class INPUTS
{
    BACKSPACE = 0,
    ARROW_KEYS,
    CHARACTER,
    EXECUTE
};

#endif