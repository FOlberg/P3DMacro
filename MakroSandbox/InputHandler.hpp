#pragma once
#include "WindowHandler.hpp"

class InputHandler
{
private:
	int argc;
	char** argv;
public:
	InputHandler( int argc, char** argv );
	bool CheckParameter( std::string parameter );
	void GetKey( bool focus, WindowHandler *WHND );
	void PressKey( void );
};