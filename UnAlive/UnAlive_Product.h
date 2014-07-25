#pragma once

#include "../Flower_shop/Product.h"

enum ALIVE_Attributes
{
	ATTR_METAL = 0x01,
};

class UnAlive_Product: public Product
{
public:
	friend class UnAlive_Input;
	friend class UnAlive_File;
	friend class UnAlive_Output;

	UnAlive_Product();
	virtual ~UnAlive_Product(){}
private:
	double m_pWeight;
};
