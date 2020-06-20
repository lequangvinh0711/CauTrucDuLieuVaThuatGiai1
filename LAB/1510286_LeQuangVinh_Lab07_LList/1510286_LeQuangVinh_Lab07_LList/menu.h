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
	cout << "\n01. Tao du lieu";
	cout << "\n02. Xuat du lieu";
	cout << "\n03. Tim x - Co/Khong";
	cout << "\n04. Tim x - Tra ve vi nut dau tien xuat hien neu co";
	cout << "\n05. Tim x - Tra ve vi nut cuoi cung xuat hien neu co";
	cout << "\n06. Tim x - Xuat cac vi tri xuat hien neu co";
	cout << "\n07. Xuat DS moi, voi Head moi tro toi nut x xuat hien cuoi cung";
	//Chen
	cout << "\n08. Chen x vao dau danh sach";
	cout << "\n09. Chen x vao cuoi danh sach";

	//Huy
	cout << "\n10. Huy nut dau danh sach";
	cout << "\n11. Huy nut cuoi danh sach";
	cout << "\n12. Huy toan bo danh sach";
	cout << "\n13. Dem so nut danh sach vong";
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
		cout << "\n3. Tim x Co/Khong?\n";
		cout << "\nDanh sach ban dau :\n";
		Output_Llist(l);
		cout << "\nNhap x : ";
		cin >> x;
		kq=Search(l, x);
		if (kq == 1)
			cout << endl << x << " co trong danh sach";
		else
			cout << endl << x << " khong co trong danh sach";
		cout << endl;
		break;

	case 4:
		system("CLS");
		cout << "\n04. Tim x - Tra ve vi nut dau tien xuat hien neu co";
		cout << "\nDanh sach ban dau :\n";
		Output_Llist(l);
		cout << "\nNhap x : ";
		cin >> x;
		kq = Search_Pos_First(l, x);
		if (kq == -1)
			cout << endl << x << " khong co trong danh sach";
		else
			cout << endl << x << " xuat hien dau tien trong danh sach tai nut : " << kq;
		cout << endl;
		break;
	case 5:
		system("CLS");
		cout << "\n05. Tim x - Tra ve vi nut cuoi cung xuat hien neu co";
		cout << "\nDanh sach ban dau :\n";
		Output_Llist(l);
		cout << "\nNhap x : ";
		cin >> x;
		kq = Search_Pos_End(l, x);
		if (kq == -1)
			cout << endl << x << " khong co trong danh sach";
		else
			cout << endl << x << " xuat hien cuoi cung trong danh sach tai nut : " << kq;
		cout << endl;
		break;
	case 6:
		system("CLS");
		cout << "\n06. Tim x - Xuat cac vi tri xuat hien neu co";
		cout << "\nDanh sach ban dau :\n";
		Output_Llist(l);
		cout << "\nNhap x : ";
		cin >> x;
		Search_All_Pos_x(l, x);

		cout << endl;
		break;

		//==============================================================
		//Chen
	case 7:
		system("CLS");
		cout << "\n07. Xuat DS moi, voi Head moi tro toi nut x xuat hien cuoi cung";
		Head_New(l, x);
		cout << endl;
		break;

	case 8:
		system("CLS");
		cout << "\n08. Chen x vao dau danh sach";
		cout << "\nDanh sach ban dau :\n";
		Output_Llist(l);
		cout << endl;
		InsertHead(l, x);
		cout << "\nDanh sach da chen " << x << " vao cuoi danh sach:\n";
		Output_Llist(l);
		cout << endl;
		
		break;


	case 9:
		system("CLS");
		cout << "\n08. Chen x vao cuoi danh sach";
		cout << "\nDanh sach ban dau :\n";
		Output_Llist(l);
		cout << endl;
		InsertTail(l, x);
		cout << "\nDanh sach da chen " << x << " vao cuoi danh sach:\n";
		Output_Llist(l);
		cout << endl;
		break;
		

	case 10:
		system("CLS");
		cout << "\n10. Huy nut dau danh sach";
		cout << "\nDanh sach ban dau :\n";
		Output_Llist(l);
		cout << endl;
		RemoveHead(l);
		cout << "\nDanh sach sau khi huy nut dau :\n";
		Output_Llist(l);
		cout << endl;
		break;
		//==============================================================
		//Huy
	case 11:
		system("CLS");
		cout << "\n11. Huy nut cuoi danh sach";
		cout << "\nDanh sach ban dau :\n";
		Output_Llist(l);
		cout << endl;
		
		RemoveTail(l);
		cout << "\nDanh sach sau khi huy nut cuoi :\n";
		Output_Llist(l);
		cout << endl;
		break;
	case 12:

		system("CLS");
		cout << "\n12. Huy toan bo danh sach";
		cout << "\nDanh sach ban dau :\n";
		Output_Llist(l);
		cout << endl;

		RemoveLLIST(l);
		cout << "\nDanh sach sau khi huy toan bo :\n";
		Output_Llist(l);
		cout << endl;
		break;
	case 13:
		system("CLS");
		cout << "\n13. Dem so nut danh sach vong";

		cout << "\nDanh sach ban dau :\n";
		Output_Llist(l);
		cout << endl;

		Copy_Llist(l,l1);
		cout << "\nDem so nut danh sach :\n";
		Output_Llist(l1);
		cout << endl;
		break;//==============================================================
	}
}

