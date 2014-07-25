#pragma once
#include "../Flower_shop/Base_Output.h"
#include <vector>
#include <conio.h>
#include "UnAlive.h"

class UnAlive_Output: public Base_Output	//Класс отвечающий за вывод данных!!!
{
public:
	UnAlive_Output(){}
	virtual ~UnAlive_Output(){}
	
	void ShowProduct(const std::vector<Product*> &pProd);
	void SellProduct(std::vector<Product*> &pProd, double &ClientPoket);
	void SearchByCriteria(std::vector<Product*> &pProd, double &ClientPoket);
	void RefillProduct(std::vector<Product*> &pProd);
private:
};