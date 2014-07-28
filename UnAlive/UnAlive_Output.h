#pragma once
#include "../Flower_shop/Base_Output.h"
#include <vector>
#include <conio.h>
#include "../Flower_shop/GetIntroducingNumber.h"

class UnAlive_Output: public Base_Output	//Класс отвечающий за вывод данных!!!
{
public:
	UnAlive_Output(){}
	virtual ~UnAlive_Output(){}

	void ShowProductList(const std::vector<Product*> &pProd, bool ShowNumbers = false);
	void ShowProduct(Product * pProd);
	void SearchByCriteria(std::vector<Product*> &pProd);
	void RefillProduct(std::vector<Product*> &pProd);
private:
};
