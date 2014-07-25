#pragma once

#include "WorkOut.h"
#include "Category.h"
#include <conio.h>

class Shop		//����� ���������� �� ��� ������-������ ��������� !!!
{
public:
	Shop();
	~Shop();

	void ReadLastFile();
	void Show_Menu();
	void GetInputNewProduct();
	void GetOutputProduct();
	void Run();
private:
	Category* m_pCategory;
	std::vector<Category*> CategoryList;
	WorkOut *m_pWork;
};