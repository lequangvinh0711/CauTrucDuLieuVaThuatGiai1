//soan thao he thong menu
void XuatMenu();
int ChonMenu(int soMenu);
void XuLyMenu(int menu, LLIST& l);
//=======================================================

void XuatMenu()
{
	cout << "\n====================== He thong chuc nang =====================";
	cout << "\n0. Thoat khoi chuong trinh";
	//Tim kiem
	cout << "\n1. Tao du lieu";
	cout << "\n2. Xuat du lieu";
	cout << "\n3. Tao so ngau nhien";
	cout << "\n4. Huy nut sau q, q la cuoi";
	cout << "\n5. Dem so nut";
	cout << "\n6. Xuat cac binh si ra khoi vong, binh si chon di cau cuu";
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

void XuLyMenu(int menu, LLIST& l)
{
	char filename[MAX];
	datac x, y;
	NODE* p;
	int kq;
	LLIST l1;
	switch (menu)
	{
	case 0:
		system("CLS");
		cout << "\n0. Thoat khoi chuong trinh\n";
		break;


	case 1:
		system("CLS");
		cout << "\n01. Tao du lieu - Nhap tu tap tin";
		do
		{
			cout << "\nNhap ten tap tin, filename = ";
			_flushall();
			cin >> filename;
			kq = File_LLIST(filename, l);
			if (!kq)
			{
				cout << "\nLoi mo file ! nhap lai\n";
				system("PAUSE");
			}

		} while (!kq);
		cout << "\nDa chuyen thanh cong du lieu tap tin " << filename << " vao lLLIST l.";
		Output_Llist(l);
		cout << endl;
		break;

	case 2:
		system("CLS");
		cout << "\n02. Xem du lieu :\n";

		Output_Llist(l);
		cout << endl;
		break;


	case 3:
		system("CLS");
		cout << "\n3. Tao so ngau nhien";
		cout << "\nDanh sach ban dau :\n";
		Output_Llist(l);
		cout << "\nSo ngau nhien : ";
		TaoSoNgauNhien();
		

	case 4:
		system("CLS");
		cout << "\n04. Huy nut sau q, q la cuoi";
		cout << "\nDanh sach ban dau :\n";
		Output_Llist(l);
		//Remove_Node_After_q(l,p);
		break;
	case 5:
		system("CLS");
		cout << "\n05. Dem so nut";
		cout << "\nDanh sach ban dau :\n";
		Output_Llist(l);
		cout << "\nso nut la : ";
		SoNut(l);
		cout << endl;
		break;
	case 6:
		system("CLS");
		cout << "\n06. Xuat cac binh si ra khoi vong, binh si chon di cau cuu";
		cout << "\nDanh sach ban dau :\n";
		Output_Llist(l);
		CryForHelp(l);

		cout << endl;
		break;

		//==============================================================
		//Chen
	}
}

