// UnAlive.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "UnAlive.h"
#include "UnAlive_Factory.h"
#include "UnAlive_Product.h"
#include "UnAlive_File.h"
#include "UnAlive_Input.h"
#include "UnAlive_Output.h"


extern "C" UNALIVE_API Base_Factory* Init()
{
	UnAlive_Factory* pFactory = NULL;
	try{
		pFactory = new UnAlive_Factory();
	}
	catch(...)
	{
		std::cout << "Error creating Alive_Factory\n";
	}
	return pFactory;
}

extern "C" UNALIVE_API char* GetLibraryName()
{
	char* Name = "UnAlive_product.txt";
	return  Name;
}

extern "C" UNALIVE_API char* GetPushBackName()
{
	char* Name = "Push_Back_UnAlive.txt";
	return  Name;
}
