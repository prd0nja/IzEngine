#include <iostream>
#include <windows.h>
#include <tlhelp32.h>

#include "main.hpp"

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  dwReason, LPVOID lpReserved) 
{
    switch (dwReason) 
    {
        case DLL_PROCESS_ATTACH:
            OnAttach();
            break;
        case DLL_THREAD_ATTACH:
            break;
        case DLL_THREAD_DETACH:
            break;
        case DLL_PROCESS_DETACH:
            FreeConsole();
            break;
        default: 
            std::cout << "An Unexpected Error has Occurred." << std::endl;
            break;
    }
    return TRUE;
}

int OnAttach() 
{
    AllocConsole();

    freopen_s((FILE**)stdin, "CONIN$", "r", stdin);
    freopen_s((FILE**)stdout, "CONOUT$", "w", stdout);
    freopen_s((FILE**)stderr, "CONOUT$", "w", stderr);

    return 0;
}
