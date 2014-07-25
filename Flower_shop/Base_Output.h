#pragma once

#include <vector>
#include "Product.h"

class Base_Output
{
public:
	virtual void ShowProduct(const std::vector<Product*> &pProd)=0;
	virtual void SellProduct(std::vector<Product*> &pProd, double &ClientPoket)=0;
	virtual void SearchByCriteria(std::vector<Product*> &pProd, double &ClientPoket)=0;
	virtual void RefillProduct(std::vector<Product*> &pProd)=0;
private:
};