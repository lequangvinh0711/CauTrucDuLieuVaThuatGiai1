#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
#include <conio.h>

using namespace std;


#include "ThuVien.h"
#include "Menu.h"


void ChayChuongTrinh();

int main()
{
	ChayChuongTrinh();
	return 1;
}

void ChayChuongTrinh()
{
	BTree root = NULL;
	int menu, soMenu = 10;
	do
	{
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, root);
		cout << endl;
		system("PAUSE");
	} while (menu > 0);
}