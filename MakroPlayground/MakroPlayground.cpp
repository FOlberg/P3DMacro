#include <iostream>
#include <WinUser.h>

void GetKey();

int main()
{
	GetKey();
	return 0;
}

void GetKey()
{
	while (true)
	{
		_sleep(1);
		std::cout << "Taste: " << GetAsyncKeyState << std::endl;
	}
}