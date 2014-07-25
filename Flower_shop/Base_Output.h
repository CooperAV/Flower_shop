#pragma once

#include <vector>
#include "Product.h"

class Base_Output
{
public:
	virtual void ShowProductList(const std::vector<Product*> &pProd, bool ShowNumbers = false)=0;
	virtual void ShowProduct(Product * pProd)=0;
	virtual void SearchByCriteria(std::vector<Product*> &pProd)=0;
	virtual void RefillProduct(std::vector<Product*> &pProd)=0;
private:
};
