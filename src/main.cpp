#include "Game/Game.hpp"

#include <thread>
#include <memory>
#include <Windows.h>
#include <iostream>

ENTRY void Init()
{
    SR = new Game();
    SR->Initialize();
}

ENTRY void Shutdown()
{
    delete SR;
    Environment::Save();
}

ENTRY BOOL STDCALL RIB_Main(HANDLE handle, INT upDown)
{
    return TRUE;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved) 
{
    switch (dwReason) 
    {
        case DLL_PROCESS_ATTACH:
            Init();
            break;
        case DLL_THREAD_ATTACH:
            break;
        case DLL_THREAD_DETACH:
            break;
        case DLL_PROCESS_DETACH:
            Shutdown();
            break;
        default: 
            break;
    }
    return TRUE;
}
