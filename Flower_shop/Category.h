#pragma once

#include "Product.h"
#include "Base_File.h"
#include "Base_Input.h"
#include "Base_Output.h"
#include "Base_Factory.h"
#include "GetIntroducingNumber.h"
#include <time.h>

typedef char*(*Get_Library_Func)();
typedef char*(*Get_PushBack_Func)();
typedef Base_Factory*(*InitFunc)();

class Category	//Класс связывающий всю бизнес-логику программы !!!
{
public:
	Category(LPWSTR pLibrary);
	~Category();

	void InputNewProduct();
	void OutputProductList(bool ShowNumber = false);
	void SaveFile();
	bool LoadFile();
	void Push_Back();
	bool IsComplete();
	char* GetLibraryName();
	int GetRandEvents();
	void FindCriteria();
	void RefillProduct();
	int GetProductCount();
	void OutputProduct(int Index);
	double GetProductPriceByIndex(int Index);
	unsigned int GetProductQuantityByIndex(int Index);
	char* GetProductNameByIndex(int Index);
	void SetProductQuantityByIndex(int Index, unsigned int Quantity);
private:
	bool DataLoaded;
	int nComplete;
	int nChoice;
	int GetCountProduct;
	HMODULE m_hMode;
	FILE *pF;
	Base_Factory* m_pBase_Factory;
	Base_Input* m_pBase_Input;
	Base_Output* m_pBase_Output;
	std::vector<Product*> m_pProd;
	Base_File* m_pBase_File;
};
