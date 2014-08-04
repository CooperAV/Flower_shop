#include "StdAfx.h"
#include "Alive_File.h"
#include "Alive_Product.h"
#include <iostream>
#include <vector>

#pragma warning( disable : 4996 )

void Alive_File::WriteFile(const std::vector<Product*> &pProd)
{
	FILE *pFile = NULL;
	Data *dat = NULL;
	try{
		dat = new Data[pProd.size()];
		for(unsigned int i = 0; i < pProd.size(); ++i)
		{
			void *temp = pProd[i];
			Alive_Product *Temp = (Alive_Product*)temp;
			memcpy(dat[i].m_pName, Temp->m_pName, sizeof(Temp->m_pName));
			dat[i].m_pPrice = Temp->m_pPrice;
			dat[i].m_pQuantity = Temp->m_pQuantity;
			dat[i].m_Attributes = Temp->m_Attributes;
			memcpy(dat[i].m_pColor, Temp->m_pColor, sizeof(Temp->m_pColor));
			dat[i].m_pLength = Temp->m_pLength;
		}
		pFile = fopen("Alive_product.txt", "wb");
		if(pFile == NULL)
			std::cout << "Error opening file Alive_product.txt for writing!\n";
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
bool Alive_File::ReadFile(std::vector<Product*> &pProd)
{
	bool Correct = false;
	FILE *pFile = fopen("Alive_product.txt", "rb");
	if(pFile == NULL)
	{
		std::cout << "Can't open the file Alive_product.txt  ...." << std::endl;
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
				Alive_Product *pAl = new Alive_Product;
				memcpy(pAl->m_pName, dat[i].m_pName, sizeof(dat[i].m_pName));
				pAl->m_pPrice = dat[i].m_pPrice;
				pAl->m_pQuantity = dat[i].m_pQuantity;
				pAl->m_Attributes = dat[i].m_Attributes;
				memcpy(pAl->m_pColor, dat[i].m_pColor, sizeof(dat[i].m_pColor));
				pAl->m_pLength = dat[i].m_pLength;
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
void Alive_File::PushBack(const std::vector<Product*> &pProd)
{
	Data *dat = NULL;
	FILE *pFile = NULL;
	try{
		dat = new Data[pProd.size()];
		for(unsigned int i = 0; i < pProd.size(); ++i)
		{
			void *temp = pProd[i];
			Alive_Product *Temp = (Alive_Product*)temp;
			memcpy(dat[i].m_pName, Temp->m_pName, sizeof(Temp->m_pName));
			dat[i].m_pPrice = Temp->m_pPrice;
			dat[i].m_pQuantity = Temp->m_pQuantity;
			dat[i].m_Attributes = Temp->m_Attributes;
			memcpy(dat[i].m_pColor, Temp->m_pColor, sizeof(Temp->m_pColor));
			dat[i].m_pLength = Temp->m_pLength;
		}
		pFile = fopen("Push_Back_Alive.txt", "wb");
		if(pFile == NULL)
			std::cout << "Error opening file Push_Back_Alive.txt for writing!\n";
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
