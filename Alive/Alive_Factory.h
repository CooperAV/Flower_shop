#pragma once

#include "../Flower_shop/Base_Factory.h"
#include "../Flower_shop/Base_Input.h"
#include "../Flower_shop/Base_Output.h"
#include "../Flower_shop/Base_File.h"
#include "Alive_Input.h"
#include "Alive_Output.h"
#include "Alive_File.h"

class Alive_Factory: public Base_Factory
{
public:
	Alive_Factory();
	virtual ~Alive_Factory();

	Base_Input* GetInput();
	Base_Output* GetOutput();
	Base_File* GetOutFile();
private:
	Alive_Input *m_pA_In;
	Alive_Output *m_pA_Out;
	Alive_File *m_pA_File;
};
