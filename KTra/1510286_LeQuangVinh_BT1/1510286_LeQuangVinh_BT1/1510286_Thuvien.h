//HT menu van hanh cho BT1, BT2
#define MAX 100

//Dinh nghia du lieu- kieu cau truc : hocvien
struct hocvien
{
	char maSV[8];
	char hoSV[10];
	char tenLot[10];
	char ten[10];
	char lop[6];
	int namSinh;
	double dtb;
	int	tichLuy;
};


//=============================================
//Khai bao nguyen mau

int TapTin_MangCT(char* filename, hocvien a[MAX], int& n);
int Chuyen_TapTin_MangCT(char* filename, hocvien a[MAX], int& n);
void Xuat_DSSV(hocvien a[MAX], int n);
void Xuat_SV(hocvien p);
void TieuDe();
void Xuat_MaSV(hocvien a[MAX], int n);
void Tim_TheoLop_TichLuy(char lop[6], int tichluy, hocvien a[MAX], int n);
void Tim_TheoTen(char ten[10], hocvien a[MAX], int n);
void Tim_TheoDTB(double dtb, hocvien a[MAX], int n);
//============================================
//Cai dat cac ham
//=============================================
//Chuyen tap tin cau truc sang mang cau truc
//Thanh cong : tra ve 1; không thanh cong : tra ve 0
int TapTin_MangCT(char* filename, hocvien a[MAX], int& n)
{
	ifstream in(filename);
	if (!in)
		return 0;
	char maSV[8];
	char hoSV[10];
	char tenLot[10];
	char ten[10];
	char lop[6];
	int namSinh;
	double dtb;
	int tichLuy;
	n = 0;
	in >> maSV; strcpy_s(a[n].maSV, maSV);
	in >> hoSV; strcpy_s(a[n].hoSV, hoSV);
	in >> tenLot; strcpy_s(a[n].tenLot, tenLot);
	in >> ten; strcpy_s(a[n].ten, ten);
	in >> lop; strcpy_s(a[n].lop, lop);
	in >> namSinh; a[n].namSinh = namSinh;
	in >> dtb; a[n].dtb = dtb;
	in >> tichLuy; a[n].tichLuy = tichLuy;
	while (!in.eof())
	{
		n++;
		in >> maSV; strcpy_s(a[n].maSV, maSV);
		in >> hoSV; strcpy_s(a[n].hoSV, hoSV);
		in >> tenLot; strcpy_s(a[n].tenLot, tenLot);
		in >> ten; strcpy_s(a[n].ten, ten);
		in >> lop; strcpy_s(a[n].lop, lop);
		in >> namSinh; a[n].namSinh = namSinh;
		in >> dtb; a[n].dtb = dtb;
		in >> tichLuy; a[n].tichLuy = tichLuy;
	}
	n++;
	in.close();
	return 1;
}
int Chuyen_TapTin_MangCT(char* filename, hocvien a[MAX], int& n)
{
	ifstream in(filename);
	if (!in)
	{
		return 0;
	}

	n = 0;
	while (!in.eof())
	{
		in >> a[n].maSV;
		in >> a[n].hoSV;
		in >> a[n].tenLot;
		in >> a[n].ten;
		in >> a[n].lop;
		in >> a[n].namSinh;
		in >> a[n].dtb;
		in >> a[n].tichLuy;
		n++;
	}

	in.close();
	return 1;
}
//Xuat tieu de
void TieuDe()
{
	cout << "\n:=========================================================================:\n";
	cout << setiosflags(ios::left);
	cout << ':'
		<< setw(8) << "MaSV"
		<< ':'
		<< setw(10) << "Ho"
		<< setw(10) << "Tenlot"
		<< setw(10) << "Ten"
		<< ':'
		<< setw(8) << "Lop"
		<< ':'
		<< setw(6) << "NS"
		<< ':'
		<< setw(6) << "DTB"
		<< ':'
		<< setw(10) << "TichLuy"
		<< ':';
	cout << "\n:=========================================================================:";
}
//Xuat 1 s1nh vien
void Xuat_SV(hocvien p)
{

	cout << setiosflags(ios::left)
		<< ':'
		<< setw(8) << p.maSV
		<< ':'
		<< setw(10) << p.hoSV
		<< setw(10) << p.tenLot
		<< setw(10) << p.ten
		<< ':'
		<< setw(8) << p.lop
		<< ':'
		<< setw(6) << p.namSinh
		<< ':'
		<< setw(6) << setprecision(2) << p.dtb << ':'
		<< setw(10) << p.tichLuy
		<< ':';
}
//Xuat danh sach s1nh vien voi thong tin day du
void Xuat_DSSV(hocvien a[MAX], int n)
{
	int i;
	TieuDe();
	for (i = 0; i < n; i++)
	{
		cout << '\n';
		Xuat_SV(a[i]);
	}
	cout << "\n:=========================================================================:\n";
}
//Xuat cac ma sinh vien
void Xuat_MaSV(hocvien a[MAX], int n)
{
	int i;
	cout << setiosflags(ios::left);
	for (i = 0; i < n; i++)
	{
		cout << setw(10) << a[i].maSV;

	}
}

void Tim_TheoTen(char ten[10], hocvien a[MAX], int n)
{
	int i, kq = -1;
	for (i = 0; i < n; i++)
		if (_stricmp(a[i].ten, ten) == 0)
		{
			kq = 1;
			break;
		}
	if (kq == -1)
		cout << "\nDanh sach khong co ten sinh vien : " << ten;
	else
	{
		cout << "\nthong tin sinh vien trong danh sach co ten " << ten;
		cout << endl;
		TieuDe();
		for (i = 0; i < n; i++)
			if (_stricmp(a[i].ten, ten) == 0)
			{
				cout << endl;
				Xuat_SV(a[i]);
			}
	}
}

void Tim_TheoLop_TichLuy(char lop[6], int tichluy, hocvien a[MAX], int n)
{
	int i, kq = -1;
	for (i = 0; i < n; i++)
		if (_stricmp(a[i].lop, lop) == 0)
		{
			kq = 1;
			break;
		}
	if (kq == -1)
		cout << "\nKhong co lop : " << lop;
	else
	{
		for (i = 0; i < n; i++)
			if (a[i].tichLuy> tichluy)
			{
				kq = 1;
				break;
			}
		if (kq == -1)
			cout << "\nKhong co diem tich luy > : " << tichluy;
		else {
			cout << "\nCac hoc vien trong danh sach thuoc lop " << lop << " va tich luy > "<<tichluy<<" :\n";
			cout << endl;
			TieuDe();
			for (i = 0; i < n; i++)
				if (_stricmp(a[i].lop, lop) == 0)
					if(a[i].tichLuy>tichluy)
					{
						cout << endl;
						Xuat_SV(a[i]);
					}
		}
		
	}
}
//void Tim_TheoNamSinh(int namSinh[10], hocvien a[MAX], int n)
//{
//	int i, kq = -1;
//	for (i = 0; i < n; i++)
//		if (_stricmp(a[i].namSinh, namSinh) == 0)
//		{
//			kq = 1;
//			break;
//		}
//	if (kq == -1)
//		cout << "\nDanh sach khong co ten sinh vien : " << namSinh;
//	else
//	{
//		cout << "\nthong tin sinh vien trong danh sach co ten " << namSinh;
//		cout << endl;
//		TieuDe();
//		for (i = 0; i < n; i++)
//			if (_stricmp(a[i].namSinh, namSinh) == 0)
//			{
//				cout << endl;
//				Xuat_SV(a[i]);
//			}
//	}
//}
//Tim theo diem trung binh : xuat sinh vien co diem >= dtb
void Tim_TheoNamSinh_DTB(int namsinh,double dtb, hocvien a[MAX], int n)
{
	int i, kq = -1;
	for (i = 0; i < n; i++)
		if (a[i].namSinh>namsinh) 
		{
			kq = 1;
			break;
		}
	if (kq == -1)
		cout << "\nKhong co nam sinh trung : " << namsinh;
	else
	{
		int i, kq = -1;
		for (i = 0; i < n; i++)
			if (a[i].dtb <= dtb)
			{
				kq = 1;
				break;
			}
		if (kq == -1)
			cout << "\nKhong co sinh vien nao co diem trung binh <= " << dtb;
		else
		{
			cout << "\nCac hoc vien trong danh sach co nam sinh > " << namsinh << " va diem trung binh <= " << dtb << " :\n";
			cout << endl;
			TieuDe();
			for (i = 0; i < n; i++)
				if (a[i].namSinh > namsinh)
					if (a[i].dtb <= dtb)
					{
						cout << endl;
						Xuat_SV(a[i]);
					}
		}
	}
	
}

