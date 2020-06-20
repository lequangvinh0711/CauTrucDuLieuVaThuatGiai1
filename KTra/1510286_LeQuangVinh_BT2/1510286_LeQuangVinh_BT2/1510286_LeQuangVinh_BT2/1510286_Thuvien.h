#define MAX 100
#define MAX_MENU 5

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
int Chuyen_TapTin_MangCT(char* filename, hocvien a[MAX], int& n);
void Xuat_DSSV(hocvien a[MAX], int n);
void Xuat_SV(hocvien p);
void TieuDe();
void HoanVi(hocvien& x, hocvien& y);
void Copy(hocvien b[MAX], hocvien a[MAX], int n);
//===========================================
void Insertion_R(hocvien a[MAX], int n);
void Interchange_R(hocvien a[MAX], int n);
void Partition(hocvien a[MAX], int l, int r);
void QuickSort(hocvien a[MAX], int n);

//============================================
//Cai dat cac ham
//=============================================
//Chuyen tap tin cau truc sang mang cau truc
//Thanh cong : tra ve 1; không thanh cong : tra ve 0
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
void Selection_R(hocvien a[MAX], int n)
{
	int i, j, cs_max;
	for (i = 0; i < n - 1; i++)
	{
		cs_max = n - 1 - i;
		for (j = n - 2 - i; j >= 0; j--)
			if (a[j].maSV > a[cs_max].maSV)
				cs_max = j;
		HoanVi(a[n - 1 - i], a[cs_max]);
	}
}
//===========================================
void HoanVi(hocvien& x, hocvien& y)
{
	hocvien t;
	t = x;
	x = y;
	y = t;
}
void Copy(hocvien b[MAX], hocvien a[MAX], int n)
{
	for (int i = 0; i < n; i++)
		b[i] = a[i];
}
// chen truc tiep
void Insertion_R(hocvien a[MAX], int n)
{
	int i, pos;
	hocvien x;
	for (i = n - 2; i >= 0; i--)
	{
		x = a[i];
		for (pos = i + 1; (pos < n) && (strcmp(a[pos].maSV,x.maSV)<0) ; pos++)
			a[pos - 1] = a[pos];
		a[pos - 1] = x;
	}
}
// doi cho truc tiep
void Interchange_R(hocvien a[MAX], int n)
{
	int i, j;
	for (j = n - 1; j > 0; j--)
	{
		for (i = 0; i < j; i++)
			if (strcmp(a[i].maSV , a[j].maSV)>0)
				HoanVi(a[i], a[j]);
	}
}
void Partition(hocvien a[MAX], int l, int r)
{
	int i, j;
	hocvien x;
	x = a[(l + r) / 2];
	i = l; j = r;
	do
	{
		while (strcmp(a[i].maSV,x.maSV)<0)
			i++;
		while (strcmp(a[j].maSV,x.maSV)>0)
			j--;
		if (i <= j)
		{
			HoanVi(a[i], a[j]);
			i++; j--;
		}
	} while (i <= j);
	if (l < j)
		Partition(a, l, j);
	if (i < r)
		Partition(a, i, r);
}
//Quick sort
void QuickSort(hocvien a[MAX], int n)
{
	Partition(a, 0, n - 1);
}





