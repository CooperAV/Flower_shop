// Flower_shop.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Shop.h"

int _tmain(int argc, _TCHAR* argv[])
{
	{
	Shop sh;
	sh.Run();
	}
	std::cout << "\n\n=========================\n";
	if(_CrtDumpMemoryLeaks())
		std::cout << "Memory leaks\n";
	else
		std::cout << "All memory was returned\n\n";
	return 0;
}
