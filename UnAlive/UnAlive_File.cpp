#include "StdAfx.h"
#include "UnAlive_File.h"
#include "UnAlive_Product.h"
#include <iostream>
#include <vector>

#pragma warning( disable : 4996 )

void UnAlive_File::WriteFile(const std::vector<Product*> &pProd)
{
	Data *dat = new Data[pProd.size()];
	for(unsigned int i = 0; i < pProd.size(); ++i)
	{
		void *temp = pProd[i];
		UnAlive_Product *Temp = (UnAlive_Product*)temp;
		memcpy(dat[i].m_pName, Temp->m_pName, sizeof(Temp->m_pName));
		dat[i].m_pPrice = Temp->m_pPrice;
		dat[i].m_pQuantity = Temp->m_pQuantity;
		dat[i].m_Attributes = Temp->m_Attributes;
		dat[i].m_pWeight = Temp->m_pWeight;
	}
	FILE *pFile = fopen("UnAlive_product.txt", "wb");

	fwrite(dat, sizeof(Data), pProd.size(), pFile);
	delete [] dat;
	fclose(pFile);
}
void UnAlive_File::ReadFile(std::vector<Product*> &pProd)
{
	FILE *pFile = fopen("UnAlive_product.txt", "rb");
	if(pFile == NULL)
	{
		std::cout << "Can't open the file UnAlive_product.txt  ...." << std::endl;
		return;
	}
	fseek(pFile, 0, SEEK_END);
	int size = ftell(pFile);
	int num = size/sizeof(Data);
	rewind(pFile); // возвращаем указатель в начало файла!
	Data *dat = new Data[num];
	fread(dat, sizeof(Data), num, pFile);
	fclose(pFile);
	for(int i=0; i < num; ++i)
	{
		UnAlive_Product *pAl = new UnAlive_Product;
		memcpy(pAl->m_pName, dat[i].m_pName, sizeof(dat[i].m_pName));
		pAl->m_pPrice = dat[i].m_pPrice;
		pAl->m_pQuantity = dat[i].m_pQuantity;
		pAl->m_Attributes = dat[i].m_Attributes;
		pAl->m_pWeight= dat[i].m_pWeight;
		pProd.push_back(pAl);
	}
	delete [] dat;
}
void UnAlive_File::PushBack(const std::vector<Product*> &pProd)
{
	Data *dat = new Data[pProd.size()];
	for(unsigned int i = 0; i < pProd.size(); ++i)
	{
		void *temp = pProd[i];
		UnAlive_Product *Temp = (UnAlive_Product*)temp;
		memcpy(dat[i].m_pName, Temp->m_pName, sizeof(Temp->m_pName));
		dat[i].m_pPrice = Temp->m_pPrice;
		dat[i].m_pQuantity = Temp->m_pQuantity;
		dat[i].m_Attributes = Temp->m_Attributes;
		dat[i].m_pWeight = Temp->m_pWeight;
	}
	FILE *pFile = fopen("Push_Back_UnAlive.txt", "wb");

	fwrite(dat, sizeof(Data), pProd.size(), pFile);
	delete [] dat;
	fclose(pFile);
}
