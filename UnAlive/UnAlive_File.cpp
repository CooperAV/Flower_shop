#include "StdAfx.h"
#include "UnAlive_File.h"
#include "UnAlive_Product.h"
#include <iostream>
#include <vector>

#pragma warning( disable : 4996 )

void UnAlive_File::WriteFile(const std::vector<Product*> &pProd)
{
	FILE *pFile = NULL;
	Data *dat = NULL;
	try{
		dat = new Data[pProd.size()];
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
		if(pFile == NULL)
			std::cout << "Error opening file UnAlive_product.txt for writing!\n";
		else
			fwrite(dat, sizeof(Data), pProd.size(), pFile);
	}
	catch(...)
	{
		if(pFile)
			fclose(pFile);
		std::cout << "Error writing the file!\n";
	}
	if(dat)
		delete [] dat;
}
bool UnAlive_File::ReadFile(std::vector<Product*> &pProd)
{
	bool Correct = false;
	FILE *pFile = fopen("UnAlive_product.txt", "rb");
	if(pFile == NULL)
	{
		std::cout << "Can't open the file UnAlive_product.txt  ...." << std::endl;
	}
	else
	{
		Data *dat = NULL;
		try{
			fseek(pFile, 0, SEEK_END);
			int size = ftell(pFile);
			int num = size/sizeof(Data);
			rewind(pFile); // возвращаем указатель в начало файла!
			dat = new Data[num];
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
			Correct = true;
		}
		catch(...)
		{
			std::cout << "Error reading the file!\n";
		}
		if(dat)
			delete [] dat;
	}
	return Correct;
}
void UnAlive_File::PushBack(const std::vector<Product*> &pProd)
{
	Data *dat = NULL;
	FILE *pFile = NULL;
	try{
		dat = new Data[pProd.size()];
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
		pFile = fopen("Push_Back_UnAlive.txt", "wb");
		if(pFile == NULL)
			std::cout << "Error opening file Push_Back_UnAlive.txt for writing!\n";
		else
		{
			fwrite(dat, sizeof(Data), pProd.size(), pFile);
			fclose(pFile);
		}
	}
	catch(...)
	{
		std::cout << "Error backup the file!\n";
	}
	if(dat)
		delete [] dat;
}
