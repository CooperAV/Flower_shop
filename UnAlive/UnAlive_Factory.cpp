#include "StdAfx.h"
#include "UnAlive_Factory.h"
#include "UnAlive_Product.h"
#include <conio.h>


UnAlive_Factory::UnAlive_Factory()
{
	try{
	m_pUnA_In = new UnAlive_Input();
	m_pUnA_Out = new UnAlive_Output();
	m_pUnA_File = new UnAlive_File();
	}
	catch(std::bad_alloc)
	{
		std::cout << "Exception!!!";
		_getch();
		return;
	}
}
UnAlive_Factory::~UnAlive_Factory()
{
	delete m_pUnA_In;
	delete m_pUnA_Out;
	delete m_pUnA_File;
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
