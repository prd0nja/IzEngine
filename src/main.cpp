#include <iostream>
#include <thread>
#include <memory>
#include <vector>
#include <algorithm>
#include <functional>
#include <windows.h>
#include <Psapi.h>
#include <MinHook.h>

#include "Sys/Hook.hpp"
#include "Sys/Memory.hpp"
#include "Sys/Log.hpp"
#include "Modules/Sys/Console.hpp"

using namespace IW3SR;

const DWORD COD4XEntry = reinterpret_cast<DWORD>(GetModuleHandleA("cod4x_021.dll"));

void Shutdown()
{
    MH_Uninitialize();
}

void Init()
{
    MH_Initialize();

    std::unique_ptr<Log> log = std::make_unique<Log>();
    std::unique_ptr<Console> console = std::make_unique<Console>();

    uintptr_t antiHook = COD4XEntry + 0x43580;
    uintptr_t aimAssist = 0x452BFA;
    uintptr_t localTagMatrix = 0x434200;

    Memory::Write(antiHook, "\xC3", 1);
    Memory::Write(aimAssist, "\xE8\xA1\xF9\xFA\xFF", 5);
    Memory::Write(localTagMatrix, "\x51\x53\x8B\x5C\x24", 5);

    while (true)
        Sleep(500);
    Shutdown();
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  dwReason, LPVOID lpReserved) 
{
    switch (dwReason) 
    {
        case DLL_PROCESS_ATTACH:
            std::thread(Init).detach();
            break;
        case DLL_THREAD_ATTACH:
            break;
        case DLL_THREAD_DETACH:
            break;
        case DLL_PROCESS_DETACH:
            // @TODO set a condition variable to stop the thread loop.
            break;
        default: 
            break;
    }
    return TRUE;
}
