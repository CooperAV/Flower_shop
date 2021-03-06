#include "StdAfx.h"
#include "Alive_Output.h"
#include "Alive_Product.h"
#include <iostream>
#include <conio.h>
#include <string>

void Alive_Output::ShowProductList(const std::vector<Product*> &pProd, bool ShowNumbers)
{
	std::cout << "\n\"Alive product\"\n";
	for(unsigned int i=0; i < pProd.size(); ++i)
	{
		std::cout << '\n';
		if(ShowNumbers)
		{
			std::cout << i;
		}
		this->ShowProduct(pProd[i]);
	}
}
void Alive_Output::ShowProduct(Product * pProd)
{
	void* temp = pProd;
	Alive_Product* pTemp = (Alive_Product*)temp;
	std::cout << "\tName:\t\t" << pTemp->m_pName << std::endl;
	std::cout << "\tLength:\t\t" << pTemp->m_pLength << std::endl;
	std::cout << "\tSpikes:" << (pTemp->m_Attributes == 0x01?"\t\tyes":"\t\tno") << std::endl;
	std::cout << "\tColor:\t\t" << pTemp->m_pColor << std::endl;
	std::cout << "\tPrice:\t\t" << pTemp->m_pPrice << std::endl;
	std::cout << "\tQuantity:\t" << pTemp->m_pQuantity << std::endl;
}
void Alive_Output::SearchByCriteria(std::vector<Product*> &pProd)
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
	char TempColor[20];
	std::cout << "Please enter product \"Color\":\t\t";
	std::cin.getline(TempColor, sizeof(TempColor));
	if(strlen(TempColor) > 0)
	{
        searchMask |= currentFlag;
	}
    currentFlag = currentFlag << 1;
	char TempSpike[10];
	int TempAttributes;
	std::cout << "Are there some \"Spikes\" on it? [y/n]:\t";
	std::cin.getline(TempSpike,10);
	if (TempSpike[0] == 'y' || TempSpike[0] == 'Y')
	{
		TempAttributes = 0x01;
	}
	if (TempSpike[0] == 'n' || TempSpike[0] == 'N')
	{
		TempAttributes = 0x00;
	}
	if(strlen(TempSpike) > 0)
	{
        searchMask |= currentFlag;
	}
	for(unsigned int i=0; i < pProd.size(); ++i)
	{
		void* temp = pProd[i];
		Alive_Product* pTemp = (Alive_Product*)temp;
        //reset currentFlag
        char currentFlag = 1;
        if (searchMask & currentFlag && !strstr(pTemp->m_pName, TempName))
        {
            continue;
        }
        currentFlag = currentFlag << 1;
        if (searchMask & currentFlag && !strstr(pTemp->m_pColor, TempColor))
        {
            continue;
        }
        currentFlag = currentFlag << 1;
        if (searchMask & currentFlag && pTemp->m_Attributes != TempAttributes)
        {
            continue;
        }
        std::cout << '\n' << j << "\tName:\t\t" << pTemp->m_pName << std::endl;
        std::cout << "\tLength:\t\t" << pTemp->m_pLength << std::endl;
        std::cout << "\tSpikes:" << (pTemp->m_Attributes == 0x01?"\t\tyes":"\t\tno") << std::endl;
        std::cout << "\tColor:\t\t" << pTemp->m_pColor << std::endl;
        std::cout << "\tPrice:\t\t" << pTemp->m_pPrice << std::endl;
        std::cout << "\tQuantity:\t" << pTemp->m_pQuantity << std::endl;
        ArrayFindProduct[j] = i;
        ++j;
	}
	if(j == 0)
		std::cout << "This item is not available...\nTry again ...\n";
	_getch();
}
void Alive_Output::RefillProduct(std::vector<Product*> &pProd)
{
	std::cout << "\nWhat product you wish to refill?\n\n";
	for(unsigned int i=0; i < pProd.size(); ++i)
	{
		void* temp = pProd[i];
		Alive_Product* pTemp = (Alive_Product*)temp;
		std::cout << "\n" << i << "\tName:\t\t" << pTemp->m_pName << std::endl;
		std::cout << "\tLength:\t\t" << pTemp->m_pLength << std::endl;
		std::cout << "\tSpikes:" << (pTemp->m_Attributes == 0x01?"\t\tyes":"\t\tno") << std::endl;
		std::cout << "\tColor:\t\t" << pTemp->m_pColor << std::endl;
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
	Alive_Product* pTemp = (Alive_Product*)temp;
	std::cout << "\nName:\t\t" << pTemp->m_pName << std::endl;
	std::cout << "Length:\t\t" << pTemp->m_pLength << std::endl;
	std::cout << "Spikes:" << (pTemp->m_Attributes == 0x01?"\t\tyes":"\t\tno") << std::endl;
	std::cout << "Color:\t\t" << pTemp->m_pColor << std::endl;
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
