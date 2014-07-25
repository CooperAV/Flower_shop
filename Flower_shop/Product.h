#pragma once

class Product
{
public:
	Product(){}
	virtual ~Product(){}
protected:
	char m_pName[20];
	double m_pPrice;
	unsigned int m_pQuantity;
	int m_Attributes;
};
