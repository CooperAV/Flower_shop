#pragma once

#include "Base_File.h"
#include "Base_Input.h"
#include "Base_Output.h"
class Base_Factory
{
public:
	virtual Base_Input* GetInput()=0;
	virtual Base_Output* GetOutput()=0;
	virtual Base_File* GetOutFile()=0;
private:
};
