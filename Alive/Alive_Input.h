#pragma once

#include "../Flower_shop/Base_Input.h"
#include <conio.h>
#include "Alive.h"

class Alive_Input: public Base_Input	//����� ���������� �� ���� ������!!!
{
public:
	Alive_Input(){}
	virtual ~Alive_Input(){}

	Product* InputProduct();
private:
};
