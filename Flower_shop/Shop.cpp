#include "StdAfx.h"
#include "Shop.h"

Shop::Shop()
{
	Get_Library_Func GetLibraryName;
	Get_PushBack_Func GetPushBackName;
	WIN32_FIND_DATA FindFileData;
	LPWSTR pCharLibrary = NULL;
	std::vector<std::wstring> LibList;
	HANDLE hFile = FindFirstFile(L"*.dll", &FindFileData);
	if(hFile == INVALID_HANDLE_VALUE)
	{
		std::cout << "Sorry none of the files are not found!!!\n"; _getch();
		return;
	}
	else
	{
		do
		{
			std::wstring LibName(FindFileData.cFileName);
			LibList.push_back(LibName);
		}
		while (FindNextFile(hFile,&FindFileData));
	}
	for(unsigned int i = 0; i < LibList.size(); ++i)
	{
			pCharLibrary = const_cast<wchar_t*> (LibList[i].c_str());
			m_pCategory = new Category(pCharLibrary);
			if(m_pCategory->IsComplete())
			{
				CategoryList.push_back(m_pCategory);
			}
			else
				delete m_pCategory;
	}
}
Shop::~Shop()
{
	unsigned int CategorySize = CategoryList.size();
	for(unsigned int i=0; i<CategorySize; ++i)
	{
		CategoryList[i]->SaveFile();
		delete CategoryList[i];
	}
}

void Shop::Run()
{
	while(true)
	{
		system("CLS");
		std::cout << "Select library to work with:\n\n";
		for(unsigned int i = 0; i < CategoryList.size(); ++i)
		{
			std::cout << "\t" << i+1 << ". ";
			std::wcout << CategoryList[i]->GetLibraryName() << std::endl;
		}
		std::cout << "\t0. Exit\n";
		unsigned int a;
		std::cout << "\nYour choice: ";
		a = GetInputNumber();
		if(a > CategoryList.size())
		{
			std::cout << "<Miss click> ...\nTry again ...\n"; _getch();
			continue;
		}
		if(!a)
			break;
		m_pCategory = CategoryList[a-1];
		Show_Menu();
	}
}
void Shop::ReadLastFile()
{
	m_pCategory->LoadFile();
}
void Shop::Show_Menu()
{
	int nchoice = m_pCategory->GetRandEvents();
	bool Exit = false;
	while(!Exit)
	{
		char choice = m_pWork->Show_Menu(nchoice);

		switch(choice)
		{
		case '1': m_pCategory->InputNewProduct();
				  m_pCategory->Push_Back();
				  break;
		case '2': m_pCategory->Sell_Product(); break;
		case '3': m_pCategory->OutputProduct(); break;
		case '4': m_pCategory->FindCriteria(); break;
		case '5': m_pCategory->RefillProduct(); break;
		case 27: Exit = true; break;
		}
		if(Exit)
			break;
	}
}
void Shop::GetInputNewProduct()
{
	m_pCategory->InputNewProduct();
}
void Shop::GetOutputProduct()
{
	m_pCategory->OutputProduct();
}
