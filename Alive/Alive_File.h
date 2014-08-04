#pragma once
#include "../Flower_shop/Base_File.h"

class Alive_File: public Base_File
{
public:
	Alive_File(){}
	~Alive_File(){}

	void WriteFile(const std::vector<Product*> &pProd);
	bool ReadFile(std::vector<Product*> &pProd);
	void PushBack(const std::vector<Product*> &pProd);
private:
	struct Data
	{
		char m_pName[20];
		double m_pPrice;
		int m_pQuantity;
		int m_Attributes;
		char m_pColor[20];
		int m_pLength;
	};
};
