#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

#include "thuvien.h"
#include "menu.h"

void ChayChuongTrinh();

int main()
{
	ChayChuongTrinh();
	return 0;
}

void ChayChuongTrinh()
{
	int n;
	int soMenu = 8, menu;
	Hocvien a[MAX];
	// Yeu cau nhap danh sach nhan vien dau tien
	char filename[MAX];
	int kq;

	do
	{
		cout << "\nNhap ten tap tin de mo >> ";
		cin >> filename;

		kq = File_Array(filename,a,n);
	} while (kq == 0);

	// Chuong trinh chinh
	do
	{
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, a, n);
	} while (menu > 0);
}

