
#include <iostream>
#include <windows.h>
HHOOK hHook;
LRESULT CALLBACK KeyHookProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	if ((nCode == HC_ACTION) && ((wParam == WM_SYSKEYDOWN) || (wParam == WM_KEYDOWN)))
	{
		KBDLLHOOKSTRUCT*pKB = (KBDLLHOOKSTRUCT*)lParam;
	}
	return CallNextHookEx(hHook, nCode, wParam, lParam);
}
void gdiscreen()
{
	while (true)
	{
		hHook = SetWindowsHookEx(WH_KEYBOARD_LL, (HOOKPROC)KeyHookProc, 0, 0);
		if (GetAsyncKeyState(VK_F3))
		{
			POINT mouse;
			GetCursorPos(&mouse);
			printf("x,y:%d,%d\n", mouse.x,mouse.y);
			Sleep(200);
		}
		if (GetAsyncKeyState(VK_F6))
		{
			system(R"("netsh wlan disconnect interface="Wi-Fi"")");
			system(R"("netsh wlan connect name="..." interface="Wi-Fi"")");
			Sleep(100);
		}
		Sleep(100);
	}
}



int main()
{

	SetWindowText(GetConsoleWindow(), (LPCWSTR)"");
	ShowWindow(GetConsoleWindow(), SW_HIDE); //hide
	gdiscreen();
	return 0;
}
