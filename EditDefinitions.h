#pragma once
#include <WinUser.h>
#include <Windows.h>


LRESULT CALLBACK SoftwareEditProcedure(HWND hWnd1, UINT msg1, WPARAM wp1, LPARAM lp1);
WNDCLASS NewEditClass(HBRUSH BGColor, HCURSOR Cursor, HINSTANCE hInst1, HICON Icon1, LPCWSTR Name1, WNDPROC Procedure1);


	int WINAPI EditMain(HINSTANCE hInst1, HINSTANCE hPrevInst1, LPSTR args1, int ncmdshow1)
	{
		WNDCLASS SoftwareEditClass = NewEditClass((HBRUSH)COLOR_WINDOW, LoadCursor(NULL, IDC_ARROW), hInst1,
			LoadIcon(hInst1, MAKEINTRESOURCE(IDI_ICON1)), L"EditWndClass", SoftwareEditProcedure);
		if (!RegisterClassW(&SoftwareEditClass)) { return -1; }
		MSG SoftwareEditMessage = { 0 };

		CreateWindow(L"EditWndClass", L"Window for edit info", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 700, 100, 800, 380, NULL, NULL, NULL, NULL);

		while (GetMessage(&SoftwareEditMessage, NULL, NULL, NULL))
		{
			TranslateMessage(&SoftwareEditMessage);
			DispatchMessage(&SoftwareEditMessage);
		}

	}

	WNDCLASS NewEditClass(HBRUSH BGColor, HCURSOR Cursor, HINSTANCE hInst1, HICON Icon1, LPCWSTR Name1, WNDPROC Procedure1)
	{
		WNDCLASS NWC = { 0 };

		NWC.hIcon = Icon1;
		NWC.hCursor = Cursor;
		NWC.hInstance = hInst1;
		NWC.lpszClassName = Name1;
		NWC.hbrBackground = BGColor;
		NWC.lpfnWndProc = Procedure1;

		return NWC;
	}
	LRESULT CALLBACK SoftwareEditProcedure(HWND hWnd1, UINT msg1, WPARAM wp1, LPARAM lp1)
	{
		switch (msg1)
		{

		case WM_CREATE:
			EditWndAddMenus(hWnd1);
			EditWndAddWidgets(hWnd1);
			break;
		case WM_DESTROY:
			PostQuitMessage(0);
		default: return DefWindowProc(hWnd1, msg1, wp1, lp1);
		}

	}
	void EditWndAddMenus(HWND hWnd1)
	{
		HMENU RootMenu1 = CreateMenu();

		SetMenu(hWnd1, RootMenu1);
	}
	void EditWndAddWidgets(HWND hWnd1)
	{
		CreateWindowA("static", "This form create for edit fields", WS_VISIBLE | WS_CHILD | ES_CENTER, 5, 5, 400, 50, hWnd1, NULL, NULL, NULL);


	};







