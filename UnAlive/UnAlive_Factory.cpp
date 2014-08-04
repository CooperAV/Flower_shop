#include "StdAfx.h"
#include "UnAlive_Factory.h"
#include "UnAlive_Product.h"
#include <conio.h>


UnAlive_Factory::UnAlive_Factory()
{
	UnAlive_Input_Created = false;
	UnAlive_Output_Created = false;
	UnAlive_File_Created = false;
	try{
	m_pUnA_In = new UnAlive_Input();
	UnAlive_Input_Created = true;
	m_pUnA_Out = new UnAlive_Output();
	UnAlive_Output_Created = true;
	m_pUnA_File = new UnAlive_File();
	UnAlive_File_Created = true;
	}
	catch(std::bad_alloc)
	{
		if(UnAlive_Input_Created)
			delete m_pUnA_In;
		else
			std::cout << "Error creating Alive_Input\n";
		if(UnAlive_Output_Created)
			delete m_pUnA_Out;
		else
			std::cout << "Error creating Alive_Output\n";
		if(UnAlive_File_Created)
			delete m_pUnA_File;
		else
			std::cout << "Error creating Alive_File\n";
	}
}
UnAlive_Factory::~UnAlive_Factory()
{
	delete m_pUnA_In;
	delete m_pUnA_Out;
	delete m_pUnA_File;
}

bool UnAlive_Factory::IsComplete()
{
	return UnAlive_Input_Created && UnAlive_Output_Created && UnAlive_File_Created;
}
Base_Input* UnAlive_Factory::GetInput()
{
	return m_pUnA_In;
}
Base_Output* UnAlive_Factory::GetOutput()
{
	return m_pUnA_Out;
}
Base_File* UnAlive_Factory::GetOutFile()
{
	return m_pUnA_File;
}
