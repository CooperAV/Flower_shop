#include "StdAfx.h"
#include "Alive_Factory.h"
#include "Alive_Product.h"

Alive_Factory::Alive_Factory()
{
	Alive_Input_Created = false;
	Alive_Output_Created = false;
	Alive_File_Created = false;
	try{
	m_pA_In = new Alive_Input();
	Alive_Input_Created = true;
	m_pA_Out = new Alive_Output();
	Alive_Output_Created = true;
	m_pA_File = new Alive_File();
	Alive_File_Created = true;
	}
	catch(std::bad_alloc)
	{
		if(Alive_Input_Created)
			delete m_pA_In;
		else
			std::cout << "Error creating Alive_Input\n";
		if(Alive_Output_Created)
			delete m_pA_Out;
		else
			std::cout << "Error creating Alive_Output\n";
		if(Alive_File_Created)
			delete m_pA_File;
		else
			std::cout << "Error creating Alive_File\n";
	}
}
Alive_Factory::~Alive_Factory()
{
	delete m_pA_In;
	delete m_pA_Out;
	delete m_pA_File;
}

bool Alive_Factory::IsComplete()
{
	return Alive_Input_Created && Alive_Output_Created && Alive_File_Created;
}
Base_Input* Alive_Factory::GetInput()
{
	return m_pA_In;
}
Base_Output* Alive_Factory::GetOutput()
{
	return m_pA_Out;
}
Base_File* Alive_Factory::GetOutFile()
{
	return m_pA_File;
}
