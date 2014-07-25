#pragma once

#include "../Flower_shop/Base_Input.h"
#include <conio.h>
#include "Alive.h"

class Alive_Input: public Base_Input	//Класс отвечающий за ввод данных!!!
{
public:
	Alive_Input(){}
	virtual ~Alive_Input(){}

	Product* InputProduct();
private:
};
