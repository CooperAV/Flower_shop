#include "StdAfx.h"
#include "UnAlive_Output.h"
#include "UnAlive_Product.h"
#include <iostream>
#include <conio.h>

void UnAlive_Output::ShowProduct(const std::vector<Product*> &pProd)
{
	std::cout << "\n\"UnAlive product\"\n";
	unsigned int i;
	for(i=0; i < pProd.size(); ++i)
	{
		void* temp = pProd[i];
		UnAlive_Product* pTemp = (UnAlive_Product*)temp;
		std::cout << "\nName:\t\t" << pTemp->m_pName << std::endl;
		std::cout << "Weight(kg):\t" << pTemp->m_pWeight << std::endl;
		std::cout << "Metal:" << (pTemp->m_Attributes == 0x01?"\t\tyes":"\t\tno") << std::endl;
		std::cout << "Price:\t\t" << pTemp->m_pPrice << std::endl;
		std::cout << "Quantity:\t" << pTemp->m_pQuantity << std::endl;
	}
	_getch();
}
void UnAlive_Output::SellProduct(std::vector<Product*> &pProd, double &ClientPoket)
{
	std::cout << "\nIf you want to continue, push\t\t\"1\"\n";
	std::cout << "Return to the previous menu, push\t\"Any button\"\n";
	int choice;
	choice = _getch();
	if(choice == '1')
	{
		std::cout << "\nOn your balance: " << ClientPoket << std::endl;
		std::cout << "\nWhat product you wish to buy?\n\n";
		for(unsigned int i=0; i < pProd.size(); ++i)
		{
			void* temp = pProd[i];
			UnAlive_Product* pTemp = (UnAlive_Product*)temp;
			std::cout << "\n" << i << "\tName:\t\t" << pTemp->m_pName << std::endl;
			std::cout << "\tWeight(kg):\t" << pTemp->m_pWeight << std::endl;
			std::cout << "\tMetal:" << (pTemp->m_Attributes == 0x01?"\t\tyes":"\t\tno") << std::endl;
			std::cout << "\tPrice:\t\t" << pTemp->m_pPrice << std::endl;
			std::cout << "\tQuantity:\t" << pTemp->m_pQuantity << std::endl;
		}
		std::cout << "\nPlease enter a number of product: ";
		unsigned int a;
		a = GetInputNumber();
		if(a > pProd.size()-1)
		{
			std::cout << "\nSorry we don't have this position ...";
			_getch();
			return;
		}
		void* temp = pProd[a];
		UnAlive_Product* pTemp = (UnAlive_Product*)temp;
		std::cout << "\nName:\t\t" << pTemp->m_pName << std::endl;
		std::cout << "Weight(kg):\t" << pTemp->m_pWeight << std::endl;
		std::cout << "Metal:" << (pTemp->m_Attributes == 0x01?"\t\tyes":"\t\tno") << std::endl;
		std::cout << "Price:\t\t" << pTemp->m_pPrice << std::endl;
		std::cout << "Quantity:\t" << pTemp->m_pQuantity << std::endl;
		std::cout << "\nOn your balance: " << ClientPoket << std::endl;
		std::cout << "\nHow much You want to buy: ";
		a = GetInputNumber();
		if(a < pTemp->m_pQuantity)
		{
			if(ClientPoket > a * pTemp->m_pPrice)
			{
				ClientPoket -=a * pTemp->m_pPrice;
				pTemp->m_pQuantity -= a;
				std::cout << "\nCongratulations, you have just purchased " << a << ' ' << pTemp->m_pName << '.';
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
			std::cout << "Try again later or enter a quantity less than \"" << pTemp->m_pQuantity << "\"!";
		}
	}
	else
	{
		return;
	}
	_getch();
}
void UnAlive_Output::SearchByCriteria(std::vector<Product*> &pProd, double &ClientPoket)
{
	unsigned int j = 0, choice;
	unsigned int ArrayFindProduct[100];
	char TempName[20];
    char currentFlag = 1;
    char searchMask = 0;
	std::cout << "\nPlease enter product \"Name\":\t\t";
	std::cin.getline(TempName, sizeof(TempName));
	if(strlen(TempName) > 0)
	{
        searchMask |= currentFlag;
	}
    currentFlag = currentFlag << 1;
	char TempMetal[10];
	int TempAttributes;
	std::cout << "Are there some \"Metal\" on it? [y/n]:\t";
	std::cin.getline(TempMetal,10);
	if (TempMetal[0] == 'y' || TempMetal[0] == 'Y')
	{
		TempAttributes = 0x01;
	}
	if (TempMetal[0] == 'n' || TempMetal[0] == 'N')
	{
		TempAttributes = 0x00;
	}
	if(strlen(TempMetal) > 0)
	{
        searchMask |= currentFlag;
	}
	for(unsigned int i=0; i < pProd.size(); ++i)
	{
		void* temp = pProd[i];
		UnAlive_Product* pTemp = (UnAlive_Product*)temp;
        //reset currentFlag
        char currentFlag = 1;
        if (searchMask & currentFlag && !strstr(pTemp->m_pName, TempName))
        {
            continue;
        }
        currentFlag = currentFlag << 1;
        if (searchMask & currentFlag && pTemp->m_Attributes != TempAttributes)
        {
            continue;
        }
		std::cout << '\n' << j << "\tName:\t\t" << pTemp->m_pName << std::endl;
		std::cout << "\tWeight(kg):\t" << pTemp->m_pWeight << std::endl;
		std::cout << "\tMetal:" << (pTemp->m_Attributes == 0x01?"\t\tyes":"\t\tno") << std::endl;
		std::cout << "\tPrice:\t\t" << pTemp->m_pPrice << std::endl;
		std::cout << "\tQuantity:\t" << pTemp->m_pQuantity << std::endl;
		ArrayFindProduct[j] = i;
		++j;
	}
	if(j == 0)
		std::cout << "This item is not available...\nTry again ...\n";
	else
	{
		std::cout << "\nIf you want to BUY product, push\t\"1\"\n";
		std::cout << "Return to the previous menu, push\t\"Any button\"\n";
		choice = _getch();
		if(choice == '1')
		{
			std::cout << "\nPlease enter a number of product: ";
			unsigned int a;
			a = GetInputNumber();
			if(a > j-1)
			{
				std::cout << "This item is not available...\nTry again ...\n";
				_getch();
				return;
			}
			void* temp = pProd[ArrayFindProduct[a]];
			UnAlive_Product* pTemp = (UnAlive_Product*)temp;
			std::cout << "\nName:\t\t" << pTemp->m_pName << std::endl;
			std::cout << "Weight(kg):\t" << pTemp->m_pWeight << std::endl;
			std::cout << "Metal:" << (pTemp->m_Attributes == 0x01?"\t\tyes":"\t\tno") << std::endl;
			std::cout << "Price:\t\t" << pTemp->m_pPrice << std::endl;
			std::cout << "Quantity:\t" << pTemp->m_pQuantity << std::endl;
			std::cout << "\nOn your balance: " << ClientPoket << std::endl;
			std::cout << "\nHow much You want to buy: ";
			a = GetInputNumber();
			if(a <= pTemp->m_pQuantity)
			{
				if(ClientPoket > a * pTemp->m_pPrice)
				{
					ClientPoket -=a * pTemp->m_pPrice;
					pTemp->m_pQuantity -= a;
					std::cout << "\nCongratulations, you have just purchased " << a << ' ' << pTemp->m_pName << '.';
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
				std::cout << "Try again later or enter a quantity less than \"" << pTemp->m_pQuantity << "\"!";
			}
		}
		else
		{
			return;
		}
	}
	_getch();
}
void UnAlive_Output::RefillProduct(std::vector<Product*> &pProd)
{
	std::cout << "\nWhat product you wish to refill?\n\n";
	for(unsigned int i=0; i < pProd.size(); ++i)
	{
		void* temp = pProd[i];
		UnAlive_Product* pTemp = (UnAlive_Product*)temp;
		std::cout << "\n" << i << "\tName:\t\t" << pTemp->m_pName << std::endl;
		std::cout << "\tWeight(kg):\t" << pTemp->m_pWeight << std::endl;
		std::cout << "\tMetal:" << (pTemp->m_Attributes == 0x01?"\t\tyes":"\t\tno") << std::endl;
		std::cout << "\tPrice:\t\t" << pTemp->m_pPrice << std::endl;
		std::cout << "\tQuantity:\t" << pTemp->m_pQuantity << std::endl;
	}
	std::cout << "\n\"Please enter a number of product: ";
	unsigned int a;
	a = GetInputNumber();
	if(a > pProd.size()-1)
	{
		std::cout << "\nSorry You don't have this position ...";
		_getch();
		return;
	}
	void* temp = pProd[a];
	UnAlive_Product* pTemp = (UnAlive_Product*)temp;
		std::cout << "\nName:\t\t" << pTemp->m_pName << std::endl;
		std::cout << "Weight(kg):\t" << pTemp->m_pWeight << std::endl;
		std::cout << "Metal:" << (pTemp->m_Attributes == 0x01?"\t\tyes":"\t\tno") << std::endl;
		std::cout << "Price:\t\t" << pTemp->m_pPrice << std::endl;
		std::cout << "Quantity:\t" << pTemp->m_pQuantity << std::endl;
	std::cout << "\nHow much You want to refill: ";
	a = GetInputNumber();
	if(pTemp->m_pQuantity + a < 35000)
	{
		pTemp->m_pQuantity += a;
		std::cout << "\nCongratulations, you have just replenishment " << a << ' ' << pTemp->m_pName << '.';
		std::cout << "\nCurrent balance of product\"" << pTemp->m_pQuantity << "\"!";
	}
	else
	{
		std::cout << "\nSorry, warehouse is full ...\n";
		std::cout << "Try again later or enter a quantity less than \"" << 35000 - pTemp->m_pQuantity << "\"!";
	}
	_getch();
}
