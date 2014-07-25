#pragma once

class Product
{
public:
	Product(){}
	virtual ~Product(){}

	double GetPrice();
	unsigned int GetQuantity();
	char* GetName();
	void SetQuantity(unsigned int Quantity);
protected:
	char m_pName[20];
	double m_pPrice;
	unsigned int m_pQuantity;
	int m_Attributes;
};
