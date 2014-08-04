#include "stdafx.h"
#include "GetIntroducingNumber.h"

int GetInputNumber()
{
	int iter = 0;
	char arr[6];
	char temp;
	while(true)
	{
		temp = _getch();
		if(temp == 13)
		{
			if(iter == 0)
				return 0;
			else
			{
				arr[iter] = '\n';
				break;
			}
		}
		else
			if(temp == 8)
			{
				if (iter > 0)
				{
					--iter;
					arr[iter] = '\n';
				}
				std::cout << "\x08 \x08";
			}
			else
				if(iter == 5)
				{
					std::cout <<"\nTransaction impossible. Too much value...\nTry again...\n";
					iter = 0;
					continue;
				}
				else
					if((temp < 58) && (temp > 47))
					{
						arr[iter] = temp;
						std::cout << arr[iter];
						++iter;
					}
	}
	std::cout << '\n';
	int sym[] = { '0', '1', '2', '3', '4', '5','6', '7', '8', '9' };
	int val[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	int Result = 0;
	for(int i = 0;( (arr[i] != '\n') ||(arr[i] < 5)) ; ++i)
		for(int j = 0; j < 10; ++j)
		{
			if(arr[0] == 0)
				return 0;
			if(sym[j] == arr[i])
			{
				Result = (Result * 10) + val[j];
			}
		}
	return Result;
}
