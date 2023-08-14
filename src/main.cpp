#include <iostream>
#include <windows.h>

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
//            FreeConsole();
            break;
        default: 
            std::cout << "An Unexpected Error has Occurred." << std::endl;
            break;
    }
    return TRUE;
}

int OnAttach() 
{
    if(AllocConsole())
    {
        SetConsoleOutputCP(65001); // UTF-8

        freopen_s(reinterpret_cast<FILE**>(&std::cin), "CONIN$", "r", stdin);
        freopen_s(reinterpret_cast<FILE**>(&std::cout), "CONOUT$", "w", stdout);

        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO CursoInfo;
        CursoInfo.dwSize = 1;
        CursoInfo.bVisible = false;
        SetConsoleCursorInfo(hConsole, &CursoInfo);

        std::cout << "Hello, world!" << std::endl;
    }
    else return -1;


    return 0;
}
