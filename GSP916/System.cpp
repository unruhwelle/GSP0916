#include "System.h"

#include <Windows.h>

LRESULT CALLBACK WndProc(HWND hWnd, UINT p_Type, WPARAM p_WParam, LPARAM p_LParam)
{
	if (p_Type == WM_DESTROY)
	{
		PostQuitMessage(1);
	}

	return DefWindowProc(hWnd, p_Type, p_WParam, p_LParam);
}

void System::Init()
{
	// Erstellen der Windowclass
	// Windowclass ist quasi ein Fensterbauplan
	WNDCLASSEX _Windowclass;
	ZeroMemory(&_Windowclass, sizeof(_Windowclass));

	_Windowclass.cbSize = sizeof(WNDCLASSEX);
	_Windowclass.lpszClassName = "WindowBauplan";

	_Windowclass.style = CS_HREDRAW | CS_VREDRAW;
	_Windowclass.hInstance = GetModuleHandle(0);
	_Windowclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	_Windowclass.hbrBackground = (HBRUSH)COLOR_GRAYTEXT;
	_Windowclass.lpfnWndProc = &WndProc;

	// Registrieren der Windowclass
	RegisterClassEx(&_Windowclass);

	// (optional) Windowrect erzeugen und anpassen
	RECT _WindowRect;
	_WindowRect.left = 100;
	_WindowRect.right = 900;
	_WindowRect.top = 100;
	_WindowRect.bottom = 700;

	AdjustWindowRect(&_WindowRect, WS_OVERLAPPEDWINDOW, false);

	// Fenster erzeugen
	HWND _Wnd = CreateWindowEx(0,
		"WindowBauplan",
		"Mein erstes Fenster",
		WS_OVERLAPPEDWINDOW,
		_WindowRect.left,
		_WindowRect.top,
		_WindowRect.right - _WindowRect.left,
		_WindowRect.bottom - _WindowRect.top,
		NULL,
		NULL,
		GetModuleHandle(0),
		NULL);


	// Fenster anzeigen
	ShowWindow(_Wnd, SW_SHOWDEFAULT);
}


int System::Run()
{
	int QuitCode = 0;
	bool Running = true;
	MSG _msg;

	while (Running)
	{
		// Fenster Updaten
		while (PeekMessage(&_msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&_msg);
			DispatchMessage(&_msg);
		
			if (_msg.message == WM_QUIT)
			{
				QuitCode = _msg.wParam;
				Running = false;
			}
		}



		// Frame Updaten 10 ms

		// Frame zeichnen 30 ms
	}

	// Resourcen wieder freigeben

	return QuitCode;
}