#include "StdAfx.h"
#include "Category.h"
#include <conio.h>

Category::Category(LPWSTR pLibrary)
{
	nComplete = 0;
	srand(time(NULL));
	ClientPoket = 200 + rand()%200;
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
	m_pBase_Input = m_pBase_Factory->GetInput();
	m_pBase_Output = m_pBase_Factory->GetOutput();
	m_pBase_File = m_pBase_Factory->GetOutFile();
	LoadFile();
}
Category::~Category()
{
	for(unsigned int i=0; i<m_pProd.size(); ++i)
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
	return nComplete == 3;
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
	m_pProd.push_back(m_pBase_Input->InputProduct());
}
void Category::OutputProduct()
{
	m_pBase_Output->ShowProduct(m_pProd);
}
void Category::SaveFile()
{
	m_pBase_File->WriteFile(m_pProd);
}
void Category::LoadFile()
{
	m_pBase_File->ReadFile(m_pProd);
}
void Category::Push_Back()
{
	m_pBase_File->PushBack(m_pProd);
}
void Category::Sell_Product()
{
	m_pBase_Output->SellProduct(m_pProd, ClientPoket);
}
void Category::FindCriteria()
{
	m_pBase_Output->SearchByCriteria(m_pProd, ClientPoket);
}
void Category::RefillProduct()
{
	m_pBase_Output ->RefillProduct(m_pProd);
}
int GetInputNumber()
{
	int iter = 0;
	char arr[6];
	char temp;
	while(true)
	{ 
		temp = _getch();
		if(temp == 13)
		{
			if(iter == 0)
				return 0;
			else
			{
				arr[iter] = '\n';
				break;
			}
		}
		else 
			if(temp == 8)
			{
				if (iter > 0)
				{
					--iter;
					arr[iter] = '\n';
				}
				std::cout << "\x08 \x08";
			}
			else
				if(iter == 5)
				{
					std::cout <<"\nTransaction impossible. Too much value...\nTry again...\n";
					iter = 0;
					continue;
				}
				else
					if((temp < 58) && (temp > 47))
					{
						arr[iter] = temp;
						std::cout << arr[iter];
						++iter;
					}
	}
	std::cout << '\n';
	int sym[] = { '0', '1', '2', '3', '4', '5','6', '7', '8', '9' };
	int val[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; 

	int Result = 0;
	for(int i = 0;( (arr[i] != '\n') ||(arr[i] < 5)) ; ++i)
		for(int j = 0; j < 10; ++j)
		{
			if(arr[0] == 0)
				return 0;
			if(sym[j] == arr[i])
			{
				Result = (Result * 10) + val[j];
			}
		}
	return Result;
}