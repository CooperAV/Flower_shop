#include "StdAfx.h"
#include "Product.h"


double Product::GetPrice()
{
	return m_pPrice;
}
unsigned int Product::GetQuantity()
{
	return m_pQuantity;
}
char* Product::GetName()
{
	return m_pName;
}
void Product::SetQuantity(unsigned int Quantity)
{
	m_pQuantity = Quantity;
}
