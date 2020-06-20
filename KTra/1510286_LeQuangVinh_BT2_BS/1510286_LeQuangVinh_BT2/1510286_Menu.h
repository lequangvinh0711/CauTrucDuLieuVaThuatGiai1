//he thong menu

void XuatMenu();
int ChonMenu(int soMenu);
void XuLyMenu(int menu, hocvien a[MAX], int& n);

//=======================================================

void XuatMenu()
{
	cout << "\n================ HT menu =================";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Tao danh sach tu tap tin";
	cout << "\n2. Xem danh sach";

	//Cac chuc nang 3,4,5 se thay doi tuong ung voi BT2_BS
	cout << "\n3. Sap danh sach hoc vien tang dan theo diem trung binh bang thuat giai chon truc tiep";
	cout << "\n4. Danh sach hoc vien sau khi tang dan theo so tin chi bang thuat giai Buble ";
	cout << "\n5. Sap danh sach hoc vien tang dan theo nam sinh bang thuat giai HeapSort";
	cout << "\n==========================================";
}

int ChonMenu(int soMenu)
{
	int stt;
	for (;;)
	{
		system("CLS"); //xoa man hinh
		XuatMenu();
		cout << "\nNhap mot so ( 0 <= so <= " << soMenu << " ) de chon menu, stt = ";
		cin >> stt;
		if (0 <= stt && stt <= soMenu)
			break;
	}
	return stt;
}


void XuLyMenu(int menu, hocvien a[MAX], int& n)
{
	char filename[MAX] = "HocVien.txt";
	switch (menu)
	{
	case 0:
		system("CLS");
		cout << "\n0. Thoat khoi chuong trinh\n";
		break;
	case 1:
		system("CLS");
		cout << "\n1. Tao danh sach tu tap tin";

		if (!Chuyen_TapTin_MangCT(filename, a, n))
			cout << "\nMo tap tin " << filename << " bi loi!\n";
		else
			cout << "\nDa chuyen thanh cong du lieu tap tin " << filename << " vao danh sach :\n";

		break;
	case 2:
		system("CLS");
		cout << "\n2. Xem danh sach";
		cout << "\nDanh sach hoc vien:\n";
		Xuat_DSSV(a, n);
		cout << endl;
		break;


	case 3:
		system("CLS");
		cout << "\n3. Sap danh sach hoc vien tang dan theo diem trung binh bang thuat giai chon truc tiep";
		Xuat_DSSV(a, n);
		cout << "\nDanh sach hoc vien sau khi tang dan theo diem trung binh khi chon truc tiep \n";
		selectionSort(a, n);
		Xuat_DSSV(a, n);
		cout << endl;
		break;

	case 4:
		system("CLS");
		cout << "\n4. Sap danh sach hoc vien tang dan theo so tin chi bang thuat giai Buble";
		Xuat_DSSV(a, n);
		cout << "\nDanh sach hoc vien sau khi tang dan theo so tin chi bang thuat giai Buble \n";
		Buble_L(a, n);
		Xuat_DSSV(a, n);
		cout << endl;
		break;

	case 5:
		system("CLS");
		cout << "\n5. Sap danh sach hoc vien tang dan theo nam sinh bang thuat giai HeapSort";
		Xuat_DSSV(a, n);
		cout << "\nDanh sach hoc vien sau khi tang dan theo nam sinh bang thuat giai HeapSort \n";
		HeapSort(a, n);
		Xuat_DSSV(a, n);
		cout << endl;
		break;

	}
}





