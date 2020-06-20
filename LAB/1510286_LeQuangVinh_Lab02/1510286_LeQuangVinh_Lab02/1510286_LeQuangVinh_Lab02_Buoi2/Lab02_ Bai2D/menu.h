//Khai bao nguyen mau
void XuatMenu();
int ChonMenu(int soMenu);
void XuLyMenu(int menu, sinhvien a[MAX], int& n);
void XuatMenu()
{
	cout << "\n================ He thong chuc nang ===============";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Tao danh sach sinh vien ";
	cout << "\n2. Xem danh sach sinh vien";
	cout << "\n3. Tim kiem theo ma sinh vien";
	cout << "\n4. Tim kiem theo ten-Xuat cac sinh vien cung ten";
	cout << "\n5. Tim kiem theo ho-Xuat cac sinh vien cung ho";
	cout << "\n6. Xuat sinh vien co diem trung binh >= dtb cho truoc";
	cout << "\n7. Tim kiem theo lop-Xuat danh sach sinh vien trong lop";
	cout << "\n8. Tim kiem nhi phan theo tich luy (neu truong tich luy co thu tu)";
}
int ChonMenu(int soMenu)
{
	int stt;
	for (;;)
	{
		system("CLS"); //xoa man hinh
		XuatMenu();
		cout << "\nNhap mot so (0 <= so <= " << soMenu << " ) de chon menu, stt = ";
		cin >> stt;
		if (0 <= stt && stt <= soMenu)
			break;
	}
	return stt;
}
//Hàm Xử lý menu
void XuLyMenu(int menu, sinhvien a[MAX], int& n)
{
	int kq;
	char filename[MAX];
	sinhvien SV;
	switch (menu)
	{
	case 0:
		system("CLS");
		cout << "\n0. Thoat khoi chuong trinh\n";
		break;
	case 1:
		system("CLS");
		cout << "\n1. Tao Danh sach sinh vien.\n";
		do
		{
			cout << "\nNhap ten tap tin, filename = ";
			cin >> filename;
			kq = TapTin_MangCT(filename, a, n);
		} while (!kq);
		cout << "\nDanh sach sinh vien vua nhap:\n";
		Xuat_DSSV(a, n);
		cout << endl;
		break;
	case 2:
		system("CLS");
		cout << "\n2. Xem danh sach sinh vien\n";
		cout << "\nDanh sach sinh vien hien hanh:\n";
		Xuat_DSSV(a, n);
		cout << endl;
		break;
	case 3:
		system("CLS");
		cout << "\n3. Tim kiem theo ma sinh vien";
		cout << "\nNhap ma sinh vien can tim kiem: ";
		cin >> SV.maSV;
		kq = Tim_MaSo_DauTien(SV.maSV, a, n);
		cout << "\nVi tri ma sinh vien nam la:";
		cout << kq<< endl;
		break;
	case 4:
		system("CLS");
		cout << "\n4. Tim kiem theo ten--Xuat cac sinh vien cung ten\n";
		cout << "\nNhap ten sinh vien can tim kiem:";
		cin >> SV.ten;
		Tim_TheoTen(SV.ten, a, n);
		cout  << endl;
		break;
	case 5:
		system("CLS");
		cout << "\n5. Tim kiem theo ho--Xuat cac sinh vien cung ho\n";
		cout << "\nNhap ho sinh vien can tim kiem:";
		cin >> SV.hoSV;
		Tim_TheoHo(SV.hoSV, a, n);
		cout << endl;
		break;
	case 6:
		system("CLS");
		cout << "\n6. Xuat sinh vien co diem trung binh >= dtb cho truoc\n";
		cout << "\nNhap dtb sinh vien can tim kiem:";
		cin >> SV.dtb;
		Tim_TheoDTB(SV.dtb, a, n);
		break;
	case 7:
		system("CLS");
		cout << "\n7. Tim kiem theo lop--Xuat cac sinh vien thuoc lop\n";
		cout << "\nNhap lop sinh vien can tim kiem:";
		cin >> SV.lop;
		Tim_TheoLop(SV.lop, a, n);
		break;
	case 8:
		system("CLS");
		cout << "\n8. Tim kien nhi phan theo tich luy";
		TKNP_Theo_TichLuy(a, n);
		cout << endl; 
		break;
	}
}