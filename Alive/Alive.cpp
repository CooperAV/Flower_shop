// Alive.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Alive.h"
#include "Alive_Factory.h"
#include "Alive_Product.h"
#include "Alive_File.h"
#include "Alive_Input.h"
#include "Alive_Output.h"


extern "C" ALIVE_API Base_Factory* Init()
{
	Alive_Factory* pFactory = NULL;
	try{
		pFactory = new Alive_Factory();
	}
	catch(...)
	{
		std::cout << "Error creating Alive_Factory\n";
	}
	return pFactory;
}

extern "C" ALIVE_API char* GetLibraryName()
{
	char* Name = "Alive_product.txt";
	return  Name;
}

extern "C" ALIVE_API char* GetPushBackName()
{
	char* Name = "Push_Back_Alive.txt";
	return  Name;
}
