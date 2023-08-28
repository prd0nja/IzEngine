#include "Console.hpp"

#include <Windows.h>
#include <iostream>
#include "Console.hpp"

namespace IW3SR
{
    Console::Console()
    {
        AllocConsole();

        freopen_s(reinterpret_cast<FILE**>(stdin), "CONIN$", "r", stdin);
        freopen_s(reinterpret_cast<FILE**>(stdout), "CONOUT$", "w", stdout);
        freopen_s(reinterpret_cast<FILE**>(stderr), "CONOUT$", "w", stderr);
    }

    Console::~Console()
    {
        FreeConsole();
    }
}
