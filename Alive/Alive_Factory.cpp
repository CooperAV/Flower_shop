#include "StdAfx.h"
#include "Alive_Factory.h"
#include "Alive_Product.h"


Alive_Factory::Alive_Factory()
{
	try{
	m_pA_In = new Alive_Input();
	m_pA_Out = new Alive_Output();
	m_pA_File = new Alive_File();
	}
	catch(std::bad_alloc)
	{
		std::cout << "Exception(Alive_Factory)!!!";
		return;
	}
}
Alive_Factory::~Alive_Factory()
{
	delete m_pA_In;
	delete m_pA_Out;
	delete m_pA_File;
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