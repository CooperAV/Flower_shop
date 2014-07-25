#include "StdAfx.h"
#include "WorkOut.h"

char WorkOut::Show_Menu(int nchoice)
{
	char choice;
	while(true)
	{
		switch(nchoice)
		{
		case 1:
			system("CLS");
			std::cout << "If you want to SET product, push\t\"1\"\n";
			std::cout << "If you want to SHOW product, push\t\"3\"\n";
			std::cout << "If you want to REFILL product, push\t\"5\"\n";
			std::cout << "Return to previous menu, push\t\t\"Esc\"\n";
			choice = _getch();
			switch(choice)
			{
			case '1':
			case '3':
			case '5':
			case 27: return choice; break;
			default: std::cout << "<Miss klick> ...\nTry again ...\n";
					 _getch();
					 break;
			}
		break;
			case 2:
			system("CLS");
			std::cout << "If you want to BUY product, push\t\"2\"\n";
			std::cout << "If you want to SHOW product, push\t\"3\"\n";
			std::cout << "If you want to FIND product, push\t\"4\"\n";
			std::cout << "Return to previous menu, push\t\t\"Esc\"\n";
			choice = _getch();
			switch(choice)
			{
			case '2':
			case '3':
			case '4':
			case 27: return choice; break;
			default: std::cout << "<Miss click> ...\nTry again ...\n";
					 _getch();
					 break;
				break;
			}
		}
	}
	return choice;
}