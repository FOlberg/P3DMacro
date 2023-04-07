#include "stdafx.h"

InputHandler::InputHandler( int argc, char** argv ) : argc(argc), argv(argv ) {}

bool InputHandler::CheckParameter( std::string parameter )
{
	if (argc > 1) //Checking arguments
	{
		for (int i = 0; i < argc; i++)
		{
			if (static_cast<std::string>(argv[i]).find(parameter) != std::string::npos)
			{
				std::cout << "Focus on Prepar3D is active!" << std::endl;
				return true;
			}
		}
	}
	return false;
}

void InputHandler::GetKey( bool focus, WindowHandler *WHND )
{
	while (true)
	{
		bool prev = false;
		while (!focus || (focus && WHND->CheckFlightSimFocus()))
		{
			if (((GetAsyncKeyState(VK_XBUTTON1) & 0x8000) || (GetAsyncKeyState(VK_XBUTTON2) & 0x8000) || (GetAsyncKeyState(VK_MBUTTON) & 0x8000)) && !prev)
			{
				prev = true;
				PressKey();
				std::cout << "Pressed " << std::endl; //Output
			}
			else if (((GetAsyncKeyState(VK_XBUTTON1) & 0x8000) || (GetAsyncKeyState(VK_XBUTTON2) & 0x8000) || (GetAsyncKeyState(VK_MBUTTON) & 0x8000)) && prev)
			{
				prev = true;
			}
			else if (!((GetAsyncKeyState(VK_XBUTTON1) & 0x8000) || (GetAsyncKeyState(VK_XBUTTON2) & 0x8000) || (GetAsyncKeyState(VK_MBUTTON) & 0x8000)) && prev)
			{
				PressKey();
				prev = false;
			}
			else prev = false;
			Sleep(100);
		}
		Sleep(100);
	}
}

void InputHandler::PressKey( void )
{
	keybd_event(VK_SCROLL, 0, 0, 0);
	//keybd_event(VK_CONTROL, 0, 0, 0);

	//keybd_event(VK_SHIFT, 0, 0, 0);

	//keybd_event(VK_F2, 0, 0, 0);

	//keybd_event(VK_F2, 0, KEYEVENTF_KEYUP, 0);

	//keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);

	//keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0);
}