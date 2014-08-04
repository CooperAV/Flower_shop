#include "StdAfx.h"
#include "Category.h"
#include <conio.h>

Category::Category(LPWSTR pLibrary)
{
	nComplete = 0;
	DataLoaded = false;
	srand(time(NULL));
	InitFunc Init;
	m_hMode = LoadLibrary(pLibrary);
	if(m_hMode==NULL)
	{
		std::cout << "Error " << pLibrary << " !!!" << std::endl;
		_getche();
		return;
	}
	else
	{
		Init = (InitFunc)GetProcAddress(m_hMode, "Init");
		if(Init==NULL)
		{
			return;
		}
		nComplete++;
		if(!GetProcAddress(m_hMode, "GetLibraryName"))
		{
			return;
		}
		nComplete++;
		if(!GetProcAddress(m_hMode, "GetPushBackName"))
		{
			return;
		}
		nComplete++;
		pF = fopen(GetLibraryName(), "rb");
		if(pF == NULL)
			nChoice = 1;
		else
		{
			nChoice = rand()%2 + 1;
		}
	}
	m_pBase_Factory = Init();
	if(m_pBase_Factory && m_pBase_Factory->IsComplete())
	{
		m_pBase_Input = m_pBase_Factory->GetInput();
		m_pBase_Output = m_pBase_Factory->GetOutput();
		m_pBase_File = m_pBase_Factory->GetOutFile();
		DataLoaded = LoadFile();
	}
}
Category::~Category()
{
	unsigned int nCountProd = m_pProd.size();
	for(unsigned int i=0; i<nCountProd; ++i)
		delete m_pProd[i];
	if(m_hMode != NULL)
	{
		if(IsComplete())
		{
			Get_PushBack_Func GetPushBackName = (Get_PushBack_Func)GetProcAddress(m_hMode, "GetPushBackName");
			if(-1 == remove(GetPushBackName()))
				std::cout << "\nSaving the file was successful\n";
			delete m_pBase_Factory;
			if (pF)
				fclose(pF);
		}
		FreeLibrary(m_hMode);
	}
}

bool Category::IsComplete()
{
	return nComplete == 3 && m_pBase_Factory && m_pBase_Factory->IsComplete() && DataLoaded;
}
int Category::GetRandEvents()
{
	return nChoice;
}
char* Category::GetLibraryName()
{
	Get_Library_Func GetLibrary_Name = (Get_Library_Func)GetProcAddress(m_hMode, "GetLibraryName");
	return GetLibrary_Name();
}
void Category::InputNewProduct()
{
	Product* pProd = m_pBase_Input->InputProduct();
	if(pProd)
		m_pProd.push_back(pProd);
}
void Category::OutputProductList(bool ShowNumber)
{
	m_pBase_Output->ShowProductList(m_pProd, ShowNumber);
}
void Category::SaveFile()
{
	m_pBase_File->WriteFile(m_pProd);
}
bool Category::LoadFile()
{
	return m_pBase_File->ReadFile(m_pProd);
}
void Category::Push_Back()
{
	m_pBase_File->PushBack(m_pProd);
}
void Category::FindCriteria()
{
	m_pBase_Output->SearchByCriteria(m_pProd);
}
void Category::RefillProduct()
{
	m_pBase_Output ->RefillProduct(m_pProd);
}
int Category::GetProductCount()
{
	return GetCountProduct = m_pProd.size();
}
void Category::OutputProduct(int Index)
{
	m_pBase_Output->ShowProduct(m_pProd[Index]);
}
double Category::GetProductPriceByIndex(int Index)
{
	return m_pProd[Index]->GetPrice();
}
unsigned int Category::GetProductQuantityByIndex(int Index)
{
	return m_pProd[Index]->GetQuantity();
}
char* Category::GetProductNameByIndex(int Index)
{
	return m_pProd[Index]->GetName();
}
void Category::SetProductQuantityByIndex(int Index, unsigned int Quantity)
{
	m_pProd[Index]->SetQuantity(Quantity);
}
