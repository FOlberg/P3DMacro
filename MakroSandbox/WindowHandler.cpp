#include "stdafx.h"

bool WindowHandler::CheckFlightSimFocus()
{
	char wnd_title[256];
	HWND hwnd = GetForegroundWindow(); // get handle of currently active window
	GetWindowTextA(hwnd, wnd_title, 256);
	return static_cast<std::string>(wnd_title).find("Prepar3D") != std::string::npos;
}