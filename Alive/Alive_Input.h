#pragma once

#include "../Flower_shop/Base_Input.h"
#include "../Flower_shop/GetIntroducingNumber.h"
#include <conio.h>

class Alive_Input: public Base_Input	//����� ���������� �� ���� ������!!!
{
public:
	Alive_Input(){}
	virtual ~Alive_Input(){}

	Product* InputProduct();
private:
};
