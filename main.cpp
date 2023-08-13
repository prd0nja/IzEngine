#include <iostream>
#include <windows.h>
#include <tlhelp32.h>

#include "main.hpp"

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  dwReason, LPVOID lpReserved) {
    switch (dwReason) {
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

        default: std::cout << "An Unexpected Error has Occurred." << std::endl; break;
    }

    return TRUE;
}

DWORD GetProcessIdByName(const char* processName) {
    PROCESSENTRY32 processEntry;
    processEntry.dwSize = sizeof(PROCESSENTRY32);

    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (Process32First(snapshot, &processEntry)) {
        while (Process32Next(snapshot, &processEntry)) {
            if (_stricmp(processEntry.szExeFile, processName) == 0) {
                CloseHandle(snapshot);
                return processEntry.th32ProcessID;
            }
        }
    }

    CloseHandle(snapshot);
    return 0;
}

int OnAttach() {
    DWORD PID = GetProcessIdByName("iw3mp.exe");
    if(AllocConsole()) AttachConsole(PID);
    else return -1;

    return 0;
}
