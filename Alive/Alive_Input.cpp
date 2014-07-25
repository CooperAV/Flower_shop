#include "StdAfx.h"
#include "Alive_Input.h"
#include "Alive_Product.h"
#include <iostream>
#include <new>

Product* Alive_Input::InputProduct()
{
	Alive_Product* pProd = new Alive_Product();
	std::cout << "\n\"Alive product\"\n";
	std::cout << "\nPlease enter product \"Name\":\t\t";
	std::cin.getline(pProd->m_pName, sizeof(pProd->m_pName));
	std::cout << "Please enter product \"Price\":\t\t";
	pProd->m_pPrice = GetInputNumber();
	std::cout << "Please enter product \"Color\":\t\t";
	std::cin.getline(pProd->m_pColor, sizeof(pProd->m_pColor));
	std::cout << "Please enter product \"Length\":\t\t";
	pProd->m_pLength = GetInputNumber();
	char Spike[5];
	std::cout << "Are there some \"Spikes\" on it? [y/n]:\t";
	std::cin.getline(Spike,10);
	if (Spike[0] == 'y' || Spike[0] == 'Y' )
	{
		pProd->m_Attributes |= ATTR_SPIKES;
	}
	std::cout << "Please enter product \"Quantity\":\t";
	pProd->m_pQuantity = GetInputNumber();
	return pProd;
}
