
#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
#include <conio.h>


using namespace std;


#include "1510286_Thuvien.h"
#include "1510286_Menu.h"

void ChayChuongTrinh();

int main()
{
	ChayChuongTrinh();
	return 1;
}

void ChayChuongTrinh()
{
	int soMenu = MAX_MENU,
		menu,
		n = 0;;
	hocvien a[MAX];
	do
	{
		system("CLS");
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, a, n);
		cout << endl;
		system("PAUSE");
	} while (menu > 0);
}