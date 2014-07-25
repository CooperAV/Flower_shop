#pragma once

#include "../Flower_shop/Product.h"

enum ALIVE_Attributes
{
	ATTR_SPIKES = 0x01,
};

class Alive_Product: public Product
{
public:
	friend class Alive_Input;
	friend class Alive_File;
	friend class Alive_Output;

	Alive_Product();
	virtual ~Alive_Product(){}
private:
	char m_pColor[20];
	int m_pLength;
};