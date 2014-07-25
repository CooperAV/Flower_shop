#pragma once

#include "../Flower_shop/Base_Input.h"
#include <conio.h>
#include "UnAlive.h"

class UnAlive_Input: public Base_Input	//Класс отвечающий за ввод данных!!!
{
public:
	UnAlive_Input(){}
	virtual ~UnAlive_Input(){}

	Product* InputProduct();
private:
};
