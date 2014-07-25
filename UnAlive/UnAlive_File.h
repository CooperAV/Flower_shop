#pragma once
#include "../Flower_shop/Base_File.h"

class UnAlive_File: public Base_File
{
public:
	UnAlive_File(){}
	~UnAlive_File(){}

	void WriteFile(const std::vector<Product*> &pProd);
	void ReadFile(std::vector<Product*> &pProd);
	void PushBack(const std::vector<Product*> &pProd);
private:
	struct Data
	{
		char m_pName[20];
		double m_pPrice;
		int m_pQuantity;
		int m_Attributes;
		double m_pWeight;
	};
};
