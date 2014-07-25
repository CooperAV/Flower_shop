#pragma once

#include "Product.h"
#include "Base_File.h"
#include "Base_Input.h"
#include "Base_Output.h"
#include "Base_Factory.h"
#include <time.h>

typedef char*(*Get_Library_Func)();
typedef char*(*Get_PushBack_Func)();
typedef Base_Factory*(*InitFunc)();
int GetInputNumber();

class Category	//Класс связывающий всю бизнес-логику программы !!!
{
public:
	Category(LPWSTR pLibrary);
	~Category();

	void InputNewProduct();
	void OutputProduct();
	void SaveFile();
	void LoadFile();
	void Push_Back();
	void Sell_Product();
	bool IsComplete();
	char* GetLibraryName();
	int GetRandEvents();
	void FindCriteria();
	void RefillProduct();
private:
	double ClientPoket;
	int nComplete;
	int nChoice;
	HMODULE m_hMode;
	FILE *pF;
	Base_Factory* m_pBase_Factory;
	Base_Input* m_pBase_Input;
	Base_Output* m_pBase_Output;
	std::vector<Product*> m_pProd;
	Base_File* m_pBase_File;
};