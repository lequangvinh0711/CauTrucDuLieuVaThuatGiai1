
void XuatMenu();
int ChonMenu(int soMenu);
void XuLyMenu(int menu, LIST& l);

//=======================================================

void XuatMenu()
{
	cout << "\n================ HT menu =================";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Tao danh sach tu tap tin";
	cout << "\n2. Xem danh sach";
	cout << "\n3. Sua so tin chi tich luy trong bang diem cua hoc vien co ma DL23452 thanh 35";
	cout << "\n4. Xuat danh sach hoc vien tung lop trong bang diem";
	cout << "\n5. Xoa cac hoc vien co nam sinh 1994 ra khoi bang diem mon hoc";
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


void XuLyMenu(int menu, LIST& l)
{
	char filename[60] = "HocVien.txt";
	static int dau = 0;
	hocvien x;
	//int kq;
	NODE* p;
	switch (menu)
	{
	case 0:
		system("CLS");
		cout << "\n0. Thoat khoi chuong trinh\n";
		break;
	case 1:
		system("CLS");
		cout << "\n1. Tao danh sach tu tap tin";
		if (!Chuyen_TapTin_List(filename, l))
			cout << "\nMo tap tin " << filename << " bi loi!\n";
		else
		{
			cout << "\nDa chuyen thanh cong du lieu tap tin " << filename << " vao danh sach l:\n";
			dau = 1;
		}
		break;
	case 2:
		system("CLS");
		if (dau == 0)
		{
			cout << "\nChon 1 truoc de tao du lieu!";
			break;
		}
		cout << "\n2. Xem danh sach";
		cout << "\nDanh sach hoc vien :\n";
		Xuat_DSHV(l);
		cout << endl;
		break;
	case 3:
		system("CLS");
		cout << "\n3. Sua so tin chi tich luy trong bang diem cua hoc vien co ma DL23452 thanh 35";
		cout << "\nDanh sach ban dau :\n";
		Xuat_DSHV(l);
		p = SuaTichLuy_Hocvien(l);
		if (p != NULL)
		{
			cout << endl << "Sua tin chi tich luy  thanh cong hoc vien co ma DL23452 thanh 35  " << endl;
			TieuDe();
			cout << endl;
			Xuat_HV(p->info);
		}		
		else
			cout << endl  << " Sua that bai";
		cout << endl;
		break;
		
		
	case 4:
		system("CLS");
		cout << "\n4. Xuat danh sach hoc vien tung lop trong bang diem";
		cout << "\nDanh sach ban dau :\n";
		Xuat_DSHV(l);
		cout << "\nNhap x : ";
		cin >> x.lop;
		XuatDsHocVien_TheoLop(l, x);
		cout << endl;
		break;
	case 5:
		system("CLS");
		cout << "\n5. Xoa cac hoc vien co nam sinh 1994 ra khoi bang diem mon hoc";
		Xuat_DSHV(l);
		cout << endl;
		cout << "\nDanh sach co " << SoNut(l) << " phan tu.\n";
		cout << "\nNhap x = ";
		cin >> x.namSinh;
		if (!RemoveNode_First(l, x))
		{
			cout << "\nKhong co " << x.namSinh << " trong danh sach, danh sach khong doi\n";
		}
		else
		{
			XoaNamSinh_HocVien(l, x);
			cout << "\nDanh sach sau khi huy hoc vien co " << x.namSinh << ":\n";
			Xuat_DSHV(l);
			cout << endl;
			cout << "\nDanh sach moi co " << SoNut(l) << " phan tu.\n";
		}
		break;
	}

}



