// MakroSandbox.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"

int main(int argc, char** argv)
{
	WindowHandler WHND;
	InputHandler InHND(argc, argv);
	InHND.GetKey(InHND.CheckParameter("-f"), &WHND);
	return 0;
}