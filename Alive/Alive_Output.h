#pragma once
#include "../Flower_shop/Base_Output.h"
#include "../Flower_shop/GetIntroducingNumber.h"
#include <vector>
#include <conio.h>

class Alive_Output: public Base_Output	//Класс отвечающий за вывод данных!!!
{
public:
	Alive_Output(){}
	virtual ~Alive_Output(){}

	void ShowProductList(const std::vector<Product*> &pProd, bool ShowNumbers = false);
	void ShowProduct(Product * pProd);
	void SearchByCriteria(std::vector<Product*> &pProd);
	void RefillProduct(std::vector<Product*> &pProd);
private:
};
