#include "StdAfx.h"
#include "UnAlive_Input.h"
#include "UnAlive_Product.h"
#include <iostream>

Product* UnAlive_Input::InputProduct()
{
	UnAlive_Product* pProd = new UnAlive_Product();
	std::cout << "\n\"UnAlive product\"\n";
	std::cout << "\nPlease enter product \"Name\":\t\t";
	std::cin.getline(pProd->m_pName, sizeof(pProd->m_pName));
	std::cout << "Please enter product \"Price\":\t\t";
	pProd->m_pPrice = GetInputNumber();
	std::cout << "Please enter product \"Weight(kg)\":\t";
	pProd->m_pWeight = GetInputNumber();
	char Metal[5];
	std::cout << "Are there some \"Metal\" on it? [y/n]:\t";
	std::cin.getline(Metal,10);
	if (Metal[0] == 'y' || Metal[0] == 'Y' )
	{
		pProd->m_Attributes |= ATTR_METAL;
	}
	std::cout << "Please enter product \"Quantity\":\t";
	pProd->m_pQuantity = GetInputNumber();
	return pProd;
}
