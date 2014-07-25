#pragma once

#include "WorkOut.h"
#include "Category.h"
#include <conio.h>

class Shop		//Класс отвечающий за всю бизнес-логику программы !!!
{
public:
	Shop();
	~Shop();

	void ReadLastFile();
	void Show_Menu();
	void Run();
	void SellProduct();
private:
	double ClientPoket;
	Category* m_pCategory;
	std::vector<Category*> CategoryList;
	WorkOut *m_pWork;
};
