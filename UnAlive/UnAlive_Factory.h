#pragma once

#include "../Flower_shop/Base_Factory.h"
#include "../Flower_shop/Base_Input.h"
#include "../Flower_shop/Base_Output.h"
#include "../Flower_shop/Base_File.h"
#include "UnAlive_Input.h"
#include "UnAlive_Output.h"
#include "UnAlive_File.h"

class UnAlive_Factory: public Base_Factory
{
public:
	UnAlive_Factory();
	virtual ~UnAlive_Factory();

	Base_Input* GetInput();
	Base_Output* GetOutput();
	Base_File* GetOutFile();
private:
	UnAlive_Input *m_pUnA_In;
	UnAlive_Output *m_pUnA_Out;
	UnAlive_File *m_pUnA_File;
};