#include "StdAfx.h"
#include "Shop.h"

Shop::Shop()
{
	srand(time(NULL));
	ClientPoket = 200 + rand()%200;
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
		case '2': SellProduct(); break;
		case '3': m_pCategory->OutputProductList(); _getch(); break;
		case '4': m_pCategory->FindCriteria(); break;
		case '5': m_pCategory->RefillProduct(); break;
		case 27: Exit = true; break;
		}
		if(Exit)
			break;
	}
}
void Shop::SellProduct()
{
	std::cout << "\nOn your balance: " << ClientPoket << std::endl;
	std::cout << "\nWhat product you wish to buy?\n\n";
	m_pCategory->OutputProductList(true);
	std::cout << "\nIf you want to continue, push\t\t\"1\"\n";
	std::cout << "Return to the previous menu, push\t\"Any button\"\n";
	int choice;
	choice = _getch();
	if(choice == '1')
	{
		std::cout << "\nPlease enter a number of product: ";
		unsigned int ProductIndex, ClientChoice;
		ProductIndex = GetInputNumber();
		if(ProductIndex >= m_pCategory->GetProductCount())
		{
			std::cout << "\nSorry we don't have this position ...";
			_getch();
			return;
		}
		m_pCategory->OutputProduct(ProductIndex);
		std::cout << "\nHow much You want to buy: ";
		ClientChoice = GetInputNumber();
		std::cout << std::endl;
		if(ClientChoice <= m_pCategory->GetProductQuantityByIndex(ProductIndex))
		{
			if(ClientPoket >= ClientChoice * m_pCategory->GetProductPriceByIndex(ProductIndex))
			{
				ClientPoket -=ClientChoice * m_pCategory->GetProductPriceByIndex(ProductIndex);
				m_pCategory->SetProductQuantityByIndex(ProductIndex, m_pCategory->GetProductQuantityByIndex(ProductIndex) - ClientChoice);
				std::cout << "\nCongratulations, you have just purchased " << ClientChoice << ' ' << m_pCategory->GetProductNameByIndex(ProductIndex) << '.';
				std::cout << "\nYour current balance is \"" << ClientPoket << "\"!";
			}
			else
			{
				std::cout << "\nSorry You don't have enough money to make this purchase ...";
			}
		}
		else
		{
			std::cout << "\nSorry, this quantity of this product is no longer available ...\n";
			std::cout << "Try again later or enter a quantity less than \"" << m_pCategory->GetProductQuantityByIndex(ProductIndex) << "\"!";
		}
	}
	else
		return;
	_getch();
}
