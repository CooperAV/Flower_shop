#pragma once

#include <iostream>
#include <vector>
#include "Product.h"

class Base_File
{
public:
	virtual void WriteFile(const std::vector<Product*> &pProd)=0;
	virtual bool ReadFile(std::vector<Product*> &pProd)=0;
	virtual void PushBack(const std::vector<Product*> &pProd)=0;
private:
};
