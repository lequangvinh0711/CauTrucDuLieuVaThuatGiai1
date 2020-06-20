
void XuatMenu();
int ChonMenu(int soMenu);
void XuLyMenu(int menu, hocvien a[MAX], int& n);

//=======================================================

void XuatMenu()
{
	cout << "\n================ HT menu =================";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Tao danh sach tu tap tin hoc vien";
	cout << "\n2. Xem danh sach hoc vien";
	cout << "\n3. Tim kiem theo lop va so tin chi";
	cout << "\n4. Tim kiem theo ten ";
	cout << "\n5. Tim kiem theo nam sinh va diem trung binh";
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
	int kq;
	char filename[MAX];
	hocvien HV;
	switch (menu)
	{
	case 0:
		system("CLS");
		cout << "\n0. Thoat khoi chuong trinh\n";
		break;
	case 1:
		system("CLS");
		cout << "\n1. Tao danh sach tu tap tin hoc vien";

		do
		{   //Doan trinh nay dung khi muon nhap ten tap tin tu ban phim
			system("CLS");
			cout << "\nNhap ten tap tin du lieu muon mo : Filename = ";
			cin.ignore();
			cin >> filename;
			if (!TapTin_MangCT(filename, a, n))
			{
				cout << "\nLoi mo file ! Nhap lai ten tap tin : \n";
				system("PAUSE");
			}
			else
			{
				cout << "\nDa chuyen thanh cong du lieu tap tin " << filename << " vao danh sach:\n";
				break;
			}
		} while (1);
		//Nen dung doan trinh sau do dung bo du lieu nay
		/*if (!Chuyen_TapTin_MangCT(filename, a, n))
			cout << "\nMo tap tin " << filename << " bi loi!\n";
		else
			cout << "\nDa chuyen thanh cong du lieu tap tin " << filename << " vao danh sach :\n";*/

		break;
	case 2:
		system("CLS");
		cout << "\n2. Xem danh sach hoc vien";
		cout << "\nDanh sach sinh vien voi thong tin day du:\n";
		Xuat_DSSV(a, n);
		cout << endl;
		cout << "\nDanh sach cac ma sinh vien :\n";
		Xuat_MaSV(a, n);
		cout << endl;
		break;


	case 3:
		system("CLS");
		cout << "\n3. Tim kiem theo lop va so tin chi.";
		cout << "\nNhap lop can tim kiem:";
		cin >> HV.lop;
		cout << "\nNhap so tin chi can tim kiem:";
		cin >> HV.tichLuy;
		Tim_TheoLop_TichLuy(HV.lop, HV.tichLuy, a, n);
		break;

	case 4:
		system("CLS");
		cout << "\n4. Tim kiem theo ten ";
		cout << "\nNhap ten hoc vien can tim kiem:";
		cin >> HV.ten;
		Tim_TheoTen(HV.ten, a, n);
		break;


	case 5:
		system("CLS");
		cout << "\n5. Tim kiem theo nam sinh va diem trung binh";
		cout << "\nNhap nam sinh hoc vien can tim kiem:";
		cin >> HV.namSinh;
		cout << "\nNhap diem trung binh  can tim kiem:";
		cin >> HV.dtb;
		Tim_TheoNamSinh_DTB(HV.namSinh, HV.dtb, a, n);
		break;


	}
}


