

#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
#include <conio.h>


using namespace std;


#include "1510286_thuvien.h"
#include "1510286_menu.h"

void ChayChuongTrinh();

int main()
{
	ChayChuongTrinh();
	return 1;
}

void ChayChuongTrinh()
{
	int soMenu = MAX_MENU,
		menu;

	LIST l;
	do
	{
		system("CLS");
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, l);
		cout << endl;
		system("PAUSE");
	} while (menu > 0);
}